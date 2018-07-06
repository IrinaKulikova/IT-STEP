<?php

include_once 'inc/db.inc';

$dns = 'mysql:host=' . HOST . ';dbname=' . DBNAME . ';charset=utf8';
try {
    $db = new PDO($dns, DBUSER, DBPASS); // подключение к б/д
    // настройка режима работы с ошибками - выкидывать исключения
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "SELECT * FROM tasks";
    $stmt = $db->query($sql);
    while (FALSE !== ($row = $stmt->fetch(PDO::FETCH_ASSOC))) {
        if (!isset($add_title_tasks)) {
            $add_title_tasks = true;
            echo '<h4>Tasks</h4>';
        }
        echo '<form method="post">';
        echo '<div class="input-group mb-3">';
        echo '<div class="input-group-prepend">';
        echo '<div class="input-group-text">';
        echo "<input type='checkbox' aria-label='Checkbox for following text input'";
        if ("true" === $row['status']) echo 'checked="checked"';
        echo '>';
        echo '</div></div>';
        echo '<lable type="text" class="form-control" aria-label="Text input with checkbox">';
        echo "{$row['title']}"."</lable>";
        echo "<button type='submit' name='delete' value='{$row["id"]}' class='btn btn-primary'>Delete</button>";
        echo "</div></form>";
        $add_button_delete_all = true;
    }
    if (isset($add_button_delete_all)) {
        echo '<div><form method="post">';
        echo '<button type="submit" name="deleteall" class="btn btn-danger">Delete All Tasks</button>';
        echo '</form></div>';
    }
} catch (PDOException $ex) {
    echo "<p style='color:red'>";
    echo $ex->getMessage();
    echo "</p>";
} finally {
    $db = null; // отключение от б/д
}