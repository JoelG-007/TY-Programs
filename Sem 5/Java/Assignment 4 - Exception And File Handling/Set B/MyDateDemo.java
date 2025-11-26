/*
c)  Define a class MyDate (day, month, year) with methods to accept and display a 
    MyDate object. Accept date as dd, mm, yyyy. Throw user defined exception 
    “InvalidDateException” if the date is invalid. 
        Examples of invalid dates : 03 15 2019, 31 6 2000, 29 2 2021
*/

import java.util.Scanner;

class InvalidDateException extends Exception{
    InvalidDateException(String msg){
        super(msg);
    }
}

class MyDate{
    int day, month, year;

    void accept() throws InvalidDateException{
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter day: ");
        day = sc.nextInt();
        System.out.print("Enter month: ");
        month = sc.nextInt();
        System.out.print("Enter year: ");
        year = sc.nextInt();

        if(!isValidDate(day, month, year)){
            throw new InvalidDateException("Invalid Date!");
        }
    }

    boolean isValidDate(int d, int m, int y){
        if (m < 1 || m > 12) return false;
        if (d < 1) return false;

        int[] days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
            days[1] = 29; // leap year
        }

        return d <= days[m - 1];
    }

    void display(){
        System.out.println("Date: " + day + "/" + month + "/" + year);
    }
}

public class MyDateDemo{
    public static void main(String[] args){
        MyDate date = new MyDate();
        try{
            date.accept();
            date.display();
        } catch (InvalidDateException e) {
            System.out.println(e.getMessage());
        }
    }
}
