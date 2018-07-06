<?php

include_once '../config/db.inc';

try {
    $dsn = "mysql:host=" . HOST . ';dbname=' . DATABASE . ';charset=utf8';
    $db = new PDO($dsn, USERNAME, PASSWORD);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = 'use ' . DATABASE;
    addNewUser($db);
} catch (PDOException $ex) {
    echo $ex->getMessage();
} catch (Exception $ex) {
    echo $ex->getMessage();
} finally {
    $db = null;
}

function addNewUser($db)
{
    if (!empty($_POST)) {
        if (isset($_POST['name']) && isset($_POST['email']) && isset($_POST['phone']) && isset($_POST['mobile_phone']) && isset($_POST['status'])) {

            $is_valid = true;
            $pattern_name = '/^[a-zA-Zа-яА-Я]{2,20}\s+[a-zA-Zа-яА-Я]{2,20}$/u';
            if (FALSE == preg_match($pattern_name, $_POST['name'])) {
                $is_valid = false;
            }

            $pattern_email = '/^\w+@\w{1,8}\.\w{2,5}$/';
            if (FALSE == preg_match($pattern_email, $_POST['email'])) {
                $is_valid = false;
            }

            if ($_POST['phone'] != "") {
                $pattern_phone = '/\+\s?\d{1,2}\s?\(?\d{3}\)?\s?\d{3}\s?\d{2}\s?\d{2}/m';
                if (FALSE == preg_match($pattern_phone, $_POST['phone'])) {
                    $is_valid = false;
                }
            }

            if ($_POST['mobile_phone'] != "") {
                if (FALSE == preg_match($pattern_phone, $_POST['mobile_phone'])) {
                    $is_valid = false;
                }
            }

            if (TRUE == $is_valid) {
                $fullname = explode(" ", htmlentities($_POST['name']));
                $name = $fullname[0];
                $surname = $fullname[1];
                $email = htmlentities($_POST['email']);
                $phone = htmlentities($_POST['phone']);
                $mobile_phone = htmlentities($_POST['mobile_phone']);
                $status = htmlentities($_POST['status']);

                //подготовленный запрос редактирования данных в таблице user
                $sql = "INSERT INTO `user` (name,surname,email,phone,mobile_phone, status) values(:name,:surname,:email,:phone,:mobile_phone,:status)";
                $stmt = $db->prepare($sql);
                $stmt->bindParam("name", $name, PDO::PARAM_STR);
                $stmt->bindParam("surname", $surname, PDO::PARAM_STR);
                $stmt->bindParam("email", $email, PDO::PARAM_STR);
                $stmt->bindParam("phone", $phone, PDO::PARAM_STR);
                $stmt->bindParam("mobile_phone", $mobile_phone, PDO::PARAM_STR);
                $stmt->bindParam("status", $status, PDO::PARAM_STR);
                $data = $stmt->execute();
                echo json_encode($is_valid);
            } else {
                echo json_encode(false);
            }
        }
    }
}