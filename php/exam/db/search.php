<?php

include_once '../config/db.inc';

try {
    $dsn = "mysql:host=" . HOST . ';dbname=' . DATABASE . ';charset=utf8';
    $db = new PDO($dsn, USERNAME, PASSWORD);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = 'use ' . DATABASE;
    $db->exec($sql);
    getUsers($db);
} catch (PDOException $ex) {
    echo $ex->getMessage();
} catch (Exception $ex) {
    echo $ex->getMessage();
} finally {
    $db = null;
}

function getUsers($db)
{
    if (!empty($_POST)) {
        if (isset($_POST['search'])) {
            header('Content-Type: application/json; charset=UTF-8');
            //подготовленный запрос редактирования данных в таблице user
            $search = trim(strip_tags(stripcslashes(htmlspecialchars($_POST['search']))));
            $sql = "SELECT DISTINCT id, name, surname FROM `user` WHERE `name` like ? or `surname` like ? group by id";
            $params = array("%$search%", "%$search%");
            $stmt = $db->prepare($sql);
            $stmt->execute($params);
            $data=$stmt->fetchAll(PDO::FETCH_ASSOC);
            echo json_encode($data);
        }
    }
}