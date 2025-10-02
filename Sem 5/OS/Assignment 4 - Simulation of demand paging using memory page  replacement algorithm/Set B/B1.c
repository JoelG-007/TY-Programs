/*
Write the simulation program to implement demand paging and show the page 
scheduling and total number of page faults for the following given page reference 
string. Give input n as the number of memory frames. 
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8

i) Implement OPT
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
        if(f[i].pg == -1) printf("[ ]");
        else printf("[%d]", f[i].pg);
    printf("\n");
}

void init(Frame f[], int n){
    for(int i = 0; i < n; i++){
        f[i].pg = -1;
        f[i].freq = 0;
    }
}

int findNext(int rs[], int len, int pg, int start){
    for(int i = start; i < len; i++)
        if(rs[i] == pg) return i;
    return 999999;
}

int findOptimal(Frame f[], int n, int rs[], int len, int curr){
    int farthest = 0, MaxDist = -1;
    for(int i = 0; i < n; i++){
        if(f[i].pg == -1) return i;
        int nextUse = findNext(rs, len, f[i].pg, curr + 1);
        if(nextUse > MaxDist){
            MaxDist = nextUse;
            farthest = i;
        }
    }
    return farthest;
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

    printf("Optimal Page Replacement (OPT)\n");
    init(f, n);
    int opt_faults = 0;
    for (int i = 0; i < len; i++) {
        int pg = rs[i];
        printf("Page %d: ", pg);
        if(find(f, n, pg) != -1){
            printf("HIT\t");
        }else{
            printf("FAULT\t");
            int victim = findOptimal(f, n, rs, len, i);
            f[victim].pg = pg;
            f[victim].freq = 1;
            opt_faults++;
        }
        show(f, n);
    }
    printf("OPT Total Page Faults: %d\n", opt_faults);

    return 0;
}
