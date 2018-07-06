<?php

include_once '../config/db.inc';

try {
    $dsn = "mysql:host=" . HOST . ';dbname=' . DATABASE . ';charset=utf8';
    $db = new PDO($dsn, USERNAME, PASSWORD);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = 'use ' . DATABASE;
    deleteUser($db);
} catch (PDOException $ex) {
    echo $ex->getMessage();
} catch (Exception $ex) {
    echo $ex->getMessage();
} finally {
    $db = null;
}

function deleteUser($db)
{
    if (!empty($_GET)) {
        if (isset($_GET['deleteid'])) {
            $id = htmlentities($_GET['deleteid']);

            //подготовленный запрос удаление данных в таблице user
            $sql = "DELETE FROM `user` WHERE id=:id";
            $stmt = $db->prepare($sql);
            $stmt->bindParam("id", $id, PDO::PARAM_INT);
            $data = $stmt->execute();

            //подготовленный запрос удаления данных в таблице user_course
            $sql = "DELETE FROM `user_course` WHERE id_user=:id";
            $stmt = $db->prepare($sql);
            $stmt->bindParam("id", $id, PDO::PARAM_INT);
            $data = $stmt->execute();
            header("Location: ../index.php");
        }
    }
}