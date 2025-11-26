/*
a)  Write a program to accept n names of country and display them in descending order.
*/

import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class CountrySort{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of countries: ");
        int n = sc.nextInt();
        sc.nextLine();
        String[] countries = new String[n];
        System.out.println("Enter " + n + " country names:");
        for(int i = 0; i < n; i++){
            countries[i] = sc.nextLine();
        }

        // Sort in descending order
        Arrays.sort(countries, Collections.reverseOrder());
        System.out.println("\nCountries in descending order:");
        for(String c : countries){
            System.out.println(c);
        }
    }
}
