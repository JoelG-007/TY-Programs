#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{ char name[10]; int size, start; } dir[100];
int bit_vector[100], mem_size, count=0;

void init(){
    printf("Memory blocks: "); scanf("%d", &mem_size);
    for(int i=0; i<mem_size; i++) bit_vector[i]=1;
}

void show_bit_vector(){
    printf("Bit Vector: ");
    for(int i=0; i<mem_size; i++) printf("%d ", bit_vector[i]);
    printf("\n");
}

int find_space(int size){
    for(int i=0; i <= mem_size - size; i++){
        int j;
        for(j=0; j<size; j++) if(!bit_vector[i+j]) break;
        if(j == size) return i;
    }
    return -1;
}

void create(){
    char name[10]; int size;
    printf("Filename: "); scanf("%s", name);
    printf("Size: ");     scanf("%d", &size);
    int start=find_space(size);
    if(start == -1){ printf("Not enough space\n"); return; }
    for(int i=start; i<start + size; i++) bit_vector[i]=0;
    strcpy(dir[count].name, name);
    dir[count].size=size; dir[count].start=start; count++;
    printf("File created\n");
}

void delete(){
    char name[10]; printf("Filename to delete: "); scanf("%s", name);
    for(int i=0; i<count; i++){
        if(!strcmp(dir[i].name, name)){
            for(int j=dir[i].start; j<dir[i].start + dir[i].size; j++) bit_vector[j]=1;
            for(int j=i; j<count - 1; j++) dir[j]=dir[j+1];
            count--; printf("Deleted\n"); return;
        }
    }
    printf("Not found\n");
}

void display(){
    printf("\nName\tStart\tSize\n");
    for(int i=0; i<count; i++)
        printf("%s\t%d\t%d\n", dir[i].name, dir[i].start, dir[i].size);
}

int main(){
    int ch; init();
    while(1){
        printf("\n1.Bit Vector 2.Create 3.Display 4.Delete 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: show_bit_vector();  break;
            case 2: create();   break;
            case 3: display();  break;
            case 4: delete();   break;
            case 5: exit(0);
        }
    }
}