/*
d)  Write a program to create a class product(product_id, product_name, product_cost, 
    product_quantity) define parameterized constructor. Create objects of class product 
    and give the 10% discount if product cost is more than 1000 rs and display all product 
    details and Also display the object count. (Note : Create multiple object of Product 
    class and count the objects and display it.)
*/

class Product{
    int product_id;
    String product_name;
    double product_cost;
    int product_quantity;
    static int count = 0;

    Product(int id, String name, double cost, int qty){
        this.product_id = id;
        this.product_name = name;
        this.product_cost = cost;
        this.product_quantity = qty;
        count++;
    }

    void applyDiscount(){
        if(product_cost > 1000){
            product_cost = product_cost - (product_cost * 0.10);
        }
    }

    void display(){
        System.out.println("Product ID: " + product_id);
        System.out.println("Name: " + product_name);
        System.out.println("Cost: Rs. " + product_cost);
        System.out.println("Quantity: " + product_quantity);
        System.out.println("-------------------------");
    }

    static void showCount(){
        System.out.println("Total products created: " + count);
    }
}

public class ProductDemo{
    public static void main(String[] args){
        Product p1 = new Product(101, "Monitor", 1500, 2);
        Product p2 = new Product(102, "Keyboard", 800, 5);
        Product p3 = new Product(103, "Mouse", 1200, 10);

        Product[] products = {p1, p2, p3};

        for(Product p : products){
            p.applyDiscount();
            p.display();
        }

        Product.showCount();
    }
}
