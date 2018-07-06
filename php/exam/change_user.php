<!DOCTYPE html>
<!-- saved from url=(0034)http://127.0.0.1:8000/users/edit/5 -->
<html lang="en" class="fa-events-icons-ready">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Test for you</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./inc_files/style.css">
    <script src="./inc_files/8176bbfa2c.js.Без названия"></script>
    <link href="./inc_files/8176bbfa2c.css" media="all" rel="stylesheet">
    <script src="./inc_files/jquery.min.js.Без названия"></script>
    <script src="./inc_files/jquery.validate.min.js.Без названия"></script>
    <script src="./inc_files/additional-methods.min.js.Без названия"></script>
    <script src="./inc_files/scrypt.js.Без названия"></script>
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
<div class="container" style="position: relative">
    <a href="index.php" class="btn-back"><i class="fa fa-angle-left"></i></a>
    <h1>Change user</h1>
    <?php
    include_once 'db/load_change_user.php';
    ?>
    <div class="valid_data message hidden_message"><p>User updated successfully</p></div>
    <div class="invalid_data message hidden_message"><p>Invalid validation!</p></div>
</div>
</body>
</html>

<script type="text/javascript">

    $(document).on('click', '#save', function (e) {
        e.preventDefault();
        var form = $('form');

        //считываем курсы
        var array_id = [];
        var array_couses = $(".course");
        for (var i = 0; i < array_couses.length; i++) {
            array_id[i] = $(array_couses[i]).data("value");
        }

        //ajax запрос на update user
        $.ajax({
            type: "POST",
            url: "db/edit_user.php",
            data: {
                'id_user': $('#id_user').val(),
                'name': $('#id_name').val(),
                'courses[]': array_id,
                'email': $('#id_email').val(),
                'phone': $('#id_phone').val(),
                'mobile_phone': $('#id_mobile_phone').val(),
                'status': $('#id_status').val()
            },
            success: function (valid) {
                console.log(data);
                if (valid == 'true') {
                    if (!$('.invalid_data').hasClass('hidden_message')) {
                        $('.invalid_data').addClass('hidden_message');
                    }
                    $('.valid_data').removeClass('hidden_message');
                    setTimeout(function () {
                        $(location).attr('href', "index.php");
                    }, 3000);
                }
                else {
                    $('.invalid_data').removeClass('hidden_message');
                }
            }
        })
    });
</script>