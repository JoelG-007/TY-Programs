//BINARY SEARCH PROGRAM

#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int n, int key){
    int low = 0, high = n - 1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("No array elements received!\n");
        return 1;
    }

    int n = argc - 1;
    int arr[n];
    for(int i = 1; i < argc; i++) arr[i - 1] = atoi(argv[i]);

    printf("Child received sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    int pos = binarySearch(arr, n, key);
    if(pos == -1)
        printf("Element %d not found in array.\n", key);
    else
        printf("Element %d found at position %d.\n", key, pos + 1);

    return 0;
}
