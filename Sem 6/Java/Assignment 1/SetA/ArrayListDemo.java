import java.util.*;

public class ArrayListDemo{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<>();

        System.out.println("Enter 5 strings:");
        for(int i = 0; i < 5; i++)
            list.add(sc.nextLine());

        System.out.println("\nUsing Iterator:");
        Iterator<String> it = list.iterator();
        while(it.hasNext())
            System.out.println(it.next());

        System.out.println("\nUsing for-each:");
        for(String s : list)
            System.out.println(s);

        System.out.print("\nEnter index to insert: ");
        int index = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter string: ");
        list.add(index, sc.nextLine());

        System.out.print("Enter string to remove: ");
        list.remove(sc.nextLine());

        System.out.print("Enter string to search: ");
        String search = sc.nextLine();
        System.out.println("Exists? " + list.contains(search));

        System.out.println("Final List: " + list);
    }
}
