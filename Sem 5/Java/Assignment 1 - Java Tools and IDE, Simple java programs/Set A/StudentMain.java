/*
b)  Write a Java program to create a class Student with attributes name, rollNo, and marks. Add 
    methods to input and display student details and check if the student has passed (marks > 40).
*/

import java.util.Scanner;
class Student{
    String name;
    int rollNo;
    int marks;

    void inputDetails(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name: ");
        name = sc.nextLine();
        System.out.print("Enter Roll No: ");
        rollNo = sc.nextInt();
        System.out.print("Enter Marks: ");
        marks = sc.nextInt();
    }

    void displayDetails(){
        System.out.println("\n--- Student Details ---");
        System.out.println("Name: " + name);
        System.out.println("Roll No: " + rollNo);
        System.out.println("Marks: " + marks);
        if(marks > 40)
            System.out.println("Status: Passed");
        else
            System.out.println("Status: Failed");
    }
}

public class StudentMain{
    public static void main(String[] args){
        Student s = new Student();
        s.inputDetails();
        s.displayDetails();
    }
}
