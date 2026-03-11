#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{ char name[20]; int size, index_block; }FileDetail;

int bit_vector[MAX];          // 0=free, 1=used
int idx[MAX][MAX];    // index block contents
FileDetail dir[MAX];
int mem_size, free_mem, count=0;

void init(){
    printf("Memory size: "); scanf("%d", &mem_size);
    for(int i=0; i<mem_size; i++) bit_vector[i]=0;
    free_mem=mem_size;
}

void show_bit_vector(){
    for(int i=0; i<mem_size; i++) printf("Block %d: %d\n", i, bit_vector[i]);
}

int find_block(){
    while(1){ int b=rand() % mem_size; if(!bit_vector[b]) return b; }
}

void create(){
    char name[20]; int size;
    printf("Filename: "); scanf("%s", name);
    printf("Size: ");     scanf("%d", &size);
    if(size + 1 > free_mem){ printf("Not enough memory\n"); return; }
    int ib=find_block(); bit_vector[ib]=1; free_mem--;
    for(int i=0; i<size; i++){
        int b=find_block(); bit_vector[b]=1; idx[ib][i]=b; free_mem--;
    }
    strcpy(dir[count].name, name);
    dir[count].size=size; dir[count].index_block=ib; count++;
    printf("File created\n");
}

void delete(){
    char name[20]; printf("Filename to delete: "); scanf("%s", name);
    for(int i=0; i<count; i++){
        if(!strcmp(dir[i].name, name)){
            int ib=dir[i].index_block;
            for(int j=0; j<dir[i].size; j++){ bit_vector[idx[ib][j]]=0; free_mem++; }
            bit_vector[ib]=0; free_mem++;
            for(int j=i; j<count - 1; j++) dir[j]=dir[j+1];
            count--; printf("Deleted\n"); return;
        }
    }
    printf("Not found\n");
}

void display(){
    printf("\nIndex\tSize\tName\tBlocks\n");
    for(int i=0; i<count; i++){
        int ib=dir[i].index_block;
        printf("%d\t%d\t%s\t", ib, dir[i].size, dir[i].name);
        for(int j=0; j<dir[i].size; j++) printf("%d ", idx[ib][j]);
        printf("\n");
    }
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
