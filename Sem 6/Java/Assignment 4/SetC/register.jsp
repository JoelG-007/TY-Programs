<%@ page language="java" contentType="text/html" %>
<%@ page import="java.sql.*" %>
<html>
<head><title>Student Registration</title></head>
<body>

<%
    String id = request.getParameter("id");
    String name = request.getParameter("name");
    String marks = request.getParameter("marks");

    if (id != null && name != null && marks != null) {
        String url = "jdbc:postgresql://192.168.0.102:5432/tycsdb52";
        String user = "tycs52";
        String password = "";
        try {
            Connection con = DriverManager.getConnection(url, user, password);
            PreparedStatement ps = con.prepareStatement("INSERT INTO student VALUES (?,?,?)");
            ps.setInt(1, Integer.parseInt(id));
            ps.setString(2, name);
            ps.setInt(3, Integer.parseInt(marks));
            ps.executeUpdate();
            con.close();
%>
            <h3>Student registered successfully!</h3>
            <a href="register.jsp">Register another</a>
<%
        } catch (Exception e) {
%>
            <p>Error: <%= e.getMessage() %></p>
<%
        }
    } else {
%>
    <h2>Student Registration</h2>
    <form action="register.jsp" method="post">
        ID: <input type="text" name="id"><br><br>
        Name: <input type="text" name="name"><br><br>
        Marks: <input type="text" name="marks"><br><br>
        <input type="submit" value="Register">
    </form>
<%
    }
%>

</body>
</html>
