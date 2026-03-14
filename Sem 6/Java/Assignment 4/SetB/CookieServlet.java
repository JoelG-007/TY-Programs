import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/cookie")
public class CookieServlet extends HttpServlet{
    protected void doGet(HttpServletRequest req,
                         HttpServletResponse res)
            throws ServletException, IOException{

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();

        String action = req.getParameter("action");

        if ("set".equals(action)){
            // Create and send cookie
            Cookie c = new Cookie("username", "Joel");
            c.setMaxAge(60 * 60); // 1 hour
            res.addCookie(c);
            out.println("<h3>Cookie set: username = Joel</h3>");
            out.println("<a href='cookie?action=read'>Read Cookie</a>");
        } else{
            // Read cookies from browser
            Cookie[] cookies = req.getCookies();
            if (cookies != null){
                for (Cookie c : cookies)
                    out.println("<p>" + c.getName() + " = " + c.getValue() + "</p>");
            } else{
                out.println("<h3>No cookies found</h3>");
            }
            out.println("<a href='cookie?action=set'>Set Cookie</a>");
        }
    }
}
