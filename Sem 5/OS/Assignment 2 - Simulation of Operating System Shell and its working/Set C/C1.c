/*
Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It 
accepts the command, tokenize the command line and execute it by creating the child process. 
Also implement the additional command ‘typeline’ as: 
myshell$ typeline n filename: It will display first n lines of the file.  
myshell$ typeline -n filename: It will display last n lines of the file.  
myshell$ typeline a filename: It will display all the lines of the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **parsetoken(char *tok){
    int i = 0;
    char *temp = strtok(tok, " \n");
    char **tokens = malloc(10 * sizeof(char *));
    while (temp != NULL){
        tokens[i++] = temp;
        temp = strtok(NULL, " \n");
    }
    tokens[i] = NULL;
    return tokens;
}

int typeline(char *mode, char *filename){
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        perror("Error opening file");
        return 1;
    }

    char line[256];
    int count = 0, total = 0;

    while (fgets(line, sizeof(line), fp)) total++;     // count total lines
    rewind(fp);

    if(strcmp(mode, "a") == 0){   // all lines
        while (fgets(line, sizeof(line), fp)) printf("%s", line);
    }else if (mode[0] == '-'){    // last n lines
        int n = atoi(mode + 1);
        int start = total - n;
        if (start < 0) start = 0;
        int i = 0;
        while (fgets(line, sizeof(line), fp)){
            if (i >= start) printf("%s", line);
            i++;
        }
    }else{  // first n lines
        int n = atoi(mode);
        while (fgets(line, sizeof(line), fp) && count < n){
            printf("%s", line);
            count++;
        }
    }
    fclose(fp);
    return 0;
}

int main(){
    char buffr[80];
    char **tokens;
    int pid;

    while(1){
        printf("myshell$ ");
        fflush(stdout);
        if(!fgets(buffr, sizeof(buffr), stdin)) break;

        tokens = parsetoken(buffr);
        if(tokens[0] == NULL) { free(tokens); continue;}
        if(strcmp(tokens[0], "q") == 0) break;

        pid = fork();
        if(pid == 0) {  // child
            if(strcmp(tokens[0], "typeline") == 0){
                if(tokens[1] == NULL || tokens[2] == NULL){
                    printf("Usage: typeline <n|-n|a> <filename>\n");
                    exit(1);
                }
                typeline(tokens[1], tokens[2]);
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
