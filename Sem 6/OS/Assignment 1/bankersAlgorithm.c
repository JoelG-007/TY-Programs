/* 
Slot I + Slot II

Slot I 
I) Add the following functionalities in your program 
a) Accept Available, Max                    accept_available() + accept_matrix()
b) Display Allocation, Max                  display_matrices()
c) Display the contents of need matrix      calculate_need() + display_matrices()
d) Display Available                        display_matrices()
                _______________________________________________
                |Process| Allocation||    Max    ||   Need    |
                |_______|___|___|___||___|___|___||___|___|___|
                |       | A | B | C || A | B | C || A | B | C |
                |_______|___|___|___||___|___|___||___|___|___|
                |       |   |   |   ||   |   |   ||   |   |   |
    --->        |   P0  | 0 | 1 | 0 || 7 | 5 | 3 || 7 | 4 | 3 |
                |_______|___|___|___||___|___|___||___|___|___|
                |       |   |   |   ||   |   |   ||   |   |   |
    --->        |   P1  | 2 | 0 | 0 || 3 | 2 | 2 || 1 | 2 | 2 |
                |_______|___|___|___||___|___|___||___|___|___|
                |       |   |   |   ||   |   |   ||   |   |   |
    --->        |   P2  | 3 | 0 | 2 || 9 | 0 | 2 || 6 | 0 | 0 |
                |_______|___|___|___||___|___|___||___|___|___|
                |       |   |   |   ||   |   |   ||   |   |   |
    --->        |   P3  | 2 | 1 | 1 || 2 | 2 | 2 || 0 | 1 | 1 |
                |_______|___|___|___||___|___|___||___|___|___|
                |       |   |   |   ||   |   |   ||   |   |   |
    --->        |   P4  | 0 | 0 | 2 || 4 | 3 | 0 || 4 | 3 | 0 |
                |_______|___|___|___||___|___|___||___|___|___|

Slot II 
I) Modify above program so as to include the following: 
a) Accept Request for a process             accept_request()
b) Resource request algorithm               resource_request_algo()
c) Safety algorithm                         safety_algo() 
Consider a system with ‘n’ processes and ‘m’ resource types. Accept number of 
instances for every resource type. For each process accept the allocation and 
maximum requirement matrices. Write a program to display the contents of 
need matrix and to check if the given request of a process can be granted 
immediately or not.
*/

#include <stdio.h>
#include <stdlib.h>

int n, m, proc;         // n = processes, m = resources
int Alloc[10][10], Max[10][10], Need[10][10];
int Avail[10], Request[10], Finish[10], Work[10], Safe[10];

// Accept matrix
void accept_matrix(int A[10][10]){
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
}

// Accept Available
void accept_available(){
    int i;
    for(i = 0; i < m; i++)
        scanf("%d", &Avail[i]);
}

// Calculate Need
void calculate_need(){
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Alloc[i][j];   // Need = Max - Alloc
}

// Display matrices
void display_matrices(){
    int i, j;
    printf("\nProcess\tAllocation\tMax\t\tNeed\n");
    for (i = 0; i < n; i++){
        printf("P%d\t", i);
        for (j = 0; j < m; j++) printf("%d ", Alloc[i][j]);
        printf("\t");
        for (j = 0; j < m; j++) printf("%d ", Max[i][j]);
        printf("\t");
        for (j = 0; j < m; j++) printf("%d ", Need[i][j]);
        printf("\n");
    }
    printf("\nAvailable:\n");
    for(j = 0; j < m; j++)
        printf("%d ", Avail[j]);
    printf("\n");
}

// Check Need <= Work for process p
int compare_need(int p) {
    int j;
    for (j = 0; j < m; j++)
        if (Need[p][j] > Work[j])
            return -1;
    return p;
}

// Safety Algorithm - Check if system is in safe state
// If yes, display safe sequence otherwise indicate unsafe state
void safety_algo(){
    int i, j, k, count = 0, found;

    // Initialize Work and Finish
    for (i = 0; i < m; i++)
        Work[i] = Avail[i];
    for (i = 0; i < n; i++)
        Finish[i] = 0;

    // What's going on here? - Find an i such that Finish[i] == 0 and Need[i] <= Work 
    // in short we are looking for a process which can be completed
    // Why? - To ensure all processes can complete and system is in safe state
    while(count < n){
        found = 0;
        for(i = 0; i < n; i++){
            if(!Finish[i] && compare_need(i) != -1){  // If Need <= Work
                for (k = 0; k < m; k++)
                    Work[k] += Alloc[i][k];
                Safe[count++] = i;
                Finish[i] = 1;
                found = 1;
            }
        }
        if(!found){                                     // No such i found
            printf("\nSystem is NOT in safe state\n");
            return;
        }
    }
    printf("\nSystem is in SAFE state\nSafe Sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", Safe[i]);
    printf("\n");
}

// Accept Request
void accept_request(){
    int i;
    printf("\nEnter process number: ");
    scanf("%d", &proc);
    printf("Enter request vector:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &Request[i]);
}

// Resource Request Algorithm
void resource_request_algo(){
    int i;

    // What's going on here? - Check if Request <= Need
    // Why? - To ensure process does not request more than its maximum claim
    for(i = 0; i < m; i++){
        if(Request[i] > Need[proc][i]){
            printf("\nError: Process exceeded its maximum claim\n");
            return;
        }
    }

    // What's going on here? - Check if resources are available
    // Why? - To see if resources are available
    for(i=0;i<m;i++){
        if(Request[i] > Avail[i]){
            printf("\nProcess must wait (Resources not available)\n");
            return;
        }
    }

    // What's going on here? - Allocate requested resources temporarily
    // Why? - To check if the system will be in safe state after allocation
    for(i=0;i<m;i++){                       
        Avail[i] -= Request[i];
        Alloc[proc][i] += Request[i];
        Need[proc][i] -= Request[i];
    }

    safety_algo();      // Check if system is in safe state
}

int main(){
    int choice;
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);
    while(1){
        printf("\n1.Accept Allocation");
        printf("\n2.Accept Max");
        printf("\n3.Calculate Need");
        printf("\n4.Accept Available");
        printf("\n5.Display Matrices");
        printf("\n6.Accept Request & Apply Banker");
        printf("\n7.Display Safe Sequence");
        printf("\n8.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Allocation Matrix:\n");
                accept_matrix(Alloc);
                break;
            case 2:
                printf("Enter Max Matrix:\n");
                accept_matrix(Max);
                break;
            case 3:
                calculate_need();
                printf("Need Matrix Calculated\n");
                break;
            case 4:
                printf("Enter Available Resources:\n");
                accept_available();
                break;
            case 5:
                display_matrices();
                break;
            case 6:
                accept_request();
                resource_request_algo();
                break;
            case 7:
                safety_algo();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}