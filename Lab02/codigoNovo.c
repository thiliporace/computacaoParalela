#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  int num = 10,i;
  int pip[2];
  if (pipe(pip) == -1){
    printf("Error when trying to open a pipe\n");
    return 0;
  }
  pid_t childid = fork();
  if (childid == -1){
    printf("Error in fork function\n");
    exit(EXIT_FAILURE);
  }
  if (childid == 0){
    close(pip[0]);
    int child = 1;
    for (i = 1;i <= num/2;i++){
      child = child*i;
    }
    write(pip[1],&child,sizeof(int));
    close(pip[1]);
  }
  else {
    close(pip[1]);
    int result;
    read(pip[0],&result,sizeof(int));
    for (i = (num/2)+1;i <= num;i++){
      result = result*i;
    }
    close(pip[0]);
    wait(NULL);
    printf("The factorial of %d is: %d\n",num,result);
  }
  return 0;
}
