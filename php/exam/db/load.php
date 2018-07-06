<?php

include_once 'config/db.inc';

function initDatabase($db)
{
    $sql = 'create database if not exists ' . DATABASE . ' default charset=utf8';
    $db->exec($sql); // если не нужен результат
    $sql = 'use ' . DATABASE;
    $db->exec($sql);
    $sql = 'CREATE TABLE IF NOT EXISTS user (
                id int primary key auto_increment,
                name varchar(255) not null,
                surname varchar(255) not null,
                email varchar(255),
                phone varchar(30),
                mobile_phone varchar(30),
                status ENUM(\'active\',\'inactive\') default \'active\'
            )';
    $db->exec($sql);

    $sql = 'CREATE TABLE IF NOT EXISTS course (
                id int primary key auto_increment,
                name varchar(255) not null
            )';
    $db->exec($sql);

    $sql = 'CREATE TABLE IF NOT EXISTS user_course (
                id_user int,
		foreign key (id_user)
		references `user`(id)
			on delete set null
			on update set null,
	id_course int,
		foreign key (id_course)
		references course(id)
			on delete set null
			on update set null
            )';
    $db->exec($sql);
}

function loadData($db){
    //колличество выбираемых записей по умолчанию
    $count=5;
    if(!empty($_GET)){
        if(isset($_GET['paginate_by'])){
            $count=(int)$_GET['paginate_by'];
        }
    }

    //подготовленный запрос
    $sql = "select id,name,surname,email,status from user limit :count";
    $stmt = $db->prepare($sql);
    $stmt->bindParam("count", $count, PDO::PARAM_INT);
    $stmt->execute();
    while (FALSE !== ($row = $stmt->fetch(PDO::FETCH_ASSOC))) {
        include_once 'load_user.php';
        loadAddUser($row['id'],$row['name'],$row['surname'],$row['email'],$row['status']);
    }
}

try {
    $dsn = "mysql:host=" . HOST . ';charset=utf8';
    $db = new PDO($dsn, USERNAME, PASSWORD);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    initDatabase($db); // инициализация базы данных
    loadData($db);
} catch (PDOException $ex) {
    echo $ex->getMessage();
} catch (Exception $ex) {
    echo $ex->getMessage();
} finally {
    $db = null;
}