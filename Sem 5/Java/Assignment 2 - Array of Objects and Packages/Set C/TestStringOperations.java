/*
a)  Write a package for String operation which has two classes Con and Comp. Con class 
    has to concatenate two strings and comp class compares two strings. Also display 
    proper message on execution. 
*/
import stringoperations.*;
public class TestStringOperations{
    public static void main(String[] args){
        Concat con = new Concat();
        Compare cmp = new Compare();

        con.concatenate("Hello", "World");
        cmp.compare("Java", "Java");
        cmp.compare("Hello", "World");
    }
}
