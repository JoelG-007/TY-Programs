/*
Write the simulation program to implement demand paging and show the page 
scheduling and total number of page faults for the following given page reference string. 
Give input n as the number of memory frames. 
Reference String: 2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8

i) Implement MRU
*/

#include <stdio.h>
typedef struct {
    int pg, time;
}Frame;

int find(Frame f[], int n, int pg){
    for(int i = 0; i < n; i++)
        if(f[i].pg == pg) return i;
    return -1;
}

int findMRU(Frame f[], int n) {
    int mru = 0;
    for(int i = 1; i < n; i++)
        if(f[i].time > f[mru].time) mru = i;
    return mru;
}

void show(Frame f[], int n){
    for(int i = 0; i < n; i++){
        if (f[i].pg == -1) printf("[ ]");
        else printf("[%d]", f[i].pg);
    }
    printf("\n");
}

int main(){
    int rs[] = {2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8};
    int len = sizeof(rs)/sizeof(rs[0]);
    int n;
    
    printf("Enter number of memory frames: ");
    scanf("%d",&n);
    
    Frame f[n];
    for(int i=0;i<n;i++) f[i].pg=-1, f[i].time=0;
    
    int counter=0, faults=0;
    
    printf("MRU Page Replacement :\n");
    
    for(int i=0;i<len;i++){
        int pg = rs[i];
        printf("Page %d: ",pg);
        int idx = find(f,n,pg);
        if(idx != -1){
            printf("HIT\t");
            counter++;
            f[idx].time = counter;
        }else{
            printf("FAULT\t");
            int victim = (counter<n) ? counter : findMRU(f,n);
            f[victim].pg = pg;
            counter++;
            f[victim].time = counter;
            faults++;
        }
        show(f,n);
    }
    
    printf("Total Page Faults (MRU): %d\n", faults);
    return 0;
}
