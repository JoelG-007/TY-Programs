import java.sql.*;
import java.util.Scanner;

public class StudentCRUD{
    static Connection con;
    static Scanner sc;

    public void insert() throws Exception{
        PreparedStatement ps = con.prepareStatement("INSERT INTO student VALUES (?,?,?)");
        System.out.print("ID: ");
        ps.setInt(1, sc.nextInt());
        sc.nextLine();
        System.out.print("Name: ");
        ps.setString(2, sc.nextLine());
        System.out.print("Marks: ");
        ps.setInt(3, sc.nextInt());
        ps.executeUpdate();
        System.out.println("Inserted");
    }

    public void display() throws Exception{
        ResultSet rs = con.createStatement().executeQuery("SELECT * FROM student");
        while (rs.next())
            System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getInt(3));
    }

    public void search() throws Exception{
        System.out.print("Enter ID: ");
        int id = sc.nextInt();
        PreparedStatement ps = con.prepareStatement("SELECT * FROM student WHERE id=?");
        ps.setInt(1, id);
        ResultSet rs = ps.executeQuery();
        if (rs.next())
            System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getInt(3));
        else
            System.out.println("Not Found");
    }

    public void update() throws Exception{
        System.out.print("Enter ID: ");
        int id = sc.nextInt();
        System.out.print("New Marks: ");
        int marks = sc.nextInt();
        PreparedStatement ps = con.prepareStatement("UPDATE student SET marks=? WHERE id=?");
        ps.setInt(1, marks);
        ps.setInt(2, id);
        ps.executeUpdate();
        System.out.println("Updated");
    }

    public void delete() throws Exception{
        System.out.print("Enter ID: ");
        int id = sc.nextInt();
        PreparedStatement ps = con.prepareStatement("DELETE FROM student WHERE id=?");
        ps.setInt(1, id);
        ps.executeUpdate();
        System.out.println("Deleted");
    }

    public static void main(String[] args){
        String url = "jdbc:postgresql://192.168.0.102:5432/tycsdbXX";
        String user = "tycsXX";
        String password = "";
        try{
            Class.forName("org.postgresql.Driver");
            con = DriverManager.getConnection(url, user, password);
            sc = new Scanner(System.in);
            StudentCRUD crud = new StudentCRUD();

            while (true){
                System.out.println("\n1.Insert \n2.Display \n3.Search \n4.Update \n5.Delete \n6.Exit");
                System.out.print("Enter your choice -> ");
                int ch = sc.nextInt();
                switch (ch){
                    case 1: crud.insert(); break;
                    case 2: crud.display(); break;
                    case 3: crud.search(); break;
                    case 4: crud.update(); break;
                    case 5: crud.delete(); break;
                    case 6:{ con.close(); sc.close(); return; }
                    default: System.out.println("Option not available...");
                }
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
