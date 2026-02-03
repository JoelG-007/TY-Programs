/*
Slot - I  
Write a program to simulate Sequential (Contiguous) file allocation method. Assume disk 
with n number of blocks. Give value of n as input. Write menu driver program with menu 
options as mentioned above and implement each option. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct file_details{            
    char file_name[10]; // Name of the file
    int file_size;      // Size of the file in blocks
    int file_start;     // Starting block of the file
}directory[MAX];

int bit_vector[MAX];    // 1 = free, 0 = occupied
int n, count = 0;       // n = number of disk blocks, count = number of files

// Initialize Bit Vector - Initialize number of disk blocks and set all blocks as free
void initialize(){
    int i;
    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        bit_vector[i] = 1;   // 1 = free
}

// Display Bit Vector - Show status of each block
void show_bit_vector(){
    int i;
    printf("Bit Vector: ");
    for(i = 0; i < n; i++)
        printf("%d ", bit_vector[i]);
    printf("\n");
}

// Find contiguous free space - Return starting index if found, else -1
int find_contiguous(int size){
    int i, j;
    for(i = 0; i <= n - size; i++){     
        for(j = 0; j < size; j++){
            if(bit_vector[i + j] == 0)      // 0 = occupied 
                break;
        }   
        if(j == size)
            return i;
    }
    return -1;
}

// Create File
void create_file(){
    char name[10];
    int size, start, i;

    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter file size (blocks): ");
    scanf("%d", &size);

    // Find contiguous free space
    start = find_contiguous(size);
    
    if(start == -1){
        printf("Not enough contiguous space!\n");
        return;
    }

    // Mark blocks as free
    for(i = start; i < start + size; i++)
        bit_vector[i] = 0;

    // Mark blocks as occupied
    strcpy(directory[count].file_name, name);           
    directory[count].file_size = size;
    directory[count].file_start = start;
    count++;

    printf("File allocated successfully.\n");
}

// Display Directory
void show_directory(){
    int i;
    printf("\nDirectory:\n");
    printf("File\tStart\tSize\n");
    for(i = 0; i < count; i++)
        printf("%s\t%d\t%d\n",
               directory[i].file_name,
               directory[i].file_start,
               directory[i].file_size);
}

// Delete File
void delete_file(){
    char name[10];
    int i, j;

    printf("Enter file name to delete: ");
    scanf("%s", name);

    // Find file in directory
    for(i = 0; i < count; i++){
        // If file found
        if(strcmp(directory[i].file_name, name) == 0){
            // Mark blocks as free
            for(j = directory[i].file_start; j < directory[i].file_start + directory[i].file_size; j++)
                bit_vector[j] = 1;
            // Remove file from directory
            for(j = i; j < count - 1; j++)
                directory[j] = directory[j + 1];
            count--;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

int main(){
    int choice;
    initialize();   // Initialize bit vector and number of blocks
    while(1){
        printf("\n1.Show Bit Vector\n2.Create File\n3.Show Directory\n4.Delete File\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: show_bit_vector(); break;
            case 2: create_file(); break;
            case 3: show_directory(); break;
            case 4: delete_file(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
