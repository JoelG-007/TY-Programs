/*
Implement the C Program to create a child process using fork (), Using exec () system 
call, child process will execute the program specified in Set A (1) and parent will 
continue by printing message “I am parent “. 
*/

//C2_parent.c
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
  pid_t pid = fork();
  if(pid==0){
    execlp("Q2_child_code.c","Q2_child_code.c",NULL);
    perror("execl failed");
  }else{
    printf("I am parent\n");
  }
  return 0;
}

