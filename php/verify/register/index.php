<?php
ob_start();
?>

<!doctype html>
<html lang="en">
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css"
          integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <title>Mailer</title>
</head>
<body>
<div class="container mt-4">
    <form method="post">
        <div class="form-group">
            <label for="login">Login</label>
            <input type="login" name="login" class="form-control" id="login" placeholder="Unique login">
        </div>
        <div class="form-group">
            <label for="email">Email address</label>
            <input type="email" name="email" class="form-control" id="email" placeholder="Unique email">
        </div>
        <div class="form-group">
            <label for="password1">Password</label>
            <input type="password" name="password1" class="form-control" id="password1" placeholder="Password">
        </div>
        <div class="form-group">
            <label for="password2">Repeat password</label>
            <input type="password" name="password2" class="form-control" id="password2" placeholder="Password">
        </div>
        <button type="submit" class="btn btn-info">To register</button>
    </form>

    <!--Видео:https://youtu.be/C1ivcJAq76E-->
    <!---->
    <!--Задание-->
    <!--Реализовать регистрацию пользователя с подтверждением email.-->
    <!---->
    <!--Пользователь регистрируется на сайте, заполняя поля login, password и email корректным образом.-->
    <!--Данные, прежде чем добавиться в базу данных, проверяются нашими скриптами.-->
    <!--Если всё корректно, то записываем данного юзера в табличку users.-->
    <!---->
    <!--Естественно, пароль в «чистом» виде хранить нельзя. Так как это теоретически может привести к краже паролей.-->
    <!--Обычно пароль хранят в захэшированном виде, а при авторизации, пароль, введённый пользователем в текстовое поле, также хэшируют и сравнивают уже хэши, а не «чистые» пароли.-->
    <!---->
    <!--Хэшируем функцией md5(). О данном алгоритме читаем тут, останавливаться на этом я не буду.-->
    <!--Часто при хэшировании пароль «солят» — примешивают к оригинальному паролю какие-то случайные символы (причём, неизвестно куда именно – в начало пароля, середину или конец),-->
    <!--а также хэшируют, например, дважды.-->
    <!---->
    <!--Все эти меры позволяют свести к минимуму шанс расшифровки хэша вашего пароля злоумышленником, использующим, например, радужные таблицы.-->
    <!--Соль, конечно же, также необходимо писать в базу данных, чтобы при каждой авторизации строить правильный хэш на основе вводимого юзером пароля.-->
    <!---->
    <!--Также при регистрации обычно указывается email. В случае нашего проекта он является и логином.-->
    <!--Естественно, почта у различных пользователей повторяться не может, поэтому в скрипте не забываем делать соответствующую проверку.-->
    <!--И вот мы подобрались к сути задания – необходимо реализовать подтверждение регистрации по email. Зачем это нужно?-->
    <!---->
    <!--Плюсов можно найти много. Все они сводятся к тому, что ты подтверждаешь, что email действительно твой. А это нам позволит в будущем реализовать, скажем,-->
    <!--«восстановление» пароля (кавычки использованы неспроста – ведь пароль из хэша восстановить не получится, обычно новый пароль либо вводит-->
    <!--сам пользователь в специальной форме, либо генерируется автоматически, высылаясь на почту забывчивого юзера).-->
    <!---->
    <!--Также это исправит нас от жалоб тех пользователей, чьи адреса использовали их недруги при регистрации, ведь им может приходить-->
    <!--нежелательная рассылка с нашего сайта. Рассылка также является одной из причин важности подтверждения по email.-->
    <!---->
    <!--Пользователь зашёл на сайт, зарегистрировался, увидел сообщение о том, что запрос на подтверждение отправлен ему на почту.-->
    <!--Что он должен увидеть в письме? Это будет ссылка на определённую страницу, где и будет проводиться верификация. И-->
    <!--дея заключается в том, что ссылка должна содержать что-то уникальное, что абсолютно невозможно узнать, не прочитав письма.-->
    <!---->
    <!--Ведь если при регистрации я указал не свой email, то и узнать эту «уникальность» я никак не смогу, не имея доступа к ящику.-->
    <!--Так, предположим, что почта наша, и мы открыли письмо. Нечто уникальное – некоторый случайно сгенерированный get-параметр. Ссылка подтверждения имеет следующий вид:-->
    <!---->
    <!--http://localhost/verification/?hash=9kzhrz3b34sb-->
    <!---->
    <!--где «9kzhrz3b34sb» — случайно сгенерированный параметр-->
    <!---->
    <!--Перейдя по ссылке мы сравним параметр с аналогичным в базе данных и с уверенностью сможем сказать, что именно этот пользователь регистрировался на-->
    <!--нашем сайте и email на самом деле принадлежит ему.-->
    <!---->
    <!--Пожалуй, стоит остановиться на том, что произойдёт после подтверждения. Наверняка, до этого у пользователя либо вообще не будет прав на сайте,-->
    <!--либо они будут существенно ограничены. Как это будем запоминать? С этой задачей прекрасно справится ещё одно поле в БД, скажем, verification,-->
    <!--которое до момента подтверждения регистрации для конкретного пользователя будет равно false или, например, нулю.-->
    <!--После подтверждения просто меняем это поле на true-->


    <?php


    include 'ConnectionDB\ConnectionDB.php';
    include_once 'UserDB\UserDB.php';
    require "../vendor/autoload.php";
    //spl_autoload_register();
    use Mailer\ConnectionDB;
    use Mailer\UserDB;
    use PHPMailer\PHPMailer\PHPMailer;

    $mail = new PHPMailer(true);
    $from = 'shag.kulikova@gmail.com';
    $msg = 'Чтоб подтвердить регистрацию перейдите по ссылке ';
    if (!empty($_POST)) {
        if (isset($_POST['email']) && isset($_POST['login']) && isset($_POST['password1']) && isset($_POST['password2'])) {
            if ($_POST['email'] != "" && $_POST['login'] != "" && $_POST['password1'] != "" && $_POST['password2'] != "") {
                if (is_valid($_POST['email'], $_POST['login'], $_POST['password1'], $_POST['password2'])) {
                    try {
                        $mail->SMTPDebug = 0;
                        // Настройки сервера SMTP
                        $mail->isSMTP();
                        $mail->Host = 'smtp.gmail.com';
                        $mail->Port = 465;
                        $mail->SMTPSecure = 'ssl';
                        $mail->SMTPAuth = true;
                        $mail->Password = '28November16';
                        $mail->Username = $from;
                        $mail->smtpConnect(
                            array(
                                "ssl" => array(
                                    "verify_peer" => false,
                                    "verify_peer_name" => false,
                                    "allow_self_signed" => true
                                )
                            )
                        );

                        // Отправляемое письмо
                        //обавление пользователя в базу данных
                        $connect = new ConnectionDB();
                        $connect->Connection();
                        $user = new UserDB(strip_tags($_POST['login']), strip_tags($_POST['email']), strip_tags($_POST['password1']));
                        $activation = $connect->AddUserToDataBase($user);
                        $msg .= "<a href='http://localhost/homeworks/verify/register/confirmation.php?code={$activation}'>Active link</a>";
                        $connect->Disconnect();
                        $mail->setFrom($from); // отправитель
                        $mail->addAddress($_POST['email']); // получатели
                        $mail->CharSet = "utf-8";
                        $mail->Subject = "Подтверждение пароля";
                        $mail->msgHTML($msg);
                        $mail->AltBody = "";
                        $mail->send();
                        header("Location: login.php");
                        echo "<div class='mt-3'><p class='small text-info font-italic'>Send successfully!</p></div>";
                    } catch (Exception $ex) {
                        echo "<div class='mt-3'><p class='small text-danger font-italic'>Error connect data base!</p></div>";
                    }
                }
            } else {
                echo "<div class='mt-3'><p class='small text-danger font-italic'>Please fill in all the fields!</p></div>";
            }
        }
    }

    function is_valid($email, $login, $password1, $password2)
    {
        //подключиться к бд и проверить если ли в бд записи с текущим login или email
        $connect = new ConnectionDB();
        $connect->Connection();
        //наличие логина или пароля в базе данных
        //$log = true;
        //$pass = true;
        if ($connect->CheckBDNotNull()) {
            $log = $connect->CheckEmailInBD(strip_tags($email));
            $pass = $connect->CheckLoginInBD(strip_tags($login));
            $connect->Disconnect();
        } else {
            echo "<div class='mt-3'><p class='small text-danger font-italic'>Error connection data base</p></div>";
            return false;
        }

        //если такой логин уже есть в базе
        if ($log != false) {
            echo "<div class='mt-3'><p class='small text-danger font-italic'>login is already taken!</p></div>";
            return false;
        }

        //если такой почтовый адрес уже есть в базе
        if ($pass != false) {
            echo "<div class='mt-3'><p class='small text-danger font-italic' '>User with such email already registered!</p></div>";
            return false;
        }

        //если пароли не совпадают
        if ($password1 != $password2) {
            echo "<div class='mt-3'><p class='small text-danger font-italic'>Passwords are different!</p></div>";
            return false;
        }
        return true;
    }

    ?>

</div>

<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js"
        integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN"
        crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js"
        integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q"
        crossorigin="anonymous"></script>

</body>
</html>


<?php
ob_end_flush();
?>