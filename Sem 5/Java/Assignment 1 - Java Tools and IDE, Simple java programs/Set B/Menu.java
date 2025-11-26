/*
b) Write a menu driven program to perform the following operations 
   a.Calculate the volume of cylinder. (hint : Volume: π × r² × h) 
   b.Find the factorial of given number. 
   c.Check the number is Armstrong or not. 
   d.Exit 
*/

import java.util.Scanner;
public class Menu{
   double pi = 3.14;

   public Menu(){ // default constructor
   }

   public double volume(int radius, int height){
      return this.pi * (double)radius * (double)radius * (double)height;
   }

   public int factorial(int n){
      int fact = 1;

      for(int i = 1; i < n + 1; ++i){
         fact *= i;
      }

      return fact;
   }

   public boolean armstrongCheck(int num){
      int sum = 0;
      int original = num;

      int i;
      for(i = 0; original > 0; original /= 10){
         ++i;
      }

      for(original = num; original > 0; original /= 10){
         int var6 = original % 10;
         int var7 = (int)Math.pow((double)var6, (double)i);
         sum += var7;
      }
      System.out.println("sum of digits are" + sum);
      return sum == num;
   }

   public static void main(String[] var0){
      Scanner sc = new Scanner(System.in);
      Menu menu = new Menu();

      int op;
      do{
         System.out.println(" Menu \n1. Volume \n2. Factorial \n3. Armstrong number \n4. Exit\n");
         System.out.println("Enter your choice - ");
         op = sc.nextInt();
         switch(op){
            case 1:
               System.out.println("Enter radius - ");
               int radius = sc.nextInt();
               System.out.println("Enter Height - ");
               int height = sc.nextInt();
               System.out.println("Volume is " + menu.volume(radius, height));
               break;
            case 2:
               System.out.println("Enter number - ");
               int n = sc.nextInt();
               System.out.println("Factorial is " + menu.factorial(n));
               break;
            case 3:
               System.out.println("Enter number - ");
               int num = sc.nextInt();
               System.out.println("Armstrong number is " + menu.armstrongCheck(num));
         }
      }while(op != 4);
   }
}
