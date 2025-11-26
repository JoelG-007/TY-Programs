/*
c)  Define a class MyNumber having one private int data member. Write a default 
    constructor to initialize it to 0 and another constructor to initialize it to a value 
    (Use this). Write methods isNegative, isPositive, isZero, isOdd, isEven. Create an 
    object in main. Use command line arguments to pass a value to the object 
    (Hint : convert string argument to integer) and perform the above tests. 
    Provide javadoc comments for all constructors and methods and generate the html help file.
 */

public class MyNumber{              // Class definition 
    private int num;

    public MyNumber(){              // Default constructor
        this.num = 0;
    }

    public MyNumber(int num){       // Parameterized constructor
        this.num = num;
    }

    public boolean isNegative(){    // Check if the number is negative
        return num < 0;
    }

    public boolean isPositive(){    // Check if the number is positive
        return num > 0;
    }

    public boolean isZero(){        // Check if the number is zero
        return num == 0;
    }

    public boolean isOdd(){         // Check if the number is odd
        return num % 2 != 0;
    }

    public boolean isEven(){        // Check if the number is even
        return num % 2 == 0;
    }

    public static void main(String[] args){ // Main method
        if(args.length > 0){
            int n = Integer.parseInt(args[0]);
            MyNumber obj = new MyNumber(n);

            System.out.println("Number: " + n);
            System.out.println("isNegative? " + obj.isNegative());
            System.out.println("isPositive? " + obj.isPositive());
            System.out.println("isZero? " + obj.isZero());
            System.out.println("isOdd? " + obj.isOdd());
            System.out.println("isEven? " + obj.isEven());
        }else{
            System.out.println("Insufficient arguments! Pass a number.");
        }
    }
}

/*
Generate Javadoc HTML:
    javadoc MyNumber.java
*/