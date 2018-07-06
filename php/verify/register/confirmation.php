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

    <title>Mailer Confirmation</title>
</head>
<body>
<div class="container mt-4">

<?php

use Mailer\ConnectionDB;

include_once 'ConnectionDB\ConnectionDB.php';
if (!empty($_GET)) {
    if ($_GET['code']) {
        $connection = new ConnectionDB();
        $connection->Connection();
        $status = $connection->SetActiveStatus(strip_tags($_GET['code']));
        if ($status == true) {
            //переводим на страничку входа
            header("Location: login.php");
        } else {
            echo "<div class='mt-3'><p class='small text-danger font-italic'>Error activation code!</p></div>";
        }
        $connection->Disconnect();
    } else {
        echo "<div class='mt-3'><p class='small text-danger font-italic'>Error date!</p></div>";
    }
} else {
    echo "<div class='mt-3'><p class='small text-danger font-italic' '>Error date!</p></div>";
}

ob_end_flush();