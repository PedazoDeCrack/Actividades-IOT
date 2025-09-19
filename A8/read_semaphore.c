#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <fcntl.h>
#include <semaphore.h>
#include "common.h"

int main() {
    char *buff;
    int shm_id = shmget(SHM_KEY, 0, 0);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    buff = shmat(shm_id, NULL, 0);
    if (buff == (char*)-1) {
        perror("shmat failed");
        exit(1);
    }

    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }

    while (1) {
        // Esperar notificación del writer
        sem_wait(sem);

        printf("Reader recibe: %s", buff);
    }

    shmdt(buff);
    sem_close(sem);

    return 0;
}
