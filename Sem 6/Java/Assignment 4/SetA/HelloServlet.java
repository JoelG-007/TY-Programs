// hello.jsp
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/hello")
public class HelloServlet extends HttpServlet{
    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.println("<h2>Welcome to Java Servlet</h2>");
    }
}
