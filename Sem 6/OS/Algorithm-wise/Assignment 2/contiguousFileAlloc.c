#include <stdio.h>
#include <string.h>

struct file {
    char name[10];
    int start, length;
} dir[10];

int bit[20], n, count=0;

void show_bit() {
    int i;
    for(i=0;i<n;i++) printf("%d ",bit[i]);
    printf("\n");
}

void create_file() {
    char name[10];
    int len,i,j,free;
    printf("Enter file name: ");
    scanf("%s",name);
    printf("Enter file length: ");
    scanf("%d",&len);

    for(i=0;i<=n-len;i++) {
        free=1;
        for(j=0;j<len;j++)
            if(bit[i+j]==0) free=0;

        if(free) {
            strcpy(dir[count].name,name);
            dir[count].start=i;
            dir[count].length=len;
            count++;
            for(j=0;j<len;j++) bit[i+j]=0;
            printf("File allocated\n");
            return;
        }
    }
    printf("No sufficient space\n");
}

void show_dir() {
    int i;
    printf("\nFile\tStart\tLength\n");
    for(i=0;i<count;i++)
        printf("%s\t%d\t%d\n",dir[i].name,dir[i].start,dir[i].length);
}

int main() {
    int i,ch;
    printf("Enter number of blocks: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) bit[i]=1;

    while(1) {
        printf("\n1.Show Bit Vector\n2.Create File\n3.Show Directory\n4.Exit\n");
        scanf("%d",&ch);
        if(ch==1) show_bit();
        else if(ch==2) create_file();
        else if(ch==3) show_dir();
        else break;
    }
}
