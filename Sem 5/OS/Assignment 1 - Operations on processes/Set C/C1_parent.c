/*
 Implement the C program that accepts an integer array. Main function forks child 
process. Parent process sorts an integer array and passes the sorted array to child 
process through the command line arguments of execve() system call. The child 
process uses execve() system call to load new program that uses this sorted array for 
performing the binary search to search the particular item in the array. 
*/

//SORTING AND PASSING ARRAY TO CHILD PROCESS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n, i;
    printf("Enter number of elements: \n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: \n", n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    bubbleSort(arr, n);

    printf("Sorted Array: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    char *args[n + 3]; // program name + n elements + NULL
    args[0] = "./binarysearch";
    for(i = 0; i < n; i++){
        char *num = malloc(10);
        sprintf(num, "%d", arr[i]);
        args[i + 1] = num;
    }
    args[n + 1] = NULL;

    pid_t pid = fork();
    if(pid == 0){
        execve(args[0], args, NULL);
        perror("execve failed");
        exit(1);
    }else{
        wait(NULL);
        printf("Parent: Child finished execution.\n");
    }
    return 0;
}
