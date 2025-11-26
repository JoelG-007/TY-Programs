/*
b)  Write a java program to accept Employee name from the user and check whether it is 
    valid or not. If it is not valid then throw user defined Exception “Name is Invalid” 
    otherwise display it.(Name should contain only characters) 
*/

import java.util.Scanner;
class InvalidNameException extends Exception{   // User-defined Exception
    InvalidNameException(String message){
        super(message);
    }
}
public class EmployeeNameCheck{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        try{
            System.out.print("Enter Employee Name: ");
            String name = sc.nextLine();
            if(!name.matches("[a-zA-Z ]+")){    // Validate name using regex (only alphabets and spaces)
                throw new InvalidNameException("Name is Invalid — only alphabets allowed!");
            }
            System.out.println("Valid Employee Name: " + name);
        }catch (InvalidNameException e){
            System.out.println(e.getMessage());
        }
    }
}
