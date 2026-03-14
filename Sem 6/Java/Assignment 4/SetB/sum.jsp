<%@ page language="java" contentType="text/html" %>
<html>
<head><title>Sum Calculator</title></head>
<body>

<%
    String a = request.getParameter("num1");
    String b = request.getParameter("num2");

    if(a != null && b != null){
        int num1 = Integer.parseInt(a);
        int num2 = Integer.parseInt(b);
        int sum = num1 + num2;
%>
        <h3>Sum of <%= num1 %> and <%= num2 %> = <%= sum %></h3>
<%
    }else{
%>
        <form action="sum.jsp" method="get">
            Number 1: <input type="text" name="num1"><br><br>
            Number 2: <input type="text" name="num2"><br><br>
            <input type="submit" value="Calculate">
        </form>
<%
    }
%>

</body>
</html>
