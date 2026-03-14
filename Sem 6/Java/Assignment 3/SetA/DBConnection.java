import java.sql.*;

public class DBConnection{
    public static void main(String[] args){
        String url = "jdbc:postgresql://192.168.0.102:5432/tycsdbXX";
        String user = "tycsXX";
        String password = "";
        try{
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection(url, user, password);
            System.out.println("Database Connected Successfully");
            con.close();
        }catch (ClassNotFoundException | SQLException e) {
            System.out.println(e);
        }
    }
}
