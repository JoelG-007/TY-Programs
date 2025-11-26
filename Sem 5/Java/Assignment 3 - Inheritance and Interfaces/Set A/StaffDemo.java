/*
b)  Define an abstract class Staff with protected members id and name. Define a 
    parameterized constructor. Define one subclass OfficeStaff with member 
    department. Create n objects of OfficeStaff and display all details. 
*/

abstract class Staff{
    protected int id;
    protected String name;

    Staff(int id, String name){
        this.id = id;
        this.name = name;
    }

    abstract void display();
}

class OfficeStaff extends Staff{
    String department;

    OfficeStaff(int id, String name, String department){
        super(id, name);
        this.department = department;
    }

    void display(){
        System.out.println("ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
        System.out.println("--------------------");
    }
}

public class StaffDemo{
    public static void main(String[] args){
        OfficeStaff[] staff = {
            new OfficeStaff(1, "Ravi", "Accounts"),
            new OfficeStaff(2, "Sneha", "Admin"),
            new OfficeStaff(3, "Arjun", "IT")
        };

        for (OfficeStaff s : staff){
            s.display();
        }
    }
}
