/*
a)  Write a java program that take input as a person name in the format of first, middle 
    and last name and then print it in the form last, first and middle name, where in the 
    middle name first character is capital letter. 
*/
import java.util.Scanner;
public class NameFormat{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first name: ");
        String first = sc.next();

        System.out.print("Enter middle name: ");
        String middle = sc.next();

        System.out.print("Enter last name: ");
        String last = sc.next();

        System.out.println("\n(Before Formatting) Name: " + last + " " + first + " " + middle);

        // Capitalize first letter of middle name
        middle = middle.substring(0, 1).toUpperCase() + middle.substring(1).toLowerCase();
        
        System.out.println("\n(Formatted) Name: " + last + " " + first + " " + middle);
    }
}
