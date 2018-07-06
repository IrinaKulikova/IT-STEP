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
            <input type="login" name="login" class="form-control" id="login" placeholder="Your login">
        </div>
        <div class="form-group">
            <label for="password">Password</label>
            <input type="password" name="password" class="form-control" id="password" placeholder="Password">
        </div>
        <button type="submit" class="btn btn-info">Login!</button>
    </form>
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
use Mailer\ConnectionDB;
include 'ConnectionDB\ConnectionDB.php';

if (!empty($_POST)) {
    if (isset($_POST['login']) && isset($_POST['password'])) {
        $connection=new ConnectionDB();
        $connection->Connection();
        if($connection->CheckUser($_POST['login'],$_POST['password'])){
            header("Location: main.php");
        }
        else{
            echo "<div class='mt-3'><p class='small text-danger font-italic'>Error login or password</p></div>";
        }
        $connection->Disconnect();
    }
}
?>

