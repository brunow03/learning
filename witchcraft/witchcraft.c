/* simple_kernel.c - A minimal kernel with functional style */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* ============ TYPE DEFINITIONS ============ */
typedef uint32_t pid_t;
typedef uint32_t message_t;
typedef uint32_t reg_t;

typedef enum {
    PROC_READY,
    PROC_RUNNING,
    PROC_BLOCKED,
    PROC_TERMINATED
} proc_state_t;

typedef struct {
    pid_t pid;
    proc_state_t state;
    reg_t regs[16];  /* CPU registers */
    void* stack_ptr;
    uint32_t priority;
} pcb_t;

typedef struct {
    pid_t from;
    pid_t to;
    message_t msg;
} ipc_msg_t;

typedef struct {
    pcb_t* processes[32];
    uint32_t proc_count;
    pid_t current_pid;
    ipc_msg_t ipc_queue[64];
    uint32_t ipc_count;
} kernel_state_t;

/* ============ PURE FUNCTIONS ============ */
/* Create new PCB (pure - no side effects) */
pcb_t* pcb_create(pid_t pid, uint32_t priority) {
    static pcb_t pcb;
    pcb.pid = pid;
    pcb.state = PROC_READY;
    pcb.priority = priority;
    memset(pcb.regs, 0, sizeof(pcb.regs));
    pcb.stack_ptr = NULL;
    return &pcb;
}

/* Update process state (pure - returns new state) */
kernel_state_t state_set_process_state(kernel_state_t state, pid_t pid, proc_state_t new_state) {
    for (uint32_t i = 0; i < state.proc_count; i++) {
        if (state.processes[i]->pid == pid) {
            /* Create modified copy */
            kernel_state_t new_state_copy = state;
            pcb_t* new_pcb = malloc(sizeof(pcb_t));
            if (new_pcb) {
                memcpy(new_pcb, state.processes[i], sizeof(pcb_t));
                new_pcb->state = new_state;
                new_state_copy.processes[i] = new_pcb;
            }
            return new_state_copy;
        }
    }
    return state;
}

/* ============ FUNCTIONAL SCHEDULER ============ */
/* Round-robin scheduler (functional style) */
kernel_state_t schedule(kernel_state_t state) {
    kernel_state_t new_state = state;
    
    if (state.proc_count == 0) {
        new_state.current_pid = 0;
        return new_state;
    }
    
    /* Find next ready process */
    for (uint32_t i = 0; i < state.proc_count; i++) {
        pid_t next_pid = (state.current_pid + i + 1) % (state.proc_count + 1);
        
        for (uint32_t j = 0; j < state.proc_count; j++) {
            if (state.processes[j]->pid == next_pid && 
                state.processes[j]->state == PROC_READY) {
                
                /* Mark current process as ready */
                if (state.current_pid != 0) {
                    new_state = state_set_process_state(new_state, state.current_pid, PROC_READY);
                }
                
                /* Mark new process as running */
                new_state = state_set_process_state(new_state, next_pid, PROC_RUNNING);
                new_state.current_pid = next_pid;
                return new_state;
            }
        }
    }
    
    return new_state;
}

/* ============ IPC MESSAGING ============ */
/* Send message (pure function) */
kernel_state_t ipc_send(kernel_state_t state, pid_t from, pid_t to, message_t msg) {
    kernel_state_t new_state = state;
    
    if (new_state.ipc_count < 64) {
        ipc_msg_t new_msg = {from, to, msg};
        new_state.ipc_queue[new_state.ipc_count] = new_msg;
        new_state.ipc_count++;
    }
    
    return new_state;
}

/* Deliver messages (pure function) */
kernel_state_t ipc_deliver(kernel_state_t state) {
    kernel_state_t new_state = state;
    uint32_t delivered = 0;
    
    for (uint32_t i = 0; i < state.ipc_count; i++) {
        ipc_msg_t msg = state.ipc_queue[i];
        
        /* Find recipient process */
        for (uint32_t j = 0; j < state.proc_count; j++) {
            if (state.processes[j]->pid == msg.to) {
                /* In a real kernel, we'd add to process mailbox */
                printf("Message delivered: %u -> %u: 0x%x\n", 
                       msg.from, msg.to, msg.msg);
                
                /* Mark message as delivered by not copying it */
                delivered++;
                break;
            }
        }
    }
    
    /* Compact undelivered messages */
    uint32_t idx = 0;
    for (uint32_t i = 0; i < state.ipc_count; i++) {
        bool delivered_flag = false;
        for (uint32_t j = 0; j < delivered; j++) {
            if (i == j) { /* Simplified - real kernel would track better */
                delivered_flag = true;
                break;
            }
        }
        if (!delivered_flag && idx < 64) {
            new_state.ipc_queue[idx++] = state.ipc_queue[i];
        }
    }
    
    new_state.ipc_count = idx;
    return new_state;
}

/* ============ FUNCTIONAL KERNEL OPERATIONS ============ */
/* Process creation (fork-like) */
kernel_state_t proc_create(kernel_state_t state, pid_t parent_pid) {
    kernel_state_t new_state = state;
    
    if (new_state.proc_count < 32) {
        pid_t new_pid = new_state.proc_count + 1;
        
        /* Find parent to copy */
        pcb_t* parent = NULL;
        for (uint32_t i = 0; i < state.proc_count; i++) {
            if (state.processes[i]->pid == parent_pid) {
                parent = state.processes[i];
                break;
            }
        }
        
        if (parent) {
            pcb_t* child = malloc(sizeof(pcb_t));
            if (child) {
                memcpy(child, parent, sizeof(pcb_t));
                child->pid = new_pid;
                child->state = PROC_READY;
                
                new_state.processes[new_state.proc_count] = child;
                new_state.proc_count++;
            }
        }
    }
    
    return new_state;
}

/* ============ KERNEL FUNCTION COMPOSITION ============ */
typedef kernel_state_t (*kernel_func_t)(kernel_state_t);

/* Compose two kernel functions */
kernel_func_t compose(kernel_func_t f, kernel_func_t g) {
    return [](kernel_state_t s) -> kernel_state_t {
        return g(f(s));
    };
}

/* Execute a chain of kernel operations */
kernel_state_t kernel_pipeline(kernel_state_t state, kernel_func_t ops[], size_t count) {
    kernel_state_t result = state;
    for (size_t i = 0; i < count; i++) {
        result = ops[i](result);
    }
    return result;
}

/* ============ INTERRUPTS AND TRAPS ============ */
typedef struct {
    uint32_t trap_num;
    pid_t pid;
    reg_t regs[16];
} trap_frame_t;

/* Handle system call (pure function) */
kernel_state_t syscall_handler(kernel_state_t state, trap_frame_t trap) {
    kernel_state_t new_state = state;
    
    switch (trap.trap_num) {
        case 1: /* SYS_FORK */
            new_state = proc_create(new_state, trap.pid);
            break;
            
        case 2: /* SYS_SEND */
            if (trap.regs[0] && trap.regs[1]) {
                new_state = ipc_send(new_state, trap.pid, 
                                    (pid_t)trap.regs[0], 
                                    (message_t)trap.regs[1]);
            }
            break;
            
        case 3: /* SYS_YIELD */
            new_state = schedule(new_state);
            break;
    }
    
    return new_state;
}

/* ============ MEMORY MANAGEMENT ============ */
typedef struct {
    void* base;
    size_t size;
    bool allocated;
} mem_block_t;

typedef struct {
    mem_block_t blocks[256];
    uint32_t block_count;
} mem_state_t;

/* Pure memory allocator */
mem_state_t mem_alloc(mem_state_t mem, size_t size) {
    mem_state_t new_mem = mem;
    
    for (uint32_t i = 0; i < mem.block_count; i++) {
        if (!mem.blocks[i].allocated && mem.blocks[i].size >= size) {
            new_mem.blocks[i].allocated = true;
            
            /* Split block if larger than needed */
            if (new_mem.blocks[i].size > size) {
                if (new_mem.block_count < 256) {
                    new_mem.blocks[new_mem.block_count].base = 
                        (void*)((char*)new_mem.blocks[i].base + size);
                    new_mem.blocks[new_mem.block_count].size = 
                        new_mem.blocks[i].size - size;
                    new_mem.blocks[new_mem.block_count].allocated = false;
                    new_mem.block_count++;
                    
                    new_mem.blocks[i].size = size;
                }
            }
            return new_mem;
        }
    }
    
    return new_mem;
}

/* ============ KERNEL INITIALIZATION ============ */
kernel_state_t kernel_init() {
    kernel_state_t state = {0};
    
    /* Create init process */
    pcb_t* init_proc = malloc(sizeof(pcb_t));
    if (init_proc) {
        init_proc->pid = 1;
        init_proc->state = PROC_RUNNING;
        init_proc->priority = 1;
        memset(init_proc->regs, 0, sizeof(init_proc->regs));
        init_proc->stack_ptr = NULL;
        
        state.processes[0] = init_proc;
        state.proc_count = 1;
        state.current_pid = 1;
    }
    
    return state;
}

/* ============ KERNEL MAIN LOOP ============ */
void kernel_loop(kernel_state_t state, int iterations) {
    kernel_state_t current_state = state;
    
    for (int i = 0; i < iterations; i++) {
        printf("\n=== Kernel Tick %d ===\n", i);
        printf("Current PID: %u\n", current_state.current_pid);
        printf("Process count: %u\n", current_state.proc_count);
        
        /* Define operations pipeline */
        kernel_func_t ops[] = {
            schedule,
            ipc_deliver
        };
        
        /* Execute pipeline */
        current_state = kernel_pipeline(current_state, ops, 2);
        
        /* Simulate some system calls */
        if (i % 3 == 0) {
            trap_frame_t trap = {2, 1, {2, 0xDEADBEEF}};
            current_state = syscall_handler(current_state, trap);
        }
        
        if (i == 2) {
            trap_frame_t trap = {1, 1, {0}};
            current_state = syscall_handler(current_state, trap);
        }
    }
}

/* ============ MAIN ============ */
int main() {
    printf("=== Simple Functional Kernel ===\n");
    
    /* Initialize kernel */
    kernel_state_t state = kernel_init();
    
    /* Run kernel loop */
    kernel_loop(state, 10);
    
    /* Cleanup */
    for (uint32_t i = 0; i < state.proc_count; i++) {
        free(state.processes[i]);
    }
    
    printf("\n=== Kernel Shutdown ===\n");
    return 0;
}