import java.util.*;

public class EmployeeMapSort{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        TreeMap<Integer, String> map = new TreeMap<>();

        System.out.print("Enter entries: ");
        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++){
            System.out.print("ID: ");
            int id = sc.nextInt();
            sc.nextLine();
            System.out.print("Name: ");
            map.put(id, sc.nextLine());
        }

        System.out.println("\nSorted by Employee ID:");
        for(Map.Entry<Integer, String> e : map.entrySet())
            System.out.println(e.getKey() + " " + e.getValue());
    }
}
