/*
a)  Create an abstract class “order” having members id,description.Create two 
    subclasses “Purchase Order” and “Sales Order” having members customer name 
    and Vendor name respectively.Define methods accept and display in all cases. 
    Create 3 objects each of Purchase Order and Sales Order and accept and display 
    details. 
*/

import java.util.Scanner;

abstract class Order{
    int id;
    String description;

    // abstract methods
    abstract void accept();
    abstract void display();
}

class PurchaseOrder extends Order{
    String customerName;

    void accept(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Purchase Order ID: ");
        id = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter Description: ");
        description = sc.nextLine();
        System.out.print("Enter Customer Name: ");
        customerName = sc.nextLine();
    }

    void display(){
        System.out.println("\nPurchase Order Details:");
        System.out.println("ID: " + id);
        System.out.println("Description: " + description);
        System.out.println("Customer Name: " + customerName);
    }
}

class SalesOrder extends Order{
    String vendorName;

    void accept(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Sales Order ID: ");
        id = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter Description: ");
        description = sc.nextLine();
        System.out.print("Enter Vendor Name: ");
        vendorName = sc.nextLine();
    }

    void display(){
        System.out.println("\nSales Order Details:");
        System.out.println("ID: " + id);
        System.out.println("Description: " + description);
        System.out.println("Vendor Name: " + vendorName);
    }
}

public class OrderDemo{
    public static void main(String[] args){
        PurchaseOrder[] p = new PurchaseOrder[3];
        SalesOrder[] s = new SalesOrder[3];

        System.out.println("=== Enter Purchase Orders ===");
        for(int i = 0; i < 3; i++) {
            p[i] = new PurchaseOrder();
            p[i].accept();
        }

        System.out.println("\n=== Enter Sales Orders ===");
        for(int i = 0; i < 3; i++) {
            s[i] = new SalesOrder();
            s[i].accept();
        }

        System.out.println("\n--- Purchase Orders ---");
        for(PurchaseOrder po : p)
            po.display();

        System.out.println("\n--- Sales Orders ---");
        for(SalesOrder so : s)
            so.display();
    }
}
