import java.io.*;
import java.util.*;

public class NumberMenuAdv{
    static Set<Integer> numbers = new LinkedHashSet<>();
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
            switch (choice){
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

    // Generate 10 random two-digit numbers (10–99)
    static void loadNumbers(){
        numbers.clear();
        Random rand = new Random();
        while (numbers.size() < 10){
            int num = 10 + rand.nextInt(90);
            numbers.add(num);
        }
        System.out.println("10 random numbers loaded successfully!");
        displayNumbers();
    }

    // Display all numbers
    static void displayNumbers(){
        if(numbers.isEmpty()){
            System.out.println("No numbers loaded yet!");
            return;
        }
        System.out.println("Numbers: " + numbers);
    }

    // Sort and display
    static void sortNumbers(){
        if(numbers.isEmpty()){
            System.out.println("Load numbers first!");
            return;
        }
        List<Integer> sortedList = new ArrayList<>(numbers);
        Collections.sort(sortedList);
        System.out.println("Sorted Numbers: " + sortedList);
    }

    // Save numbers to file
    static void saveToFile(){
        if (numbers.isEmpty()){
            System.out.println("No numbers to save!");
            return;
        }
        try(BufferedWriter writer = new BufferedWriter(new FileWriter("number.txt"))) {
            for (int n : numbers){
                writer.write(n + "\n");
            }
            System.out.println("Numbers saved to number.txt");
        }catch(IOException e){
            System.out.println("Error saving to file: " + e.getMessage());
        }
    }

    // Search for a specific number
    static void searchNumber(){
        if(numbers.isEmpty()){
            System.out.println("No numbers loaded yet!");
            return;
        }
        System.out.print("Enter number to search: ");
        int n = sc.nextInt();
        if(numbers.contains(n)){
            System.out.println(n + " found in the set.");
        }else{
            System.out.println(n + " not found.");
        }
    }
}
