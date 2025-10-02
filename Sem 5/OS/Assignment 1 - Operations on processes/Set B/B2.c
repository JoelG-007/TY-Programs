/*
Write a C program to illustrate the concept of orphan process. Parent process creates 
a child and terminates before child has finished its task. So child process becomes 
orphan process. (Use fork (), sleep (), getpid (), getppid ()). 
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
  pid_t pid;
  pid=fork();
  if(pid==0){
    sleep(3);
    printf("Child process. PID - (%d), PPID - (%d)\n",getpid(),getppid());
  }else{
    printf("Parent process terminating... PID - %d\n",getpid());
    exit(0);
 }
  return 0;
}