#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[10];
    int start,end,size;
} dir[10];

int bit[50], n, free_blocks, count=0;

void init() {
    int i;
    printf("Enter number of blocks: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) bit[i]=-1;
    free_blocks=n;
}

void create_file() {
    char name[10];
    int size,i,prev=-1,curr;
    printf("Enter file name: ");
    scanf("%s",name);
    printf("Enter file size: ");
    scanf("%d",&size);

    if(size>free_blocks) {
        printf("Not enough space\n");
        return;
    }

    strcpy(dir[count].name,name);
    dir[count].size=size;

    for(i=0;i<size;i++) {
        do {
            curr=rand()%n;
        } while(bit[curr]!=-1);

        if(i==0) dir[count].start=curr;
        else bit[prev]=curr;

        prev=curr;
        bit[curr]=-9;
    }

    dir[count].end=prev;
    free_blocks-=size;
    count++;
    printf("File created\n");
}

void delete_file() {
    char name[10];
    int i,j,curr,next;
    printf("Enter file name to delete: ");
    scanf("%s",name);

    for(i=0;i<count;i++) {
        if(strcmp(dir[i].name,name)==0) {
            curr=dir[i].start;
            while(curr!=-9) {
                next=bit[curr];
                bit[curr]=-1;
                curr=next;
                free_blocks++;
            }
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
    int i;
    printf("\nFile\tStart\tEnd\tSize\n");
    for(i=0;i<count;i++)
        printf("%s\t%d\t%d\t%d\n",dir[i].name,dir[i].start,dir[i].end,dir[i].size);
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
