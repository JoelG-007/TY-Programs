#include <stdio.h>
#include <stdlib.h>

int main(){
    int req[20], visited[20] = {0};
    int i, n, head, total = 0, count;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for(i=0;i<n;i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Seek Sequence: %d ", head);

    for(count=0;count<n;count++){
        int min = 9999, index = -1;

        for(i=0;i<n;i++){
            if(!visited[i]){
                int dist = abs(req[i] - head);
                if(dist < min){
                    min = dist;
                    index = i;
                }
            }
        }

        visited[index] = 1;
        total += abs(req[index] - head);
        head = req[index];
        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}
