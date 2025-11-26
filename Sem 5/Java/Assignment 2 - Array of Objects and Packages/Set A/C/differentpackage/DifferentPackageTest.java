package differentpackage;
import samepackage.Customer;

public class DifferentPackageTest extends Customer{
    public static void main(String[] args){
        Customer c = new Customer();
        System.out.println("Accessing from DIFFERENT package:");
        System.out.println(c.name);  // public accessible
        // System.out.println(c.accountNumber); // private -> not accessible
        // System.out.println(c.phone); // default -> not accessible

        // Protected accessible only through subclass
        DifferentPackageTest obj = new DifferentPackageTest();
        System.out.println(obj.email); // accessible via inheritance
    }
}
