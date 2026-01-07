#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]){
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int main(){
    int req[20], n, head, dir, i, j;
    int total = 0, disk_size = 199;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for (i=0;i<n;i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 = right, 0 = left): ");
    scanf("%d", &dir);

    sort(req, n);
    printf("Seek Sequence: %d ", head);

    if(dir == 1){
        for (i=0;i<n;i++){
            if (req[i] >= head){
                total += abs(req[i] - head);
                head = req[i];
                printf("-> %d ", head);
            }
        }
        total += abs(disk_size - head);
        head = disk_size;
        printf("-> %d ", head);

        for(i=n-1;i>=0;i--){
            if(req[i] < head){
                total += abs(req[i] - head);
                head = req[i];
                printf("-> %d ", head);
            }
        }
    }else{
        for(i=n-1;i>=0;i--){
            if(req[i] <= head){
                total += abs(req[i] - head);
                head = req[i];
                printf("-> %d ", head);
            }
        }
        total += abs(head - 0);
        head = 0;
        printf("-> %d ", head);

        for(i=0;i<n;i++){
            if(req[i] > head){
                total += abs(req[i] - head);
                head = req[i];
                printf("-> %d ", head);
            }
        }
    }

    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}
