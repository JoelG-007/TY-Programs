import java.sql.*;

public class CreateInsert{
    public static void main(String[] args){
        String url = "jdbc:postgresql://192.168.0.102:5432/tycsdbXX";
        String user = "tycsXX";
        String password = "";
        try{
            Connection con = DriverManager.getConnection(url, user, password);
            Statement stmt = con.createStatement();

            stmt.execute(
                "CREATE TABLE IF NOT EXISTS student(" +
                "id INT PRIMARY KEY, name VARCHAR(30), marks INT)"
            );

            stmt.executeUpdate(
                "INSERT INTO student VALUES (5,'Kishor',85)," +
                "(6,'Yash',90),(7,'Shashank',78)"
            );

            System.out.println("Table created & records inserted");
            stmt.close();
            con.close();
        }catch (SQLException e){
            System.out.println(e);
        }
    }
}
