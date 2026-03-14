import java.util.*;

class Employee implements Comparable<Employee>{
    int id;
    String name;

    Employee(int id, String name){
        this.id = id;
        this.name = name;
    }

    public int compareTo(Employee e){
        return name.compareTo(e.name);
    }

    public String toString(){
        return id + " " + name;
    }
}

public class EmployeeSort{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        TreeSet<Employee> ts = new TreeSet<>();

        System.out.print("Enter employee count: ");
        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++){
            System.out.print("ID: ");
            int id = sc.nextInt();
            sc.nextLine();
            System.out.print("Name: ");
            String name = sc.nextLine();
            ts.add(new Employee(id, name));
        }

        System.out.println("\nSorted by Name:");
        for(Employee e : ts)
            System.out.println(e);
    }
}
