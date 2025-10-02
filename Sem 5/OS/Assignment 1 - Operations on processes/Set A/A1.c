/* 
Implement the C Program to create a child process using fork (), display parent and 
child process id. Child process will display the message “I am Child Process” and 
the parent process should display “I am Parent Process”.
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
  pid_t pid;
  pid=fork();

  if(pid<0){
    printf("Fork failed\n");
  }else if(pid==0){
    printf("I am Child Process. PID - %d\n",getpid());
  }else{
    printf("I am Parent Process. PID - %d\nChild Process PID - %d\n",getpid(),pid);
  }
  return 0;
}