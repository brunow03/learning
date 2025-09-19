#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void copy(void) {
    char in_pathname[BUFFER_SIZE], out_pathname[BUFFER_SIZE];
    int fd_in, fd_out;

    // Prompt source
    const char prompt_src[] = "Enter source file:\n";
    write(STDERR_FILENO, prompt_src, sizeof(prompt_src));

    // Accept input
    ssize_t len = read(STDERR_FILENO, in_pathname, BUFFER_SIZE);
    if (len > 0 && in_pathname[len - 1] == '\n') {
        in_pathname[len - 1] = '\0';  // Replace newline with null terminator
    } else {
        in_pathname[len] = '\0';  // Null terminate the string
    }
    
    // Prompt destination
    const char prompt_dest[] = "Enter destination file:\n";
    write(STDERR_FILENO, prompt_dest, sizeof(prompt_dest));

    // Accept input
    len = read(STDERR_FILENO, out_pathname, BUFFER_SIZE);
    if (len > 0 && out_pathname[len - 1] == '\n') {
        out_pathname[len - 1] = '\0';  // Replace newline with null terminator
    } else {
        out_pathname[len] = '\0';  // Null terminate the string
    }

    // Open input file
    fd_in = open(in_pathname, O_RDONLY);
    if (fd_in < 0) { // If input file open fails, abort
        return;
    }

    // Create output file
    fd_out = open(out_pathname, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd_out < 0) // If fails, abort
    {
        return;
    }

    char c[1];
    while (read(fd_in, c, 1) != 0)
    {
        write(fd_out, c, 1);
    }
    
    close(fd_in);
    close(fd_out);
    
    const char finish_msg[] = "Copy complete!\n";
    write(STDERR_FILENO, finish_msg, sizeof(finish_msg));
}

int main(char argc, char *argv) {
    copy();
    return 0;
}