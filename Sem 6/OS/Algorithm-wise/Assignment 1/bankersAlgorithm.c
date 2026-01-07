#include <stdio.h>
#include <stdlib.h>

int n, m;
int Alloc[10][10], Max[10][10], Need[10][10];
int Avail[10], Work[10], Finish[10], Safe[10];
int Request[10], proc;

void accept_matrix(int A[10][10]) {
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&A[i][j]);
}

void accept_available() {
    int i;
    for(i=0;i<m;i++)
        scanf("%d",&Avail[i]);
}

void find_need() {
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            Need[i][j]=Max[i][j]-Alloc[i][j];
}

void display() {
    int i,j;
    printf("\nAllocation\tMax\t\tNeed\n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) printf("%d ",Alloc[i][j]);
        printf("\t");
        for(j=0;j<m;j++) printf("%d ",Max[i][j]);
        printf("\t");
        for(j=0;j<m;j++) printf("%d ",Need[i][j]);
        printf("\n");
    }
    printf("Available: ");
    for(i=0;i<m;i++) printf("%d ",Avail[i]);
    printf("\n");
}

int compare_need(int p) {
    int j;
    for(j=0;j<m;j++)
        if(Need[p][j]>Work[j])
            return -1;
    return p;
}

void safety_algo() {
    int i,k,l=0,pno,found;
    for(i=0;i<m;i++) Work[i]=Avail[i];
    for(i=0;i<n;i++) Finish[i]=0;

    while(l<n) {
        found=0;
        for(i=0;i<n;i++) {
            if(Finish[i]==0) {
                pno=compare_need(i);
                if(pno!=-1) {
                    for(k=0;k<m;k++)
                        Work[k]+=Alloc[pno][k];
                    Finish[pno]=1;
                    Safe[l++]=pno;
                    found=1;
                }
            }
        }
        if(!found) {
            printf("\nSystem is Unsafe\n");
            return;
        }
    }
    printf("\nSafe Sequence: ");
    for(i=0;i<n;i++)
        printf("P%d ",Safe[i]);
    printf("\n");
}

void resource_request_algo() {
    int i;
    printf("Enter process number: ");
    scanf("%d",&proc);
    printf("Enter request vector: ");
    for(i=0;i<m;i++) scanf("%d",&Request[i]);

    for(i=0;i<m;i++) {
        if(Request[i]>Need[proc][i]) {
            printf("Error: Request exceeds need\n");
            return;
        }
        if(Request[i]>Avail[i]) {
            printf("Process must wait\n");
            return;
        }
    }

    for(i=0;i<m;i++) {
        Avail[i]-=Request[i];
        Alloc[proc][i]+=Request[i];
        Need[proc][i]-=Request[i];
    }
    safety_algo();
}

int main() {
    int ch;
    printf("Enter number of processes and resources: ");
    scanf("%d%d",&n,&m);

    while(1) {
        printf("\n1.Accept Allocation\n2.Accept Max\n3.Calculate Need");
        printf("\n4.Accept Available\n5.Display\n6.Accept Request");
        printf("\n7.Display Safe Sequence\n8.Exit\n");
        scanf("%d",&ch);

        switch(ch) {
            case 1: accept_matrix(Alloc); break;
            case 2: accept_matrix(Max); break;
            case 3: find_need(); break;
            case 4: accept_available(); break;
            case 5: display(); break;
            case 6: resource_request_algo(); break;
            case 7: safety_algo(); break;
            case 8: exit(0);
        }
    }
}
