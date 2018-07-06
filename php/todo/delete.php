<?php

include_once 'inc/db.inc';

if (isset($_POST)) {
    if (isset($_POST['delete'])) {
        //подключаемся к базе данных
        $dns = 'mysql:host=' . HOST . ';dbname=' . DBNAME . ';charset=utf8';
        try {
            $db = new PDO($dns, DBUSER, DBPASS); // подключение к б/д
            // настройка режима работы с ошибками - выкидывать исключения
            $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            // УДАЛЕНИЕ ВСЕХ ЗАПИСЕЙ
            $sql = "DELETE FROM tasks where id={$_POST['delete']}";
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
