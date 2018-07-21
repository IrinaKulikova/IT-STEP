<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core_1_1" %>
<%@ page isELIgnored="false" contentType="text/html;charset=UTF-8" %>
<%@ page import="java.util.List" %>
<%@ page import="application.models.ContryModel" %>
<%@ page import="application.models.GenreModel" %>
<%@ page import="application.models.AlbumModel" %>
<%@ page import="application.models.AuthorModel" %>
<html>
<head>
    <title>Album</title>
    <meta charset="UTF-8"/>
</head>
<body>
<p> Name of album: ${album.name}</p>
<p> Author's name: ${album.author.name} ${aibum.author.lastname}</p>
<p> Genre: ${album.author.genre.name}</p>
<p> Count of tracks: ${album.tracks}</p>

<a href="/">
    <input type="button" value="go to main page"/>
</a>
</body>
</html>