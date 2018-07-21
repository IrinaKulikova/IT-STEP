<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core_1_1" %>
<%@ page isELIgnored="false" contentType="text/html;charset=UTF-8" %>
<%@ page import="java.util.List" %>
<%@ page import="application.models.ContryModel" %>
<%@ page import="application.models.GenreModel" %>
<%@ page import="application.models.AlbumModel" %>
<%@ page import="application.models.AuthorModel" %>
<html>
<head>
    <title>Collections</title>
    <meta charset="UTF-8"/>
</head>
<body>
<h2>List authors</h2>
<c:if test="${authors!=null}">
    <table>
        <th>Name</th>
        <th></th>
        <th></th>
        <c:forEach var="author" items="${authors}">
            <tr>
                <td><a href="/author.jsp?id=${author.id}">${author.name} ${author.lastname}</a></td>
                <td>
                    <a href="/editauthor.jsp?id=${author.id}">
                        <input type="button" value="Edit author"/>
                    </a>
                </td>
                <td><p style="display: none">${author.id}</p>
                    <button id="delete" value="delete">Delete</button>
                </td>
            </tr>
        </c:forEach>
    </table>
</c:if>
<a href="/editauthor.jsp?=0">
    <input type="button" value="Add author"/>
</a>
</body>
<script src="https://code.jquery.com/jquery-3.3.1.min.js" type="application/javascript"></script>
<script type="application/javascript">
    $(document).on('click', '#delete', function (e) {
        e.preventDefault();
        var id = $(this).prev().text();
        var button=this;
        $.ajax({
            type: "POST",
            url: "/",
            data: id,

            success: function () {
                console.log("Successfully!");
                $(button).parents("tr").remove();
            },

            error: function () {
                console.log("Error!")
            }
        })
    });
</script>
</html>
