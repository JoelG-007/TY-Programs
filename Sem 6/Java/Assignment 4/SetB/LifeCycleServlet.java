import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/lifecycle")
public class LifeCycleServlet extends HttpServlet{

    public void init(){
        System.out.println("Servlet Initialized");
    }

    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.println("<h3>Service Method Executed</h3>");
    }

    public void destroy(){
        System.out.println("Servlet Destroyed");
    }
}
