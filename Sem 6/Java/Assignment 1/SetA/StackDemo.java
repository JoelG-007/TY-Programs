import java.util.*;

public class StackDemo{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        for(int i = 0; i < n; i++)
            stack.push(sc.nextInt());

        System.out.println("Stack: " + stack);
        System.out.println("Popped Element: " + stack.pop());
        System.out.println("After Pop: " + stack);
    }
}
