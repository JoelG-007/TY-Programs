/*
b)  Write a program to using marker interface create a class product(product_id, 
    product_name, product_cost, product_quantity) define a default and parameterized 
    constructor. Create objects of class product and display the contents of each object 
    and Also display the object count. 
*/

interface Marker {}   // marker interface (empty)

class Product implements Marker{
    int product_id;
    String product_name;
    double product_cost;
    int product_quantity;
    static int count = 0;

    // Default constructor
    Product(){
        count++;
    }

    // Parameterized constructor
    Product(int id, String name, double cost, int qty){
        product_id = id;
        product_name = name;
        product_cost = cost;
        product_quantity = qty;
        count++;
    }

    void display(){
        System.out.println("Product ID: " + product_id);
        System.out.println("Product Name: " + product_name);
        System.out.println("Product Cost: " + product_cost);
        System.out.println("Product Quantity: " + product_quantity);
        System.out.println("----------------------------");
    }

    static void showCount(){
        System.out.println("Total objects created: " + count);
    }
}

public class ProductMarker{
    public static void main(String[] args){
        Product p1 = new Product(101, "Mouse", 500, 2);
        Product p2 = new Product(102, "Keyboard", 1500, 3);
        Product p3 = new Product();  // using default constructor

        p1.display();
        p2.display();
        p3.display();

        Product.showCount();
    }
}
