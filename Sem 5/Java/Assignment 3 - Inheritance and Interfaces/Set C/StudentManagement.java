/*
a)  Create an interface Department containing attributes deptName and deptHead. It also 
    has abstract methods for printing the attributes. Create a class hostel containing 
    hostelName, hostelLocation and numberOfRooms. The class contains method printing 
    the attributes. Then write Student class extending the Hostel class and implementing 
    the Department interface. This class contains attributes studentName, regNo, 
    electiveSubject and avgMarks. Write suitable printData method for this class. Also, 
    implement the abstract methods of the Department interface. Write a driver class to 
    test the Student class. The program should be menu driven containing the options: 
          i. Admit new student 
         ii. Migrate a student 
        iii. Display details of a student 
    For the third option, a search is to be made on the basis of the entered registration 
    Number.
*/

import java.util.Scanner;

// Interface Department
interface Department{
    String deptName = "Computer Science";
    String deptHead = "Dr. Yo'el Widus";

    void printDeptDetails();
}

// Hostel class
class Hostel{
    String hostelName;
    String hostelLocation;
    int numberOfRooms;

    Hostel(String hostelName, String hostelLocation, int numberOfRooms){
        this.hostelName = hostelName;
        this.hostelLocation = hostelLocation;
        this.numberOfRooms = numberOfRooms;
    }

    void printHostelDetails(){
        System.out.println("Hostel Name: " + hostelName);
        System.out.println("Hostel Location: " + hostelLocation);
        System.out.println("Number of Rooms: " + numberOfRooms);
    }
}

// Student class
class Student extends Hostel implements Department{
    String studentName;
    String regNo;
    String electiveSubject;
    double avgMarks;

    Student(String hostelName, String hostelLocation, int numberOfRooms,
            String studentName, String regNo, String electiveSubject, double avgMarks){
        super(hostelName, hostelLocation, numberOfRooms);
        this.studentName = studentName;
        this.regNo = regNo;
        this.electiveSubject = electiveSubject;
        this.avgMarks = avgMarks;
    }

    public void printDeptDetails(){
        System.out.println("Department Name: " + deptName);
        System.out.println("Department Head: " + deptHead);
    }

    void printData(){
        System.out.println("\n--- Student Details ---");
        System.out.println("Student Name: " + studentName);
        System.out.println("Registration No: " + regNo);
        System.out.println("Elective Subject: " + electiveSubject);
        System.out.println("Average Marks: " + avgMarks);
        printDeptDetails();
        printHostelDetails();
        System.out.println("-----------------------------");
    }
}

// Driver class
public class StudentManagement{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Student[] students = new Student[10];
        int count = 0;
        int choice;

        do{
            System.out.println("\n=== MENU ===");
            System.out.println("1. Admit new student");
            System.out.println("2. Migrate student");
            System.out.println("3. Display student details");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice){
                case 1:
                    System.out.print("Enter Student Name: ");
                    String name = sc.nextLine();
                    System.out.print("Enter Registration No: ");
                    String regNo = sc.nextLine();
                    System.out.print("Enter Elective Subject: ");
                    String elective = sc.nextLine();
                    System.out.print("Enter Average Marks: ");
                    double avg = sc.nextDouble();
                    sc.nextLine();

                    System.out.print("Enter Hostel Name: ");
                    String hName = sc.nextLine();
                    System.out.print("Enter Hostel Location: ");
                    String hLoc = sc.nextLine();
                    System.out.print("Enter Number of Rooms: ");
                    int rooms = sc.nextInt();

                    students[count++] = new Student(hName, hLoc, rooms, name, regNo, elective, avg);
                    System.out.println("✅ Student admitted successfully!");
                    break;

                case 2:
                    System.out.print("Enter Registration No to migrate: ");
                    String regToMigrate = sc.nextLine();
                    boolean found = false;
                    for (int i = 0; i < count; i++) {
                        if (students[i].regNo.equals(regToMigrate)) {
                            System.out.print("Enter new hostel name: ");
                            students[i].hostelName = sc.nextLine();
                            System.out.print("Enter new hostel location: ");
                            students[i].hostelLocation = sc.nextLine();
                            System.out.println("✅ Student migrated successfully!");
                            found = true;
                            break;
                        }
                    }
                    if(!found) System.out.println("⚠️ Student not found.");
                    break;

                case 3:
                    System.out.print("Enter Registration No to search: ");
                    String regSearch = sc.nextLine();
                    boolean match = false;
                    for(int i = 0; i < count; i++) {
                        if(students[i].regNo.equals(regSearch)) {
                            students[i].printData();
                            match = true;
                            break;
                        }
                    }
                    if(!match)
                        System.out.println("⚠️ No student found with Registration No: " + regSearch);
                    break;

                case 4:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }while (choice != 4);
    }
}
