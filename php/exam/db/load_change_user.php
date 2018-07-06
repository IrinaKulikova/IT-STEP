<?php
//донные для подключения к DB
include_once './config/db.inc';

function loadUser($db)
{
    $id = htmlentities($_GET['editid']);
    $sql = "select * from user where id=:id";
    $stmt = $db->prepare($sql);
    $stmt->bindParam("id", $id, PDO::PARAM_INT);
    $stmt->execute();
    $data = $stmt->fetch();

    //предметы, которые не проходит выбранный студент
    $sql = "select c.id, c.name from course as c
			where c.id not in (select id_course from user_course where id_user like '{$id}')";
    $stmt = $db->prepare($sql);
    $stmt->execute();
    $courses_to_choose = $stmt->fetchAll(PDO::FETCH_ASSOC);

    //предметы которые проходит выбранный студент
    $sql = "select c.id, c.name from user_course as uc join course as c on c.id=uc.id_course where uc.id_user like '$id'";
    $stmt = $db->prepare($sql);
    $stmt->execute();
    $user_courses = $stmt->fetchAll(PDO::FETCH_ASSOC);

    //все предметы
    $sql = "select * from course";
    $stmt = $db->prepare($sql);
    $stmt->execute();
    $courses_all = $stmt->fetchAll(PDO::FETCH_ASSOC);

    if (false != $data) {
        show_form($data['id'], $data['name'], $data['surname'], $data['email'], $data['phone'], $data['mobile_phone'], $data['status'], $courses_all, $courses_to_choose, $user_courses);
    }
}

function show_form($id, $name, $surname, $email, $phone, $mobile_phone, $status, $courses_all, $courses_to_choose, $user_courses)
{
    echo '<form class="user update" method="post" id="data" novalidate="novalidate">';
    echo "<input style='display: none' id='id_user' name='id_user' value='$id'></input>";
    echo '<input type="hidden" name="csrfmiddlewaretoken" value="Uau4TRc6yneLkgChNKQnUTW0xBGsCYQpaaQIQCNWCtMaY5jsP2NcEz07uzIuG0dT">';
    $fullname = $name . ' ' . $surname;
    echo "<label for='id_name'>Name</label><input type='text' name='name' value='$fullname' maxlength='100' required='' id='id_name' aria-required='true' readonly>";
    echo "<label for='id_email'>E-mail</label><input type='email' name='email' value='{$email}' required='' id='id_email' aria-required='true'>";
    echo "<label for='id_phone'>Phone</label><input  type='text' value='$phone' name='phone' pattern='\+\s?\d{1,2}\s?\(?\d{3}\)?\s?\d{3}\s?\d{2}\s?\d{2}' placeholder=\"+XX(XXX)XXXXXXX\" maxlength='100' id='id_phone'>";
    echo "<label for='id_mobile_phone'>Mobile phone</label><input type='text' value='$mobile_phone' name='mobile_phone' pattern='\+\s?\d{1,2}\s?\(?\d{3}\)?\s?\d{3}\s?\d{2}\s?\d{2}'  placeholder=\"+XX(XXX)XXXXXXX\" maxlength='100' id='id_mobile_phone'>";
    echo "<label for='id_status'>Status</label><select name='status' id='id_status'>";
    echo '<option value="inactive"';
    if ($status != "active") echo "selected";
    echo ">Inactive</option>";
    echo '<option value="active"';
    if ($status == 'active') echo "selected";
    echo ">Active</option>";
    echo '</select>';
    echo '<label for="id_courses">Courses</label>';
    echo '<select name="courses" class="courses_select" id="id_courses">';
    for ($i = 0; $i < count($courses_to_choose); $i++) {
        $id_course = $courses_to_choose[$i]['id'];
        $name_course = $courses_to_choose[$i]['name'];
        echo '<option value=" ' . $id_course . '" >' . $name_course . '</option>';
    }
    echo '</select>';
    echo '<select name="selected" class="invisible" id="id_selected" multiple>';
    $select_attribute = "selected";
    for ($i = 0; $i < count($user_courses); $i++) {
        $id_course = $user_courses[$i]['id'];
        $name_course = $user_courses[$i]['name'];
        echo '<option value=" ' . $id_course . '" ' . $select_attribute . ' >' . $name_course . '</option>';
    }
    echo '</select>';
    echo '</select>';
    echo '<div class="btn-add-course"  href="">+</div>';
    echo '<div id="selected"></div>';
    echo '<div class="clear"></div>';
    echo '<button type="submit" id="save" class="save-user">Save</button>';
    echo '</form>';
}

if (isset($_GET)) {
    if (isset($_GET['editid'])) {
        try {
            $dsn = "mysql:host=" . HOST . ';charset=utf8';
            $db = new PDO($dsn, USERNAME, PASSWORD);
            $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $sql = 'use ' . DATABASE;
            $db->exec($sql);
            loadUser($db);
        } catch (PDOException $ex) {
            echo $ex->getMessage();
        } catch (Exception $ex) {
            echo $ex->getMessage();
        } finally {
            $db = null;
        }
    }
}