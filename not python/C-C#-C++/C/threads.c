#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ULLONG_MAX 18446744073709551615ULL
#define NUM_THREADS 4

unsigned long long int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg) {
    unsigned long long int local_count = 0;

    for (unsigned long long int i = 0; i < ULLONG_MAX / NUM_THREADS; i++) {
        local_count++;
    }

    // Bloquear o acesso à variável global count para evitar condições de corrida
    pthread_mutex_lock(&mutex);
    count += local_count;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Criar threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    // Aguardar threads terminarem
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Soma em um único núcleo: %llu\n", count);

    // Reinicializar count para a próxima etapa
    count = 0;

    // Criar threads para utilizar todos os núcleos
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    // Aguardar threads terminarem
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Soma em todos os quatro núcleos: %llu\n", count);

    return 0;
}

