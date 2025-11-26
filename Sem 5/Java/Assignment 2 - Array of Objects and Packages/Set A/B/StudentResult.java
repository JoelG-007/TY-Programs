/*
b)  Write a Java program to create a Package “SY” which has a class SYMarks 
    (members – ComputerTotal, MathsTotal, and ElectronicsTotal). Create another 
    package TY which has a class TYMarks (members – Theory, Practicals). Create n 
    objects of Student class (having rollNumber, name, SYMarks and TYMarks). Add 
    the marks of SY and TY computer subjects and calculate the Grade (‘A’ for >= 70, 
    ‘B’ for >= 60 ‘C’ for >= 50 , Pass Class for > =40 else ‘FAIL’) and display the result 
    of the student in proper format. 

    Note: Create separate files for each class and package. The main class StudentResult 
    should be in default package. The file structure is as follows:
    SY/
        SYMarks.java
    TY/
        TYMarks.java
    StudentResult.java (Main Java File)

*/

import SY.SYMarks;
import TY.TYMarks;
import java.util.Scanner;

class Student {
    int rollNumber;
    String name;
    SYMarks sy;
    TYMarks ty;
    char grade;

    public Student(int rollNumber, String name, SYMarks sy, TYMarks ty) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.sy = sy;
        this.ty = ty;
        calculateGrade();
    }

    private void calculateGrade() {
        int total = sy.ComputerTotal + ty.Theory + ty.Practicals;
        double average = total / 3.0;

        if (average >= 70)
            grade = 'A';
        else if (average >= 60)
            grade = 'B';
        else if (average >= 50)
            grade = 'C';
        else if (average >= 40)
            grade = 'P'; // Pass Class
        else
            grade = 'F'; // Fail
    }

    public void display() {
        System.out.println("\nRoll No: " + rollNumber);
        System.out.println("Name: " + name);
        System.out.println("SY Computer: " + sy.ComputerTotal);
        System.out.println("TY Theory: " + ty.Theory + ", Practicals: " + ty.Practicals);
        System.out.println("Grade: " + grade);
        System.out.println("-----------------------------");
    }
}

public class StudentResult {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();

        Student[] students = new Student[n];

        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for student " + (i + 1));
            System.out.print("Roll Number: ");
            int roll = sc.nextInt();
            sc.nextLine(); // consume newline
            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("SY Computer, Maths, Electronics marks: ");
            int c = sc.nextInt(), m = sc.nextInt(), e = sc.nextInt();
            System.out.print("TY Theory, Practicals marks: ");
            int t = sc.nextInt(), p = sc.nextInt();

            students[i] = new Student(roll, name, new SYMarks(c, m, e), new TYMarks(t, p));
        }

        System.out.println("\n=== STUDENT RESULTS ===");
        for (Student s : students) {
            s.display();
        }
    }
}
