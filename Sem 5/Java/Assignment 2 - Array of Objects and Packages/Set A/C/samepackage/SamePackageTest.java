package samepackage;

public class SamePackageTest{
    public static void main(String[] args) {
        Customer c = new Customer();
        System.out.println("Accessing from SAME package:");
        System.out.println(c.name);      // public
        // System.out.println(c.accountNumber); // private -> not accessible
        System.out.println(c.email);     // protected
        System.out.println(c.phone);     // default
    }
}
