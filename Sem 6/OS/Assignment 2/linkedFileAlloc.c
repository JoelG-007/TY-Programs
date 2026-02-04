/*
Slot - II 
Write a program to simulate Linked file allocation method. Assume disk with n 
number of blocks. Give value of n as input. Write menu driver program with menu 
options as mentioned above and implement each option. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct file_details{
    char file_name[10];
    int file_size;
    int start;
}directory[MAX];

int bit_vector[MAX];   // -1 free, else points to next block
int n, count = 0;

// Initialize
void initialize(){
    int i;
    printf("Enter number of disk blocks: ");
    scanf("%d", &n);
    // Set all blocks as free
    for(i = 0; i < n; i++)
        bit_vector[i] = -1;
}

// Show Bit Vector 
void show_bit_vector(){
    int i;
    printf("Block Status:\n");
    // Display status of each block
    for (i = 0; i < n; i++)
        printf("%d -> %d\n", i, bit_vector[i]);
}

// Create File
void create_file(){
    char name[10];
    int size, i, prev = -1, first = -1, block;

    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter file size: ");
    scanf("%d", &size);

    int free_count = 0;
    // Check for free blocks
    for(i = 0; i < n; i++)
        if(bit_vector[i] == -1)
            free_count++;

    if(free_count < size){
        printf("Not enough free blocks!\n");
        return;
    }
    // Allocate blocks
    for(i = 0; i < size; i++){
        while (1){
            block = rand() % n;
            if (bit_vector[block] == -1)
                break;
        }
        if(first == -1)
            first = block;
        if(prev != -1)
            bit_vector[prev] = block;

        prev = block;
        bit_vector[block] = -2; // temporary
    }

    bit_vector[prev] = -9; // end of file
    
    // Update directory
    strcpy(directory[count].file_name, name);
    directory[count].file_size = size;
    directory[count].start = first;
    count++;

    printf("File created successfully.\n");
}

// Delete File
void delete_file(){
    char name[10];
    int i, pos, next;

    printf("Enter file name to delete: ");
    scanf("%s", name);
    // Find file in directory
    for(i = 0; i < count; i++) {
        if(strcmp(directory[i].file_name, name) == 0) {
            pos = directory[i].start;
            // Free allocated blocks
            while (pos != -9) {
                next = bit_vector[pos];
                bit_vector[pos] = -1;
                if (next == -9) break;
                pos = next;
            }
            // Remove from directory
            for(int j = i; j < count - 1; j++)
                directory[j] = directory[j + 1];
            count--;

            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

// Show Directory
void show_directory(){
    int i;
    printf("\nDirectory:\n");
    printf("File\tStart\tSize\n");
    // Display each file's details
    for (i = 0; i < count; i++)
        printf("%s\t%d\t%d\n",
               directory[i].file_name,
               directory[i].start,
               directory[i].file_size);
}

int main(){
    int choice;
    initialize();
    while(1){
        printf("\n1.Show Bit Vector\n2.Create File\n3.Show Directory\n4.Delete File\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1: show_bit_vector(); break;
            case 2: create_file(); break;
            case 3: show_directory(); break;
            case 4: delete_file(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
