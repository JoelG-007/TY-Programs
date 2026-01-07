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

void accept_requests(int req[], int n) {
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);
    sort(req, n);
}

int sstf(int head, int req[], int n) {
    int visited[20] = {0};
    int count = 0, total = 0;

    printf("Sequence: %d ", head);

    while(count < n) {
        int i, min = 9999, pos = -1;
        for(i = 0; i < n; i++) {
            if(!visited[i] && abs(req[i] - head) < min) {
                min = abs(req[i] - head);
                pos = i;
            }
        }
        visited[pos] = 1;
        total += abs(req[pos] - head);
        head = req[pos];
        printf("-> %d ", head);
        count++;
    }
    return total;
}

int main() {
    int req[20], n, head, total;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    accept_requests(req, n);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    total = sstf(head, req, n);
    printf("\nTotal head movement = %d\n", total);
    return 0;
}
