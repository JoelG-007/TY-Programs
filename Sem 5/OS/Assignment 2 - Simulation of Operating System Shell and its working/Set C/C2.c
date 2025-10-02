/*
Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It 
accepts the command, tokenize the command line and execute it by creating the child process.Also 
implement the additional command ‘search’ as: 
myshell$ search f filename pattern: It will search the first occurrence of pattern in the given file. 
myshell$ search a filename pattern: It will search all the occurrence of pattern in the given file. 
myshell$ search c filename pattern: It will count the number of occurrence of pattern in the given file.
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
    while(temp != NULL){
        tokens[i++] = temp;
        temp = strtok(NULL, " \n");
    }
    tokens[i] = NULL;
    return tokens;
}

int search(char *mode, char *filename, char *pattern){
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        perror("Error opening file");
        return 1;
    }

    char line[256];
    int lineNo = 0, found = 0, count = 0;

    while(fgets(line, sizeof(line), fp)){
        lineNo++;
        if(strstr(line, pattern)){
            found = 1;
            count++;
            if(strcmp(mode, "f") == 0){  // first occurrence
                printf("Found at line %d: %s", lineNo, line);
                break;
            }else if(strcmp(mode, "a") == 0){  // all occurrences
                printf("Found at line %d: %s", lineNo, line);
            }
        }
    }
    if(strcmp(mode, "c") == 0){
        printf("Total occurrences of '%s' = %d\n", pattern, count);
    }
    if(!found && strcmp(mode, "f") == 0)
        printf("Pattern not found\n");

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
        if(tokens[0] == NULL) { free(tokens); continue; }
        if(strcmp(tokens[0], "q") == 0) break;

        pid = fork();
        if(pid == 0){  // child
            if(strcmp(tokens[0], "search") == 0){
                if(tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL){
                    printf("Usage: search <f|a|c> <filename> <pattern>\n");
                    exit(1);
                }
                search(tokens[1], tokens[2], tokens[3]);
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