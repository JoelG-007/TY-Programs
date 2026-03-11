#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j] > a[j+1]){int t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
}

// FCFS
void fcfs(int req[], int n, int head){
    int total=0;
    printf("FCFS Sequence: %d ", head);
    for(int i=0; i<n; i++){
        total += abs(req[i] - head);
        head=req[i];
        printf("-> %d ", head);
    }
    printf("\nTotal: %d\n", total);
}

// SSTF
void sstf(int req[], int n, int head){
    int visited[20] ={0}, total=0;
    printf("SSTF Sequence: %d ", head);
    for(int c=0; c<n; c++){
        int min=9999, idx=-1;
        for(int i=0; i<n; i++)
            if(!visited[i] && abs(req[i]-head)<min){min=abs(req[i]-head); idx=i; }
        visited[idx]=1; total += abs(req[idx]-head); head=req[idx];
        printf("-> %d ", head);
    }
    printf("\nTotal: %d\n", total);
}

// SCAN
void scan(int req[], int n, int head, int dir){
    int total=0, disk_size=199;
    sort(req, n);
    printf("SCAN Sequence: %d ", head);
    if(dir == 1){
        for(int i=0; i<n; i++) if(req[i] >= head){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
        total += abs(disk_size-head); head=disk_size; printf("-> %d ", head);
        for(int i=n-1; i >= 0; i--) if(req[i]<head){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
    } else{
        for(int i=n-1; i >= 0; i--) if(req[i] <= head){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
        total += head; head=0; printf("-> 0 ");
        for(int i=0; i<n; i++) if(req[i] > head){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
    }
    printf("\nTotal: %d\n", total);
}

// C-SCAN
void cscan(int req[], int n, int head){
    int total=0, disk_size=199, start=head;
    sort(req, n);
    printf("C-SCAN Sequence: %d ", head);
    for(int i=0; i<n; i++) if(req[i] >= start){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
    total += abs(disk_size-head); head=disk_size; printf("-> %d ", head);
    total += disk_size; head=0; printf("-> 0 ");
    for(int i=0; i<n; i++) if(req[i]<start){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
    printf("\nTotal: %d\n", total);
}

// LOOK(like SCAN but stops at last request, not disk boundary)
void look(int req[], int n, int head, int dir){
    int total=0, start=head;
    sort(req, n);
    printf("LOOK Sequence: %d ", head);
    if(dir == 1){
        for(int i=0; i<n; i++) if(req[i] >= start){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
        for(int i=n-1; i >= 0; i--) if(req[i]<start){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
    } else{
        for(int i=n-1; i >= 0; i--) if(req[i] <= start){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
        for(int i=0; i<n; i++) if(req[i] > start){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
    }
    printf("\nTotal: %d\n", total);
}

// C-LOOK(like C-SCAN but jumps back to lowest request, not 0)
void clook(int req[], int n, int head){
    int total=0, start=head;
    sort(req, n);
    printf("C-LOOK Sequence: %d ", head);
    for(int i=0; i<n; i++) if(req[i] >= start){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
    // Jump to the smallest request(no physical seek to 0)
    for(int i=0; i<n; i++){
        if(req[i]<start){total += abs(req[i]-head); head=req[i]; printf("-> %d ", head); }
    }
    printf("\nTotal: %d\n", total);
}

int main(){
    int req[20], n, head, ch;
    printf("Requests: "); scanf("%d", &n);
    printf("Enter %d requests: ", n);
    for(int i=0; i<n; i++) scanf("%d", &req[i]);
    printf("Head: "); scanf("%d", &head);

    printf("\n1.FCFS 2.SSTF 3.SCAN 4.C-SCAN 5.LOOK 6.C-LOOK\nChoice: ");
    scanf("%d", &ch);
    int dir;
    switch(ch){
        case 1: fcfs(req,n,head); break;
        case 2: sstf(req,n,head); break;
        case 3: printf("Direction(1=right, 0=left): "); scanf("%d",&dir); scan(req,n,head,dir); break;
        case 4: cscan(req,n,head); break;
        case 5: printf("Direction(1=right, 0=left): "); scanf("%d",&dir); look(req,n,head,dir); break;
        case 6: clook(req,n,head); break;
        default: printf("Invalid choice\n");
    }
}