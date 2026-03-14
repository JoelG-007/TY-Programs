import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/userinfo")
public class UserInfoServlet extends HttpServlet{
    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        String name = req.getParameter("name");
        String age = req.getParameter("age");

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.println("<h3>Name: " + name + "</h3>");
        out.println("<h3>Age: " + age + "</h3>");
    }
}
