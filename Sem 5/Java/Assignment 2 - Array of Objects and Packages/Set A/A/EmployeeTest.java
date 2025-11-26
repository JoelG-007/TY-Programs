/*
a)  Create an employee class(id,name,deptname,salary). Define a default and 
    parameterized constructor. Use ‘this’ keyword to initialize instance variables. 
    Keep a count of objects created. Create objects using parameterized constructor 
    and display the object count after each object is created.(Use static member and 
    method). Also display the contents of each object.
*/
class Employee{
    private int id;
    private String name;
    private String deptName;
    private double salary;
    private static int count = 0;   //static variable to count objects

    public Employee(){             //Default constructor
        this.id = 0;
        this.name = "Unknown";
        this.deptName = "None";
        this.salary = 0.0;
        count++;
    }

    public Employee(int id, String name, String deptName, double salary){   //Parameterized constructor using 'this'
        this.id = id;
        this.name = name;
        this.deptName = deptName;
        this.salary = salary;
        count++;
    }

    public static int getCount(){   // Static method to return object count
        return count;
    }

    public void display(){
        System.out.println("Employee ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Department: " + deptName);
        System.out.println("Salary: " + salary);
        System.out.println("--------------------------------");
    }
}

public class EmployeeTest{
    public static void main(String[] args){
        Employee e1 = new Employee(1, "abc", "IT", 50000);
        System.out.println("Objects created: " + Employee.getCount());
        e1.display();

        Employee e2 = new Employee(2, "def", "HR", 45000);
        System.out.println("Objects created: " + Employee.getCount());
        e2.display();

        Employee e3 = new Employee(3, "ghi", "Finance", 55000);
        System.out.println("Objects created: " + Employee.getCount());
        e3.display();
    }
}
