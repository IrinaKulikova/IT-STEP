<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core_1_1" %>
<%@ page isELIgnored="false" contentType="text/html;charset=UTF-8" %>
<%@ page import="java.util.List" %>
<%@ page import="application.models.ContryModel" %>
<%@ page import="application.models.GenreModel" %>
<%@ page import="application.models.AlbumModel" %>
<%@ page import="application.models.AuthorModel" %>
<html>
<head>
    <title>author</title>
    <meta charset="UTF-8"/>
</head>
<body>
<h2>Add or edit author</h2>
<form merhod="post" id="formdata" accept-charset="utf-8">
    <input style="display: none" id="id" value="${author.id}"/>
    <lable>Name:</lable>
    <input value="${author.name}" id="name" type="text"/></br></br>

    <lable>Last Name:</lable>
    <input value="${author.lastname}" id="lastname" type="text"/></br></br>

    <lable>Genre:</lable>
    <select id="genre_id">
        <c:forEach items="${genres}" var="genre">
            <option value="${genre.id}" ${author.genre.id==genre.id ? 'selected' : ''} >${genre.name}</option>
        </c:forEach>
    </select></br></br>
    <lable>Contry:</lable>
    <select id="contry_id">
        <c:forEach items="${contries}" var="contry">
            <option value="${contry.id}" ${author.contry.id==contry.id ? 'selected' : ''} >${contry.name}</option>
        </c:forEach>
    </select></br></br>
    <input id="save" type="submit" value="save"/>
    <a href="/">
        <input type="button" value="go to main page"/>
    </a>
</form>
</body>
<script src="https://code.jquery.com/jquery-3.3.1.min.js" type="application/javascript"></script>
<script type="application/javascript">
    $(document).on('click', '#save', function (e) {
        e.preventDefault();

        var arr = {
            id: $('#id').val(),
            name: $('#name').val(),
            lastname: $('#lastname').val(),
            genre_id: $('#genre_id option:selected').val(),
            contry_id: $('#contry_id option:selected').val()
        };

        console.log(arr);
        $.ajax({
            cache: false,
            type: "POST",
            url: "/editauthor.jsp",
            contentType: 'application/json; charset=utf-8',
            data: JSON.stringify(arr),
            success: function () {
                console.log("Successfully!");
            },

            error: function () {
                console.log("Error!")
            }
        })
    });
</script>
</html>
