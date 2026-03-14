import java.util.*;

public class SortNumbers{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();

        System.out.print("Enter count: ");
        int n = sc.nextInt();

        for(int i = 0; i < n; i++)
            list.add(sc.nextInt());

        Collections.sort(list);
        System.out.println("Sorted List: " + list);
    }
}
