import java.sql.*;
import java.util.Scanner;

public class PreparedInsert{
    public static void main(String[] args){
        String url = "jdbc:postgresql://192.168.0.102:5432/tycsdbXX";
        String user = "tycsXX";
        String password = "";
        try{
            Scanner sc = new Scanner(System.in);
            Connection con = DriverManager.getConnection(url, user, password);

            String sql = "INSERT INTO student VALUES (?,?,?)";
            PreparedStatement ps = con.prepareStatement(sql);

            System.out.print("Enter ID: ");
            ps.setInt(1, sc.nextInt());

            sc.nextLine();
            System.out.print("Enter Name: ");
            ps.setString(2, sc.nextLine());

            System.out.print("Enter Marks: ");
            ps.setInt(3, sc.nextInt());

            int status = ps.executeUpdate();
            if (status > 0)
                System.out.println("Record Inserted");
            else
                System.out.println("Failed to insert");

            ps.close();
            con.close();
        }catch (Exception e){
            System.out.println(e);
        }
    }
}
