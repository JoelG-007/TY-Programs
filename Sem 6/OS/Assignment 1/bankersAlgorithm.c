#include <stdio.h>
#include <stdlib.h>

int n, m, i, j;
int Alloc[10][10], Max[10][10], Need[10][10];
int Avail[10], Work[10];
int Finish[10], Safe[10];
int Request[10], proc;

void accept_matrix(int A[10][10]){
    for(i=0;i<n;i++){
        printf("P[%d]:\n", i);
        for (j=0;j<m;j++){
            scanf("%d", &A[i][j]);
        }
    }
}

void accept_available(){
    for(i=0;i<m;i++)
        scanf("%d", &Avail[i]);
}

void calculate_need(){
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            Need[i][j] = Max[i][j] - Alloc[i][j];
}

void display(){
    printf("\nAllocation\tMax\t\tNeed\n");
    for (i=0; i < n; i++) {
        for(j=0;j<m;j++)printf("%d ", Alloc[i][j]);
        printf("\t");
        for(j=0;j<m;j++)printf("%d ", Max[i][j]);
        printf("\t");
        for(j=0;j<m;j++)printf("%d ", Need[i][j]);
        printf("\n");
    }
    printf("Available: ");
    for (i = 0; i < m; i++) printf("%d ", Avail[i]);
}

int check(int p){
    for(j=0;j<m;j++)
        if(Need[p][j] > Work[j])
            return 0;
    return 1;
}

void safety_algo(){
    for(i=0;i<m;i++) Work[i] = Avail[i];
    for(i=0;i<n;i++) Finish[i] = 0;

    int count = 0;
    while(count<n){
        int found = 0;
        for(i=0;i<n;i++){
            if (!Finish[i] && check(i)){
                for (j=0;j<m;j++)
                    Work[j] += Alloc[i][j];
                Safe[count++] = i;
                Finish[i] = 1;
                found = 1;
            }
        }
        if(!found){
            printf("\nSystem is NOT in safe state\n");
            return;
        }
    }
    printf("\nSafe Sequence: ");
    for(i=0;i<n;i++)
        printf("P%d ", Safe[i]);
}

void request_algo(){
    printf("Enter process number: ");
    scanf("%d", &proc);

    printf("Enter request: ");
    for(i=0;i<m;i++)
        scanf("%d", &Request[i]);

    for(i=0;i<m;i++) {
        if(Request[i] > Need[proc][i]){
            printf("Error: Exceeds maximum need\n");
            return;
        }
        if(Request[i] > Avail[i]){
            printf("Process must wait\n");
            return;
        }
    }
    for(i=0;i<m;i++) {
        Avail[i] -= Request[i];
        Alloc[proc][i] += Request[i];
        Need[proc][i] -= Request[i];
    }
    safety_algo();
}

int main(){
    int choice;
    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    while(1){
        printf("\n1.Accept Allocation\n2.Accept Max\n3.Calculate Need\n");
        printf("4.Accept Available\n5.Display\n6.Request\n7.Safe Sequence\n8.Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: accept_matrix(Alloc); break;
            case 2: accept_matrix(Max); break;
            case 3: calculate_need(); break;
            case 4: accept_available(); break;
            case 5: display(); break;
            case 6: request_algo(); break;
            case 7: safety_algo(); break;
            case 8: exit(0);
        }
    }
}
