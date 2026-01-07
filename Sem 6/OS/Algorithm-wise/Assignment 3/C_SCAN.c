#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n) {
    int i, j, t;
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(a[j] > a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

int cscan(int head, int req[], int n) {
    int i, total = 0;
    int disk_end = 199;

    printf("Sequence: %d ", head);

    for(i = 0; i < n; i++)
        if(req[i] >= head) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }

    total += abs(disk_end - head);
    head = disk_end;
    printf("-> %d ", head);

    total += disk_end;
    head = 0;
    printf("-> %d ", head);

    for(i = 0; i < n; i++)
        if(req[i] < head) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }

    return total;
}

int main() {
    int req[20], n, head, total, i;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    sort(req, n);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    total = cscan(head, req, n);
    printf("\nTotal head movement = %d\n", total);
    return 0;
}
