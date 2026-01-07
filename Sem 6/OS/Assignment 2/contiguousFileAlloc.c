#include <stdio.h>
#include <string.h>
int i,j;
struct file{
    char name[10];
    int start, size;
}dir[10];

int bit[20], n, count = 0;

void show(){
    for(i = 0; i < n; i++)
        printf("%d ", bit[i]);
}

void create(){
    char name[10];
    int size;
    printf("File name: ");
    scanf("%s", name);
    printf("Size: ");
    scanf("%d", &size);

    for(i=0;i<=n-size;i++){
        int free = 1;
        for(j=0;j<size;j++)
            if(bit[i+j]==0)free = 0;

        if(free){
            strcpy(dir[count].name, name);
            dir[count].start = i;
            dir[count].size = size;
            count++;
            for(j=0;j<size;j++)
                bit[i + j] = 0;
            printf("File allocated\n");
            return;
        }
    }
    printf("No space available\n");
}

int main(){
    printf("Enter disk size: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)bit[i] = 1;

    int ch;
    while (1){
        printf("\n1.Show Bit\n2.Create File\n3.Exit\n");
        scanf("%d", &ch);
        if (ch==1) show();
        else if (ch==2) create();
        else break;
    }
}
