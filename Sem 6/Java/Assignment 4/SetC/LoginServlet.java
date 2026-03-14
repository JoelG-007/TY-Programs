import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/login")
public class LoginServlet extends HttpServlet{
    protected void doPost(HttpServletRequest req,
                          HttpServletResponse res)
            throws ServletException, IOException{

        String username = req.getParameter("username");
        String password = req.getParameter("password");

        res.setContentType("text/html");
        PrintWriter out = res.getWriter();

        if("admin".equals(username) && "1234".equals(password)){
            HttpSession session = req.getSession();
            session.setAttribute("user", username);
            res.sendRedirect("welcome");
        } else{
            out.println("<h3>Invalid credentials. <a href='login.html'>Try again</a></h3>");
        }
    }
}
