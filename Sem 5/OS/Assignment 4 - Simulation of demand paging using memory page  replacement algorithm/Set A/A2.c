/*
Write the simulation program to implement demand paging and show the page 
scheduling and total number of page faults for the following given page reference 
string. Give input n as the number of memory frames. 
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8 

i. Implement LRU
*/

#include<stdio.h>
int findLRU(int time[], int n){
    int min=time[0], pos=0;
    for(int i=1;i<n;i++){
        if(time[i]<min){
            min=time[i];
            pos=i;
        }
    }
    return pos;
}

int main(){
    int rs[] = {12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
    int len = sizeof(rs)/sizeof(rs[0]);
    int n;

    printf("Enter number of memory frames: ");
    scanf("%d",&n);

    int frames[n], time[n];
    for(int i=0;i<n;i++) frames[i]=-1, time[i]=0;

    int counter=0, faults=0;

    printf("LRU Page Replacement:\n");

    for(int i=0;i<len;i++){
        int pg = rs[i];
        int hit=0;
        for(int j=0;j<n;j++){
            if(frames[j]==pg){
                hit=1;
                counter++;
                time[j]=counter;
                break;
            }
        }

        printf("Page %d: ", pg);
        if(hit){
            printf("HIT\t");
        } else {
            int replaced = 0;
            for(int j=0;j<n;j++){
                if(frames[j]==-1){
                    frames[j]=pg;
                    counter++;
                    time[j]=counter;
                    faults++;
                    replaced=1;
                    break;
                }
            }
            if(!replaced){
                int pos = findLRU(time,n);
                frames[pos]=pg;
                counter++;
                time[pos]=counter;
                faults++;
            }
        }

        // Show current frames
        for(int j=0;j<n;j++){
            if(frames[j]==-1) printf("[ ]");
            else printf("[%d]",frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults (LRU): %d\n", faults);
    return 0;
}
