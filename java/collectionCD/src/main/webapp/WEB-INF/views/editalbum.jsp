<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core_1_1" %>
<%@ page isELIgnored="false" contentType="text/html;charset=UTF-8" %>
<%@ page import="java.util.List" %>
<%@ page import="application.models.ContryModel" %>
<%@ page import="application.models.GenreModel" %>
<%@ page import="application.models.AlbumModel" %>
<%@ page import="application.models.AuthorModel" %>
<%@ page import="java.util.Date" %>
<html>
<head>
    <title>Edit Album</title>
    <meta charset="UTF-8"/>
</head>
<body>
<h2>Edit the album</h2>
<form merhod="post" id="formdata" accept-charset="utf-8">
    <input style="display: none" id="id" value="${album.id}"/>
    <lable>Name:</lable>
    <input value="${album.name}" id="name" type="text"/></br></br>

    <lable>Tracks:</lable>
    <input value="${album.tracks}" id="tracks" type="text"/></br></br>

    <lable>Authors: </lable>
    <select id="author_id">
        <c:forEach items="${authors}" var="author">
            <option value="${author.id}" ${author.id==album.author.id ? 'selected' : ''} >${author.name} ${author.lastname}</option>
        </c:forEach>
    </select></br></br>
    <input id="save" type="submit" value="save"/>
    <a href="/">
        <input type="button" value="go to main page"/>
    </a></form>
</body>
<script src="https://code.jquery.com/jquery-3.3.1.min.js" type="application/javascript"></script>
<script type="application/javascript">
    $(document).on('click', '#save', function (e) {
        e.preventDefault();

        var arr = {
            id: $('#id').val(),
            name: $('#name').val(),
            tracks: $('#tracks').val(),
            author_id: $('#author_id option:selected').val()
        };

        $.ajax({
            cache: false,
            type: "POST",
            url: "/editalbum.jsp",
            contentType: 'application/json; charset=utf-8',
            data: JSON.stringify(arr),

            success: function () {
                console.log(arr);
            },

            error: function () {
                console.log("Error!")
            }
        })
    });
</script>
</html>
