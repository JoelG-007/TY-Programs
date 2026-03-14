// index.html
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/greet")
public class GreetServlet extends HttpServlet{
    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        String name = req.getParameter("uname");

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.println("<h3>Welcome " + name + "</h3>");
    }
}
