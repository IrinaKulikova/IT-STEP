<?php

include_once 'inc/db.inc';

//провепяем что есть в массиве пост данные
if (!empty($_POST)) {
    extract($_POST);
    //новая задача не пустая
    if (isset($newtask)) {
        if ($newtask != "") {
            //подключаемся к базе данных
            $dns = 'mysql:host=' . HOST . ';dbname=' . DBNAME . ';charset=utf8';
            try {
                $db = new PDO($dns, DBUSER, DBPASS); // подключение к б/д
                // настройка режима работы с ошибками - выкидывать исключения
                $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                // добавление новой записи
                if (isset($status)) {
                    $sql = "INSERT INTO tasks(title,status) VALUES ('$newtask', 'true')";
                } else {
                    $sql = "INSERT INTO tasks(title,status) VALUES ('$newtask', 'false')";
                }
                $rows = $db->exec($sql); // выполнение sql запроса

            } catch (PDOException $ex) {
                echo "<p style='color:red'>";
                echo $ex->getMessage();
                echo "</p>";
            } finally {
                $db = null; // отключение от б/д
            }
        }
    }
}