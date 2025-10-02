/*
Implement the C program to accept n integers to be sorted. Main function creates 
child process using fork system call. Parent process sorts the integers using bubble 
sort and waits for child process using wait system call. Child process sorts the integers 
using insertion sort. 
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void bubbleSort(int arr[],int n){
  int i,j,temp;
  for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
      if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
	arr[j+1]=temp;
      }
}

void insertionSort(int arr[], int n){
  int i,key,j;
    for(i=1;i<n;i++){
      key=arr[i], j=i-1;
      while(j>=0 && arr[j]>key)
	arr[j+1]=arr[j--];
      arr[j+1]=key;
    }
}

int main(){
  int n,i;
  pid_t pid;
  
  printf("Enter limit - ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter %d integers - \n",n);
  for(i=0;i<n;i++)scanf("%d",&arr[i]);

  pid=fork();

  if(pid==0){
    insertionSort(arr,n);
    printf("Child (Insertion Sort): ");
    for(i=0;i<n;i++)printf("%d\t",arr[i]);
    printf("\n");
  }else if(pid>0){
    wait(NULL);
    bubbleSort(arr,n);
    printf("Parent (Bubble Sort): ");
    for(i=0;i<n;i++)printf("%d\t",arr[i]);
    printf("\n");
  }else{
    printf("Fork failed\n");
  }
  return 0;
}