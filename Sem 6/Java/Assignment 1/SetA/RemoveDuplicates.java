import java.util.*;

public class RemoveDuplicates{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();

        System.out.print("Enter count: ");
        int n = sc.nextInt();

        for(int i = 0; i < n; i++)
            list.add(sc.nextInt());

        Set<Integer> unique = new HashSet<>(list);
        System.out.println("Unique Elements: " + unique);
    }
}
