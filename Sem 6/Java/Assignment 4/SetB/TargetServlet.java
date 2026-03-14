import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/target")
public class TargetServlet extends HttpServlet{
    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.println("<h3>Response from TargetServlet (forwarded here)</h3>");
    }
}
