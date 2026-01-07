#include <stdio.h>

int index[10][10], used[10];

int main(){
    int n, files, i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter number of files: ");
    scanf("%d", &files);

    for(i=0;i<files;i++){
        int blocks;
        printf("Enter blocks for file %d: ", i);
        scanf("%d", &blocks);

        printf("Enter block numbers: ");
        for(j=0;j<blocks;j++) {
            scanf("%d", &index[i][j]);
            used[index[i][j]] = 1;
        }
    }

    printf("Indexed Allocation Table\n");
    for(i=0;i<files;i++){
        printf("File %d: ", i);
        for(j=0;index[i][j]!=0;j++)
            printf("%d ", index[i][j]);
        printf("\n");
    }
}
