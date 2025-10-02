/*
Write a program that demonstrates the use of nice () system call. After a child process 
is started using fork (), assign higher priority to the child using nice () system call.
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
  int pid,retnice,i;
  pid=fork();
  if(pid==0){
    retnice=nice(-5);
    printf("Child gets higher CPU priority. Nice Value - (%d)\n",retnice);
    for(i=0;i<5;i++){
      printf("Child process executing...\n");
      sleep(1);
    }
  }else if(pid>0){
    retnice=nice(5);
    printf("Parent gets lower CPU priority. Nice Value - (%d)\n",retnice);
    for(i=0;i<5;i++){
      printf("Parent process executing...\n");
      sleep(1);
    }
  }else{
    printf("Fork failed"); 
  }
  return 0;
}