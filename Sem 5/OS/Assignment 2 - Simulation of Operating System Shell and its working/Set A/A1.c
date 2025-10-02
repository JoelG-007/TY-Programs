/*
Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It 
accepts the command, tokenize the command line and execute it by creating the child process. 
Also implement the additional command ‘count’ as: 
myshell$ count c filename: It will display the number of characters in given file 
myshell$ count w filename: It will display the number of words in given file 
myshell$ count l filename: It will display the number of lines in given file
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>
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

int count(char *filename, char mode){
  FILE *fp=fopen(filename,"r");
  if(fp==NULL){
    perror("Error opening file.");
    return 1;
  }
 
  int lines=0, words=0, chars=0;
  char ch, prev= ' ';

  while((ch=fgetc(fp))!=EOF){
    chars++;
    if(ch=='\n')lines++;
    if((ch==' ' || ch=='\n' || ch=='\t')&&(prev!=' ' && prev!='\n' && prev!='\t'))words++;
    prev=ch;
  }
  fclose(fp);

  if(mode=='c')printf("Characters - %d\n",chars);
  else if(mode=='w')printf("Words - %d\n",words);
  else if(mode=='l')printf("Lines - %d\n",lines);
  else printf("Invalid mode\n");

  return 0;
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
      if(strcmp(tokens[0],"count")==0){
	if(tokens[1]==NULL || tokens[2]==NULL){
	  printf("Usage: count <c|w|l> <filename>\n");
	  exit(1);
	}
	count(tokens[2],tokens[1][0]);
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
