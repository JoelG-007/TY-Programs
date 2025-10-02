/*
Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It 
accepts the command, tokenize the command line and execute it by creating the child process. 
Also implement the additional command ‘list’ as: 
myshell$ list f dirname: It will display filenames in a given directory. 
myshell$ list n dirname: It will count the number of entries in a given directory. 
myshell$ list i dirname: It will display filenames and their inode number for the files in a given 
directory. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>
#include<dirent.h>

char **parsetoken(char **tok){
  int i=0;
  char *temp=strtok(tok," \n");
  char **tokens=malloc(10*sizeof(char *));
  while(temp!=NULL){
    tokens[i++]=temp;
    temp=strtok(NULL," \n");
  }
  tokens[i]=NULL;
  return tokens;
}

int list(char mode, char *dirname){
  DIR *dir=opendir(dirname);
  struct dirent *entry;
  struct stat fileStat;
  int count=0;
  char fullpath[512];

  if(!dir){
    perror("Cannot open directory");
  }
  while((entry=readdir(dir))!=NULL){
    sprintf(fullpath,"%s/%s",dirname,entry->d_name);
    stat(fullpath,&fileStat);

    if(entry->d_type==DT_REG || entry->d_type==DT_DIR){
      count++;
      if(mode=='f'){
	printf("%s\n",entry->d_name);
      }else if(mode=='i'){
	  printf("%s-Inode: %ld\n",entry->d_name,entry->d_ino);
      }
    }
    if(mode=='n'){
      printf("Total entries: %d\n",count);
    }
  }
  closedir(dir);
}

int main(){
  char buffr[80];
  char **tokens;
  int pid;

  while(1){
    printf("myshell$ ");
    fflush(stdout);
    fgets(buffr,sizeof(buffr),stdin);

    tokens=parsetoken(buffr);
    if(tokens[0]==NULL)continue;
    if(strcmp(tokens[0],"q")==0)break;
    pid=fork();

    if(pid==0){
       if(strcmp(tokens[0],"list")==0){
	if(tokens[1]==NULL || tokens[2]==NULL){
	  printf("Usage: list <f|n|i> <filename>\n");
	  exit(1);
	}
	list(tokens[1][0],tokens[2]);
      }else{
	execvp(tokens[0], tokens);
	perror("Command not found");
      }
      exit(0);
    }else{
      wait(NULL);
    }
    free(tokens);
  }
  return 0;
}