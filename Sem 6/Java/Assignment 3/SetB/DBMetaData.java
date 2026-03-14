import java.sql.*;

public class DBMetaData{
    public static void main(String[] args){
        String url = "jdbc:postgresql://192.168.0.102:5432/tycsdbXX";
        String user = "tycsXX";
        String password = "";
        try{
            Connection con = DriverManager.getConnection(url, user, password);
            DatabaseMetaData db = con.getMetaData();

            System.out.println("DB Name: " + db.getDatabaseProductName());
            System.out.println("DB Version: " + db.getDatabaseProductVersion());
            System.out.println("Driver Name: " + db.getDriverName());
            System.out.println("User Name: " + db.getUserName());

            con.close();
        }catch (Exception e){
            System.out.println(e);
        }
    }
}
