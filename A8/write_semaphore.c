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
    int shm_id = shmget(SHM_KEY, MAX_LEN, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    buff = shmat(shm_id, NULL, 0);
    if (buff == (char*)-1) {
        perror("shmat failed");
        exit(1);
    }

    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }

    while (1) {
        printf("Escribe un mensaje: ");
        if (fgets(buff, MAX_LEN, stdin) == NULL) break;

        // Notificar al reader que hay datos nuevos
        sem_post(sem);
    }

    shmdt(buff);
    sem_close(sem);
    sem_unlink(SEM_NAME);

    return 0;
}
