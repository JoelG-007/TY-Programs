import java.util.*;

public class MapDemo{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        Map<String, Integer> map = new HashMap<>();

        System.out.print("Enter number of entries: ");
        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++){
            System.out.print("Enter name: ");
            String key = sc.nextLine();
            System.out.print("Enter value: ");
            int value = sc.nextInt();
            sc.nextLine();
            map.put(key, value);
        }

        System.out.println("\nUsing for-each(Map.Entry):");
        for(Map.Entry<String, Integer> e : map.entrySet())
            System.out.println(e.getKey() + " = " + e.getValue());

        System.out.println("\nUsing Iterator:");
        Iterator<Map.Entry<String, Integer>> it = map.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry<String, Integer> e = it.next();
            System.out.println(e.getKey() + " = " + e.getValue());
        }
    }
}
