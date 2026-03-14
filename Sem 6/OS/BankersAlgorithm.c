#include <stdio.h>
#include <stdlib.h>

int n, m;
int Avail[10], Max[10][10], Alloc[10][10], Need[10][10], Request[10];
int Work[10], Finish[10], Safe[10];

void Accept_matrix(int A[][10]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
}

void Find_Need() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Alloc[i][j];
}

void Display_matrix() {
    printf("\nProcess\tAllocation\t\tMax\t\t\tNeed\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < m; j++) printf("%d ", Alloc[i][j]);
        printf("\t\t");
        for (int j = 0; j < m; j++) printf("%d ", Max[i][j]);
        printf("\t\t");
        for (int j = 0; j < m; j++) printf("%d ", Need[i][j]);
        printf("\n");
    }
    printf("Available: ");
    for (int j = 0; j < m; j++) printf("%d ", Avail[j]);
    printf("\n");
}

void Safety_algo() {
    for (int i = 0; i < m; i++) Work[i] = Avail[i];
    for (int i = 0; i < n; i++) Finish[i] = 0;

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (Finish[i]) continue;
            int ok = 1;
            for (int j = 0; j < m; j++)
                if (Need[i][j] > Work[j]) { ok = 0; break; }
            if (!ok) continue;
            for (int j = 0; j < m; j++) Work[j] += Alloc[i][j];
            Finish[i] = 1;
            Safe[count++] = i;
            found = 1;
        }
        if (!found) { printf("System is UNSAFE!\n"); return; }
    }
    printf("Safe sequence: ");
    for (int i = 0; i < n; i++) printf("P%d ", Safe[i]);
    printf("\n");
}

void Resource_request_algo(int proc) {
    for (int i = 0; i < m; i++)
        if (Request[i] > Need[proc][i] || Request[i] > Avail[i]) {
            printf("Request denied.\n"); return;
        }
    // Tentatively allocate
    for (int i = 0; i < m; i++) {
        Avail[i]       -= Request[i];
        Alloc[proc][i] += Request[i];
        Need[proc][i]  -= Request[i];
    }
    Safety_algo();
}

int main() {
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    int choice, proc;
    while (1) {
        printf("\n1.Accept Allocation  2.Accept Max  3.Calculate Need  4.Accept Available"
               "\n5.Display Matrices  6.Accept Request & Apply Banker's  7.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: Accept_matrix(Alloc); break;
            case 2: Accept_matrix(Max);   break;
            case 3: Find_Need(); printf("Need matrix calculated.\n"); break;
            case 4: printf("Enter Available: ");
                    for (int i = 0; i < m; i++) scanf("%d", &Avail[i]); break;
            case 5: Display_matrix(); break;
            case 6: printf("Enter process number: "); scanf("%d", &proc);
                    printf("Enter request: ");
                    for (int i = 0; i < m; i++) scanf("%d", &Request[i]);
                    Resource_request_algo(proc); break;
            case 7: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}
