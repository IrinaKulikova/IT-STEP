<!DOCTYPE html>
<!-- saved from url=(0035)http://127.0.0.1:8000/users/create/ -->
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
<div class="container">

    <a href="index.php" class="btn-back"><i class="fa fa-angle-left"></i></a>

    <h1>Create user</h1>

    <form class="user" method="post" id="new_user_form" novalidate="novalidate">
        <input type="hidden" name="csrfmiddlewaretoken"
               value="uWZOWOlxKN7Jr9xIxX7o2QY8u8xLk8qoKWlsTzWnOTF85YeTzf4dMw2fr6zNoaNS">
        <label for="id_name">Name</label><input type="text" name="name" maxlength="100" required="" id="id_name"
                                                aria-required="true">
        <label for="id_email">E-mail</label><input type="email" name="email" required="" id="id_email"
                                                   aria-required="true">
        <label for="id_phone">Phone</label><input type="text" name="phone"
                                                  pattern='\+\s?\d{1,2}\s?\(?\d{3}\)?\s?\d{3}\s?\d{2}\s?\d{2}'
                                                  placeholder="+XX (XXX) XXXXXXX" maxlength="100" id="id_phone">
        <label for="id_mobile_phone">Mobile phone</label><input type="text" name="mobile_phone"
                                                                pattern='\+\s?\d{1,2}\s?\(?\d{3}\)?\s?\d{3}\s?\d{2}\s?\d{2}'
                                                                placeholder="+XX (XXX) XXXXXXX" maxlength="100"
                                                                id="id_mobile_phone">
        <label for="id_status">Status</label>
        <select name="status" id="id_status">
            <option value="inactive">Inactive</option>
            <option value="active">Active</option>
        </select>
        <button id="add" type="submit">Create</button>
    </form>
    <div class="valid_data message hidden_message"><p>User added!</p></div>
    <div class="invalid_data message hidden_message"><p>Invalid validation!</p></div>
</div>
</body>
</html>

<script type="text/javascript">
    $(document).on('click', '#add', function (e) {
        e.preventDefault();

        //ajax запрос на update user
        $.ajax({
            type: "POST",
            url: "db/add_new_user.php",
            data: $('#new_user_form').serialize(),
            dataType: "html",
            cache: false,
            success: function (valid) {
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