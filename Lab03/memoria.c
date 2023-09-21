#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

#define IPC_RESULT_ERROR (-1)
#define BLOCK_SIZE 1024
#define FILE_NAME "main.c"

int main(int argc, char *argv[]) {
  int *shmptr;
  int shmblockid = shmget(IPC_PRIVATE,BLOCK_SIZE,IPC_CREAT | 0666);
  if (shmblockid < 0){
    printf("Error when creating a sharedblock id\n");
    exit(EXIT_FAILURE);
  }
  shmptr = (int *) shmat(shmblockid, NULL, 0);
  if (shmptr == (int *)IPC_RESULT_ERROR){
    printf("Error when creating a ptr for the shared memory block\n");
    exit(EXIT_FAILURE);
  }
  shmptr[0] = atoi(argv[1]); 
  printf("Number associated with the variable num: %d\n",shmptr[0]);
  pid_t childid = fork();
  if (childid == -1){
    printf("Error in fork function\n");
    exit(EXIT_FAILURE);
  }
  if (childid == 0){
    shmptr[0] = shmptr[0] + 3;
    printf("Number after child operations: %d\n",shmptr[0]);
  }
  else {
    wait(NULL);
    shmptr[0] = shmptr[0] * 3;
    printf("Number after parent operations: %d\n",shmptr[0]);
  }
  return 0;
}
