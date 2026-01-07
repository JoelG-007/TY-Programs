#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int main() {
    int req[20], n, head;
    int total = 0, disk_size = 199;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    sort(req, n);
    printf("Seek Sequence: %d ", head);

    for (int i = 0; i < n; i++) {
        if (req[i] >= head) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    total += abs(disk_size - head);
    head = disk_size;
    printf("-> %d ", head);

    total += abs(disk_size - 0);
    head = 0;
    printf("-> %d ", head);

    for (int i = 0; i < n; i++) {
        if (req[i] < head) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}
