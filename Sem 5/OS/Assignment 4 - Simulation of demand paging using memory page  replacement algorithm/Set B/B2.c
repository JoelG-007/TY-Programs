/*
Write the simulation program to implement demand paging and show the page 
scheduling and total number of page faults for the following given page reference 
string. Give input n as the number of memory frames. 
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8

ii) Implement MFU
*/

#include <stdio.h>
typedef struct{
    int pg, freq;
}Frame;

int find(Frame f[], int n, int pg){
    for(int i = 0; i < n; i++)
        if(f[i].pg == pg) return i;
    return -1;
}

void show(Frame f[], int n){
    for(int i = 0; i < n; i++)
        if (f[i].pg == -1) printf("[ ]");
        else printf("[%d]", f[i].pg);
    printf("\n");
}

void init(Frame f[], int n){
    for(int i = 0; i < n; i++){
        f[i].pg = -1;
        f[i].freq = 0;
    }
}

int findMFU(Frame f[], int n){
    int mfu = 0;
    for(int i = 0; i < n; i++){
        if (f[i].pg == -1) return i;
        if (f[i].freq > f[mfu].freq)
            mfu = i;
    }
    return mfu;
}

int main(){
    int rs[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int len = sizeof(rs) / sizeof(rs[0]);
    int n;
    
    printf("Enter number of memory frames: ");
    scanf("%d", &n);
    
    Frame f[n];
    
    printf("\nReference String: { ");
    for(int i = 0; i < len; i++) printf("%d ", rs[i]);
    printf("}\n\n");

    printf("Most Frequently Used (MFU)\n");
    init(f, n);
    int mfu_faults = 0;
    for(int i = 0; i < len; i++){
        int pg = rs[i];
        printf("Page %d: ", pg);
        int idx = find(f, n, pg);
        if(idx != -1){
            printf("HIT\t");
            f[idx].freq++;
        }else{
            printf("FAULT\t");
            int victim = findMFU(f, n);
            f[victim].pg = pg;
            f[victim].freq = 1;
            mfu_faults++;
        }
        show(f, n);
    }
    printf("MFU Total Page Faults: %d\n", mfu_faults);

    return 0;
}
