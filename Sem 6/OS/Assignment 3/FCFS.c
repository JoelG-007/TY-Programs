#include <stdio.h>

int main() {
    int req[10], n, head, total = 0, i;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
        scanf("%d", &req[i]);

    printf("Enter head: ");
    scanf("%d", &head);

    for(i=0;i<n;i++){
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("Total head movement = %d\n", total);
}
