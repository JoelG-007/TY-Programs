/*
a)  Write a program to read book information (bookid, bookname, bookprice, bookqty) in 
    file “book.dat”. Write a menu driven program to perform the following operations 
    using Random access file: 
        i. Search for a specific book by name. 
        ii. Display all book and total cost 
*/

import java.io.*;
import java.util.Scanner;

class Book{
    int id, qty;
    String name;
    double price;

    Book(int id, String name, double price, int qty){
        this.id = id;
        this.name = name;
        this.price = price;
        this.qty = qty;
    }
}

public class BookRandomAccess{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        File file = new File("book.dat");

        try(RandomAccessFile raf = new RandomAccessFile(file, "rw")){
            int choice;
            do{
                System.out.println("\n=== MENU ===");
                System.out.println("1. Add Book Records");
                System.out.println("2. Search Book by Name");
                System.out.println("3. Display All Books and Total Cost");
                System.out.println("4. Exit");
                System.out.print("Enter your choice: ");
                choice = sc.nextInt();
                sc.nextLine();

                switch(choice){
                    case 1:
                        System.out.print("Enter Book ID: ");
                        int id = sc.nextInt();
                        sc.nextLine();
                        System.out.print("Enter Book Name: ");
                        String name = sc.nextLine();
                        System.out.print("Enter Book Price: ");
                        double price = sc.nextDouble();
                        System.out.print("Enter Quantity: ");
                        int qty = sc.nextInt();

                        raf.seek(raf.length());
                        raf.writeInt(id);
                        raf.writeUTF(name);
                        raf.writeDouble(price);
                        raf.writeInt(qty);
                        System.out.println("Book Added!");
                        break;

                    case 2:
                        System.out.print("Enter Book Name to Search: ");
                        String searchName = sc.nextLine();
                        raf.seek(0);
                        boolean found = false;

                        while(raf.getFilePointer() < raf.length()){
                            int bid = raf.readInt();
                            String bname = raf.readUTF();
                            double bprice = raf.readDouble();
                            int bqty = raf.readInt();

                            if(bname.equalsIgnoreCase(searchName)){
                                System.out.println("Book Found!");
                                System.out.println("ID: " + bid + ", Name: " + bname +
                                        ", Price: " + bprice + ", Quantity: " + bqty);
                                found = true;
                            }
                        }
                        if(!found) System.out.println("Book not found!");
                        break;

                    case 3:
                        raf.seek(0);
                        double total = 0;
                        System.out.println("\n--- Book List ---");
                        while(raf.getFilePointer() < raf.length()){
                            int bid = raf.readInt();
                            String bname = raf.readUTF();
                            double bprice = raf.readDouble();
                            int bqty = raf.readInt();

                            System.out.println("ID: " + bid + ", Name: " + bname +
                                    ", Price: " + bprice + ", Quantity: " + bqty);
                            total += (bprice * bqty);
                        }
                        System.out.println("Total Cost of all Books: " + total);
                        break;

                    case 4:
                        System.out.println("Exiting...");
                        break;

                    default:
                        System.out.println("Invalid choice!");
                }

            }while(choice != 4);
        }catch (IOException e){
            System.out.println("Error: " + e.getMessage());
        }
    }
}
