import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/dispatch")
public class DispatchServlet extends HttpServlet{
    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.println("<h3>From DispatchServlet (before forward)</h3>");

        // Forward request to another servlet
        RequestDispatcher rd = req.getRequestDispatcher("/target");
        rd.forward(req, res);
    }
}
