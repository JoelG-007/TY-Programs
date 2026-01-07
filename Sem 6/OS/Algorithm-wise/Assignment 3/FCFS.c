#include <stdio.h>
#include <stdlib.h>

void accept_requests(int req[], int n) {
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);
}

int fcfs(int head, int req[], int n) {
    int i, total = 0;
    printf("Sequence: %d ", head);

    for(i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
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

    total = fcfs(head, req, n);
    printf("\nTotal head movement = %d\n", total);
    return 0;
}
