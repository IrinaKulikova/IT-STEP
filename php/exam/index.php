<!DOCTYPE html>
<!-- saved from url=(0028)http://127.0.0.1:8000/users/ -->
<html lang="en" class="fa-events-icons-ready">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Test for you</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./index_files/style.css">
    <script src="./index_files/8176bbfa2c.js"></script>
    <link href="./index_files/8176bbfa2c.css" media="all" rel="stylesheet">
    <script src="./index_files/jquery.min.js"></script>
    <script src="./index_files/jquery.validate.min.js"></script>
    <script src="./index_files/additional-methods.min.js"></script>
    <script src="./index_files/scrypt.js"></script>
</head>
<body>
<nav>
    <div class="navbar">
        <h2 class="logo"><a href="index.php">Test for You</a></h2>
        <ul class="nav right">
            <li><a href="index.php" class="active">Users</a></li>
            <li><a href="">Courses</a></li>
        </ul>
    </div>
</nav>
<div class="container">
    <a href="create_user.php" class="btn-add">+</a>
    <form class="search" method="post" action="index.php?paginate_by=5" novalidate="novalidate">
        <input type="hidden" name="csrfmiddlewaretoken"
               value="IqVdgjQAImzx7Ot7Q7cL44RZZwMvMgaxYqhRd4rqMs7WLDaiSp9AOKV6WuOxQix1">
        <button class="btn-search" type="submit"><i class="fa fa-search" aria-hidden="true"></i></button>
        <input id="search" placeholder="Username" value="" type="search" name="user" list="users">
        <datalist id="users">
        </datalist>
    </form>
    <select class="how-many">
        <option>3</option>
        <option selected="">5</option>
        <option>10</option>
    </select>
    <h1>Users</h1>
    <table>
        <colgroup>
            <col>
            <col>
            <col>
            <col>
        </colgroup>
        <thead>
        <tr>
            <th>Name</th>
            <th>E-mail</th>
            <th>Status</th>
            <th>Action</th>
        </tr>
        </thead>
        <tbody>
        <?php
        include_once 'db/load.php';
        ?>
        </tbody>
    </table>
    <div>
        <ul class="paginator">
            <li><a id="left" class="done"><i class="fa fa-angle-left fa-2x"></i></a></li>
            <li><a href="" class="current">1</a></li>
            <li><a href="">2</a></li>
            <li><a href="">3</a></li>
            <li><a id="rigth" href="#" class="next"><i class="fa fa-angle-right fa-2x"></i></a></li>
        </ul>
    </div>
</div>
</body>
</html>

<script type="text/javascript">
    $(document).ready(function (e) {

        //ajax поиск по имени и фамилии
        $('#search').keyup(function () {
            if ($("#search").val() == 0) {
                return;
            }
            $.ajax({
                type: 'post',
                url: "db/search.php", //Путь к обработчику
                data: {'search': $("#search").val()},
                response: 'text',
                success: function (data) {
                    $('.searchuser').remove();
                    if (data != false) {
                        for (var i = 0; i < data.length; i++) {
                            var user = $('<option></option>').addClass('searchuser').text(data[i]['name'] + " " + data[i]['surname']);
                            $('#users').append(user);
                        }
                    }
                }
            })
            return false;
        })
    });
</script>