/*
b)  Write a java program to accept 5 numbers using command line arguments sort and 
    display them. 
*/
import java.util.Arrays;
public class SortNumbers{
    public static void main(String[] args){
        if (args.length < 5){
            System.out.println("Please enter 5 numbers as command line arguments.");
            return;
        }

        int[] numbers = new int[args.length];

        for (int i = 0; i < args.length; i++){
            numbers[i] = Integer.parseInt(args[i]);
        }

        Arrays.sort(numbers);

        System.out.println("Sorted numbers:");
        for (int n : numbers){
            System.out.print(n + " ");
        }
    }
}
