import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/students")
public class StudentServlet extends HttpServlet{
    static final String URL = "jdbc:postgresql://192.168.0.102:5432/tycsdb52";
    static final String USER = "tycs52";
    static final String PASSWORD = "";

    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();

        out.println("<h2>Student Records</h2>");
        out.println("<table border='1'><tr><th>ID</th><th>Name</th><th>Marks</th></tr>");

        try{
            Connection con = DriverManager.getConnection(URL, USER, PASSWORD);
            ResultSet rs = con.createStatement().executeQuery("SELECT * FROM student");
            while(rs.next())
                out.println("<tr><td>" + rs.getInt(1) + "</td><td>" +
                    rs.getString(2) + "</td><td>" + rs.getInt(3) + "</td></tr>");
            con.close();
        } catch(Exception e){
            out.println("<p>Error: " + e.getMessage() + "</p>");
        }

        out.println("</table>");
        out.println("<br><a href='addStudent.html'>Add Student</a>");
    }

    protected void doPost(HttpServletRequest req,
                          HttpServletResponse res)
            throws ServletException, IOException{

        int id = Integer.parseInt(req.getParameter("id"));
        String name = req.getParameter("name");
        int marks = Integer.parseInt(req.getParameter("marks"));

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();

        try{
            Connection con = DriverManager.getConnection(URL, USER, PASSWORD);
            PreparedStatement ps = con.prepareStatement("INSERT INTO student VALUES(?,?,?)");
            ps.setInt(1, id);
            ps.setString(2, name);
            ps.setInt(3, marks);
            ps.executeUpdate();
            con.close();
            out.println("<h3>Student added successfully!</h3>");
            out.println("<a href='students'>View All</a>");
        } catch(Exception e){
            out.println("<p>Error: " + e.getMessage() + "</p>");
        }
    }
}
