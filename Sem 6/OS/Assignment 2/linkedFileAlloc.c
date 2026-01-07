#include <stdio.h>
#include <stdlib.h>

int mem[20], n;

int main(){
    int i;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) mem[i] = -1;

    int start, len;
    printf("Start block: ");
    scanf("%d", &start);
    printf("Length: ");
    scanf("%d", &len);

    int prev = start;
    for(i=1;i<len;i++) {
        mem[prev] = prev + 1;
        prev++;
    }
    mem[prev] = -9;

    printf("Linked Allocation:\n");
    int t = start;
    while (t != -9) {
        printf("%d -> ", t);
        t = mem[t];
    }
    printf("NULL\n");
}
