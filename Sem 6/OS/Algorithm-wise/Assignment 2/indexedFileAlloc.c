#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[10];
    int index,size;
} dir[10];

int used[50], index_block[50][50];
int n,count=0;

void init() {
    int i,j;
    printf("Enter number of blocks: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        used[i]=0;
        for(j=0;j<n;j++) index_block[i][j]=-1;
    }
}

void create_file() {
    char name[10];
    int size,i,idx,blk;
    printf("Enter file name: ");
    scanf("%s",name);
    printf("Enter file size: ");
    scanf("%d",&size);

    for(idx=0;idx<n;idx++)
        if(!used[idx]) break;
    if(idx==n) {
        printf("No index block\n");
        return;
    }

    used[idx]=1;
    strcpy(dir[count].name,name);
    dir[count].index=idx;
    dir[count].size=size;

    for(i=0;i<size;i++) {
        do {
            blk=rand()%n;
        } while(used[blk]);
        used[blk]=1;
        index_block[idx][i]=blk;
    }
    count++;
    printf("File created\n");
}

void delete_file() {
    char name[10];
    int i,j,idx;
    printf("Enter file name to delete: ");
    scanf("%s",name);

    for(i=0;i<count;i++) {
        if(strcmp(dir[i].name,name)==0) {
            idx=dir[i].index;
            for(j=0;j<dir[i].size;j++)
                used[index_block[idx][j]]=0;
            used[idx]=0;

            for(j=i;j<count-1;j++)
                dir[j]=dir[j+1];
            count--;
            printf("File deleted\n");
            return;
        }
    }
    printf("File not found\n");
}

void show_dir() {
    int i,j;
    printf("\nFile\tIndex\tBlocks\n");
    for(i=0;i<count;i++) {
        printf("%s\t%d\t",dir[i].name,dir[i].index);
        for(j=0;j<dir[i].size;j++)
            printf("%d ",index_block[dir[i].index][j]);
        printf("\n");
    }
}

int main() {
    int ch;
    init();
    while(1) {
        printf("\n1.Create File\n2.Delete File\n3.Show Directory\n4.Exit\n");
        scanf("%d",&ch);
        if(ch==1) create_file();
        else if(ch==2) delete_file();
        else if(ch==3) show_dir();
        else break;
    }
}
