/*
a)  Write a java program to display the system date and time in various formats shown below: 
    Current date is : 31/08/2021 
    Current date is : 08-31-2021 
    Current date is : Tuesday August 31 2021 
    Current date and time is : Fri August 31 15:25:59 IST 2021 
    Current date and time is : 31/08/21 15:25:59 PM +0530 
    Current time is : 15:25:59 
    Current week of year is : 35 
    Current week of month : 5 
    Current day of the year is : 243 
    Note: Use java.util.Date and java.text.SimpleDateFormat class
*/

import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class DateTimeFormats {
    public static void main(String[] args) {
        Date now = new Date();

        // Different date formats
        SimpleDateFormat f1 = new SimpleDateFormat("dd/MM/yyyy");
        SimpleDateFormat f2 = new SimpleDateFormat("MM-dd-yyyy");
        SimpleDateFormat f3 = new SimpleDateFormat("EEEE MMMM dd yyyy");
        SimpleDateFormat f4 = new SimpleDateFormat("EEE MMMM dd HH:mm:ss z yyyy");
        SimpleDateFormat f5 = new SimpleDateFormat("dd/MM/yy HH:mm:ss a Z");
        SimpleDateFormat f6 = new SimpleDateFormat("HH:mm:ss");

        System.out.println("Current date is : " + f1.format(now));
        System.out.println("Current date is : " + f2.format(now));
        System.out.println("Current date is : " + f3.format(now));
        System.out.println("Current date and time is : " + f4.format(now));
        System.out.println("Current date and time is : " + f5.format(now));
        System.out.println("Current time is : " + f6.format(now));

        // Using Calendar for week/day info
        Calendar cal = Calendar.getInstance();
        System.out.println("Current week of year is : " + cal.get(Calendar.WEEK_OF_YEAR));
        System.out.println("Current week of month : " + cal.get(Calendar.WEEK_OF_MONTH));
        System.out.println("Current day of the year is : " + cal.get(Calendar.DAY_OF_YEAR));
    }
}
