/*
Write the simulation program to implement demand paging and show the page 
scheduling and total number of page faults for the following given page reference 
string. Give input n as the number of memory frames. 
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8 

i. Implement FIFO
*/

#include<stdio.h>
int main(){
    int rs[] = {12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
    int len = sizeof(rs)/sizeof(rs[0]);
    int n;

    printf("Enter number of memory frames: ");
    scanf("%d",&n);

    int frames[n];
    for(int i=0;i<n;i++) frames[i]=-1;

    int faults=0, pointer=0;

    printf("FIFO Page Replacement:\n");

    for(int i=0;i<len;i++){
        int pg = rs[i];
        int hit=0;
        for(int j=0;j<n;j++){
            if(frames[j]==pg){
                hit=1;
                break;
            }
        }

        printf("Page %d: ", pg);
        if(hit){
            printf("HIT\t");
        }else{
            printf("FAULT\t");
            frames[pointer]=pg;
            pointer = (pointer+1)%n;
            faults++;
        }

        // Show current frames
        for(int j=0;j<n;j++){
            if(frames[j]==-1) printf("[ ]");
            else printf("[%d]",frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults (FIFO): %d\n", faults);
    return 0;
}
