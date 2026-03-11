#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{ char name[10]; int size, start, end; } dir[100];
int bit_vector[100], mem_size, free_blocks, count=0;

void init(){
    printf("Memory blocks: "); scanf("%d", &mem_size);
    for(int i=0; i<mem_size; i++) bit_vector[i]=-1;
    free_blocks=mem_size;
}

void show_bit_vector(){
    for(int i=0; i<mem_size; i++) printf("Block %d -> %d\n", i, bit_vector[i]);
    printf("Free: %d\n", free_blocks);
}

void create(){
    char name[10]; int size;
    printf("Filename: "); scanf("%s", name);
    printf("Size: ");     scanf("%d", &size);
    if(size > free_blocks){ printf("Not enough memory\n"); return; }
    int start=-1, prev=-1, placed=0;
    while(placed<size){
        int b=rand() % mem_size;
        if(bit_vector[b] == -1){
            if(start == -1) start=b;
            else bit_vector[prev]=b;
            prev=b; placed++;
        }
    }
    bit_vector[prev]=-9;
    strcpy(dir[count].name, name);
    dir[count].size=size; dir[count].start=start; dir[count].end=prev;
    count++; free_blocks -= size; printf("File created\n");
}

void delete(){
    char name[10]; printf("Filename to delete: "); scanf("%s", name);
    for(int i=0; i<count; i++){
        if(!strcmp(dir[i].name, name)){
            int cur=dir[i].start, tmp;
            while(cur != -9){ tmp=cur; cur=bit_vector[tmp]; bit_vector[tmp]=-1; free_blocks++; }
            for(int j=i; j<count - 1; j++) dir[j]=dir[j+1];
            count--; printf("Deleted\n"); return;
        }
    }
    printf("Not found\n");
}

void display(){
    printf("\nName\tSize\tStart\tEnd\n");
    for(int i=0; i<count; i++)
        printf("%s\t%d\t%d\t%d\n", dir[i].name, dir[i].size, dir[i].start, dir[i].end);
}

int main(){
    int ch; init();
    while(1){
        printf("\n1.Memory 2.Create 3.Display 4.Delete 5.Exit\nChoice: ");
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