/*
Slot- III 
Write a program to simulate Indexed file allocation method. Assume disk with n 
number of blocks. Give value of n as input. Write menu driver program with menu 
options asmentioned above and implement each option.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100             // Maximum number of disk blocks

struct file_details{
    char name[10];
    int size;
    int index_block;
} directory[MAX];

int bit_vector[MAX];        // 0 = free, 1 = occupied
int index_table[MAX][MAX];  // Index block table
int n, count = 0;           // n = number of disk blocks, count = number of files

// Initialize
void initialize(){
    int i;
    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    // Set all blocks as free
    for(i = 0; i < n; i++)
        bit_vector[i] = 0;
}

// Show Bit Vector
void show_bit_vector(){
    int i;
    printf("Bit Vector: ");

    // Display status of each block
    for(i = 0; i < n; i++)
        printf("%d ", bit_vector[i]);
    printf("\n");
}

// Create File
void create_file(){
    char name[10];
    int size, i, j, idx;    // size = file size, i,j = loop variables, idx = index block

    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter file size: ");
    scanf("%d", &size);

    // Find free index block
    for(i = 0; i < n; i++)
        if(bit_vector[i] == 0)
            break;

    if(i == n){
        printf("No index block available\n");
        return;
    }

    idx = i;
    bit_vector[idx] = 1;

    // Allocate blocks for the file
    for(j = 0, i = 0; j < size && i < n; i++){
        if(bit_vector[i] == 0){
            bit_vector[i] = 1;
            index_table[idx][j++] = i;
        }
    }

    // Check if enough blocks were allocated
    if(j < size){
        printf("Not enough space\n");
        bit_vector[idx] = 0;
        return;
    }

    // Update directory
    strcpy(directory[count].name, name);
    directory[count].size = size;
    directory[count].index_block = idx;
    count++;

    printf("File created successfully.\n");
}

// Delete File
void delete_file(){
    char name[10];
    int i, j, idx;

    printf("Enter file name to delete: ");
    scanf("%s", name);

    // Find file in directory
    for(i = 0; i < count; i++){
        if(strcmp(directory[i].name, name) == 0){
            idx = directory[i].index_block;

            // Free allocated blocks
            for(j = 0; j < directory[i].size; j++)
                bit_vector[index_table[idx][j]] = 0;

            // Free index block
            bit_vector[idx] = 0;    

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

// Show Directory
void show_directory(){
    int i, j;
    printf("\nDirectory:\n");

    // Display each file's details
    for(i = 0; i < count; i++){
        printf("%s Index:%d Blocks: ", directory[i].name, directory[i].index_block);

        // Display allocated blocks
        for(j = 0; j < directory[i].size; j++)
            printf("%d ", index_table[directory[i].index_block][j]);
        printf("\n");
    }
}

int main(){
    int choice;
    initialize();

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
