import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/welcome")
public class WelcomeServlet extends HttpServlet{
    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        HttpSession session = req.getSession(false);

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();

        if(session != null && session.getAttribute("user") != null){
            String user =(String) session.getAttribute("user");
            out.println("<h2>Welcome, " + user + "!</h2>");
            out.println("<a href='logout'>Logout</a>");
        } else{
            out.println("<h3>Session expired. <a href='login.html'>Login again</a></h3>");
        }
    }
}
