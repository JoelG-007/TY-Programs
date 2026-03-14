import java.util.*;

public class CollectionsMenu{
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        ArrayList<Integer> list = acceptList();
        int choice;
        do{
            displayMenu();
            choice = sc.nextInt();
            switch(choice){
                case 1 -> sortList(list);
                case 2 -> reverseList(list);
                case 3 -> swap(list);
                case 4 -> maxMin(list);
                case 5 -> search(list);
                case 6 -> frequency(list);
                case 7 -> displayList(list);
                case 0 -> System.out.println("Exiting...");
                default -> System.out.println("Invalid choice!");
            }
        } while(choice != 0);
    }

    static ArrayList<Integer> acceptList(){
        ArrayList<Integer> list = new ArrayList<>();
        System.out.print("Enter count: ");
        int n = sc.nextInt();
        System.out.println("Enter elements:");
        for(int i = 0; i < n; i++)
            list.add(sc.nextInt());
        return list;
    }

    static void displayMenu(){
        System.out.println("\n--- COLLECTIONS MENU ---");
        System.out.println("1. Sort");
        System.out.println("2. Reverse");
        System.out.println("3. Swap");
        System.out.println("4. Max & Min");
        System.out.println("5. Search");
        System.out.println("6. Frequency");
        System.out.println("7. Display List");
        System.out.println("0. Exit");
        System.out.print("Enter choice: ");
    }

    static void sortList(ArrayList<Integer> list){
        Collections.sort(list);
        System.out.println("Sorted: " + list);
    }

    static void reverseList(ArrayList<Integer> list){
        Collections.reverse(list);
        System.out.println("Reversed: " + list);
    }

    static void swap(ArrayList<Integer> list){
        System.out.print("Enter two indices to swap: ");
        int i = sc.nextInt();
        int j = sc.nextInt();
        if(i >= 0 && i < list.size() && j >= 0 && j < list.size()){
            Collections.swap(list, i, j);
            System.out.println("Swapped: " + list);
        } else{
            System.out.println("Invalid indices");
        }
    }

    static void maxMin(ArrayList<Integer> list){
        if(!list.isEmpty()){
            System.out.println("Max: " + Collections.max(list));
            System.out.println("Min: " + Collections.min(list));
        }
    }

    static void search(ArrayList<Integer> list){
        System.out.print("Enter element to search: ");
        int key = sc.nextInt();
        Collections.sort(list);
        int idx = Collections.binarySearch(list, key);
        System.out.println(idx >= 0 ? "Found at index " + idx : "Not found");
    }

    static void frequency(ArrayList<Integer> list){
        System.out.print("Enter element for frequency: ");
        int el = sc.nextInt();
        System.out.println("Frequency: " + Collections.frequency(list, el));
    }

    static void displayList(ArrayList<Integer> list){
        System.out.println("List: " + list);
    }
}
