<?php

include_once '../config/db.inc';

try {
    $dsn = "mysql:host=" . HOST . ';dbname=' . DATABASE . ';charset=utf8';
    $db = new PDO($dsn, USERNAME, PASSWORD);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = 'use ' . DATABASE;
    editUser($db);
} catch (PDOException $ex) {
    echo $ex->getMessage();
} catch (Exception $ex) {
    echo $ex->getMessage();
} finally {
    $db = null;
}

function editUser($db)
{
    if (!empty($_POST)) {
        if (isset($_POST['id_user']) && isset($_POST['email']) && isset($_POST['phone']) && isset($_POST['mobile_phone']) && isset($_POST['status'])) {

            $is_valid = true;
            $pattern_email = '/^\w+@\w{2,8}\.\w{2,5}$/';
            if (FALSE == preg_match($pattern_email, $_POST['email'])) {
                $is_valid = false;
            }
            $pattern_phone = '/^\+\d{2}\(\d{3}\)\d{3}\d{2}\d{2}$/';
            if (FALSE == preg_match($pattern_phone, $_POST['phone'])) {
                $is_valid = false;
            }

            if (FALSE == preg_match($pattern_phone, $_POST['mobile_phone'])) {
                $is_valid = false;
            }

            if (TRUE == $is_valid) {
                $id = htmlentities($_POST['id_user']);
                $email = htmlentities($_POST['email']);
                $phone = htmlentities($_POST['phone']);
                $mobile_phone = htmlentities($_POST['mobile_phone']);
                $status = htmlentities($_POST['status']);

                //подготовленный запрос редактирования данных в таблице user
                $sql = "UPDATE `user` SET email=:email, phone=:phone, mobile_phone=:mobile_phone, `status`=:status WHERE id=:id";
                $stmt = $db->prepare($sql);
                $stmt->bindParam("email", $email, PDO::PARAM_STR);
                $stmt->bindParam("phone", $phone, PDO::PARAM_STR);
                $stmt->bindParam("mobile_phone", $mobile_phone, PDO::PARAM_STR);
                $stmt->bindParam("status", $status, PDO::PARAM_STR);
                $stmt->bindParam("id", $id, PDO::PARAM_INT);
                $stmt->bindParam("status", $status);
                $data = $stmt->execute();
            }


            if (isset($_POST['courses'])) {
                //подготовленный запрос редактирования данных в таблице user_course

                //удаляем из таблицы user_course все записи c id редактируемого пользователя
                $id = htmlentities($_POST['id_user']);
                $sql = "DELETE FROM `user_course` WHERE id_user=:id";
                $stmt = $db->prepare($sql);
                $stmt->bindParam("id", $id, PDO::PARAM_INT);
                $data = $stmt->execute();

                //добавляем новые курсы текущему пользователю
                $courses = ($_POST['courses']);

                //перебимаем массив с курсами
                $sql = "INSERT INTO `user_course` (id_user,id_course) VALUES (:id_user,:id_course)";
                $stmt = $db->prepare($sql);
                $stmt->bindParam("id_user", $id, PDO::PARAM_STR);
                for ($i = 0; $i < count($courses); $i++) {
                    $stmt->bindParam("id_course", $courses[$i], PDO::PARAM_INT);
                    $data = $stmt->execute();
                }
                echo json_encode(true);
            }
        } else {
            echo json_encode(false);
        }
    }
}