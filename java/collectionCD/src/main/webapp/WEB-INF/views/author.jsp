<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core_1_1" %>
<%@ page isELIgnored="false" contentType="text/html;charset=UTF-8" %>
<%@ page import="java.util.List" %>
<%@ page import="application.models.ContryModel" %>
<%@ page import="application.models.GenreModel" %>
<%@ page import="application.models.AlbumModel" %>
<%@ page import="application.models.AuthorModel" %>
<html>
<head>
    <title>Author</title>
    <meta charset="UTF-8"/>
</head>
<body>
<p>Name: ${author.name}</p>
<p>Last Name: ${author.lastname}</p>
<p>Country: ${author.contry.name}</p>
<p>Genre: ${author.genre.name}</p>
<table>
    <c:forEach var="album" items="${albums}">
        <tr id="${album.id}">
            <td><a href="/album.jsp?id=${album.id}">${album.name}</a></td>
            <td>
                <a href="/editalbum.jsp?album_id=${album.id}&author_id=${author.id}">
                    <input type="button" value="Edit album"/>
                </a>
            </td>
            <td><p style="display: none">${album.id}</p>
                <button id="delete">Delete</button>
            </td>
        </tr>
    </c:forEach>
</table>
<a href="/editalbum.jsp?author_id=${author.id}">
    <input type="button" value="Add album"/>
</a>
</body>
<script src="https://code.jquery.com/jquery-3.3.1.min.js" type="application/javascript"></script>
<script type="application/javascript">
    $(document).on('click', '#delete', function (e) {
        e.preventDefault();
        var id =  $(this).prev().text();
        var button=this;
        $.ajax({
            type: "POST",
            url: "./author.jsp",
            data: id,

            success: function () {
                $(button).parents("tr").remove();
            }
        })
    });
</script>
</html>
</html>
