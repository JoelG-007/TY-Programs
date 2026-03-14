import java.sql.*;

public class DisplayRecords{
    public static void main(String[] args){
        String url = "jdbc:postgresql://192.168.0.102:5432/tycsdbXX";
        String user = "tycsXX";
        String password = "";
        try{
            Connection con = DriverManager.getConnection(url, user, password);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM student");

            System.out.println("ID\tName\tMarks");
            while(rs.next()){
                System.out.println(
                    rs.getInt(1) + "\t" +
                    rs.getString(2) + "\t" +
                    rs.getInt(3)
                );
            }

            rs.close();
            stmt.close();
            con.close();
        }catch(Exception e){
            System.out.println(e);
        }
    }
}
