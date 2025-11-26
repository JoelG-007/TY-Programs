/*
a)  Write a menu driven program to perform the following operations on a set of integers 
    as shown in the following figure. A load operation should generate 10 random 
    integers (2 digit) and display the number on screen. The save operation should save 
    the number to a file “number.txt”. The short menu provides various operations and the 
    result is displayed on the screen. 
*/

import java.io.*;
import java.util.*;

public class NumberMenuBasic{
    static int[] numbers = new int[10];
    static boolean loaded = false;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        int choice;
        do{
            System.out.println("\n=== MENU ===");
            System.out.println("1. Load (Generate 10 Random 2-digit Integers)");
            System.out.println("2. Display Numbers");
            System.out.println("3. Sort Numbers");
            System.out.println("4. Save to File (number.txt)");
            System.out.println("5. Search a Number");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            switch(choice){
                case 1 -> loadNumbers();
                case 2 -> displayNumbers();
                case 3 -> sortNumbers();
                case 4 -> saveToFile();
                case 5 -> searchNumber();
                case 6 -> System.out.println("Exiting...");
                default -> System.out.println("Invalid choice! Try again.");
            }
        }while(choice != 6);
    }

    static void loadNumbers(){                  // Generate 10 random 2-digit numbers (10–99)
        Random rand = new Random();
        for(int i = 0; i < 10; i++){
            numbers[i] = 10 + rand.nextInt(90);
        }
        loaded = true;
        System.out.println("10 random numbers loaded successfully!");
        displayNumbers();
    }

    static void displayNumbers(){               // Display all numbers
        if(!loaded){
            System.out.println("Please load numbers first!");
            return;
        }
        System.out.println("Numbers:");
        for (int num : numbers) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    static void sortNumbers(){                  // Sort numbers in ascending order
        if(!loaded){
            System.out.println("Load numbers first!");
            return;
        }
        Arrays.sort(numbers);
        System.out.println("Numbers sorted successfully!");
        displayNumbers();
    }

    static void saveToFile(){                  // Save numbers to a text file
        if(!loaded){
            System.out.println("No numbers to save!");
            return;
        }
        try(BufferedWriter writer = new BufferedWriter(new FileWriter("number.txt"))) {
            for(int num : numbers){
                writer.write(num + "\n");
            }
            System.out.println("Numbers saved to number.txt");
        } catch (IOException e) {
            System.out.println("Error saving file: " + e.getMessage());
        }
    }

    static void searchNumber(){                 // Search for a number in the array
        if(!loaded){
            System.out.println("Load numbers first!");
            return;
        }
        System.out.print("Enter number to search: ");
        int key = sc.nextInt();
        boolean found = false;
        for(int num : numbers){
            if(num == key){
                found = true;
                break;
            }
        }
        if(found){
            System.out.println(key + " found in the list.");
        }else{
            System.out.println(key + " not found.");
        }
    }
}
