import java.util.*;

public class SetDemo{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        HashSet<Integer> hs = new HashSet<>();
        TreeSet<Integer> ts = new TreeSet<>();

        System.out.print("Enter count: ");
        int n = sc.nextInt();

        System.out.println("Enter numbers:");
        for(int i = 0; i < n; i++){
            int x = sc.nextInt();
            hs.add(x);
            ts.add(x);
        }

        System.out.println("\nHashSet:");
        for(int x : hs)
            System.out.println(x);

        System.out.println("\nTreeSet:");
        for(int x : ts)
            System.out.println(x);
    }
}
