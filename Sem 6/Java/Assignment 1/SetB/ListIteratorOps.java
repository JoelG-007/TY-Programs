import java.util.*;

public class ListIteratorOps{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();

        System.out.print("Enter count: ");
        int n = sc.nextInt();

        System.out.println("Enter " + n + " elements:");
        for(int i = 0; i < n; i++)
            list.add(sc.nextInt());

        Iterator<Integer> it = list.iterator();
        int le = 0, gt = 0;

        while(it.hasNext()){
            int x = it.next();
            if(x <= 20)
                le++;
            else{
                gt++;
                it.remove();
            }
        }

        System.out.println("=======================");
        System.out.println("<=20: " + le);
        System.out.println(">20 removed: " + gt);
        System.out.println("Max: " + Collections.max(list));
        System.out.println("Min: " + Collections.min(list));
        System.out.println("Final List: " + list);
    }
}
