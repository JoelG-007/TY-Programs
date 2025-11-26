/*
c)  Write a program to display the 1 to 15 tables. 
*/

public class Tables1to15{
    public static void main(String[] args){
        for(int i = 1; i <= 15; i++){
            System.out.println("\n--- Table of " + i + " ---");
            for(int j = 1; j <= 10; j++) {
                System.out.println(i + " x " + j + " = " + (i * j));
            }
        }
    }
}
