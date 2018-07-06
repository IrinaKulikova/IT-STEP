<?php
function loadAddUser($id, $name, $surname, $email, $status)
{
    echo "<tr>";
    echo '<td >' . "$name $surname" . '</td >';
    echo '<td >' . "$email" . '</td >';
    echo "<td >";
    echo "<span class=";
    if ($status == 'active') echo 'active'; else echo 'inactive';
    echo ">$status</span >";
    echo "</td >";
    echo "<td >";
    $refEdit = "change_user.php?editid=" . "$id";
    echo "<a href = $refEdit class='edit' ><i class='fa fa-pencil' aria - hidden = 'true' ></i ></a >";
    $refDelete = "db\delete_user.php?deleteid=" . "$id";
    echo "<a href = $refDelete class='delete' ><i class='fa fa-trash' aria - hidden = 'true' ></i ></a >";
    echo "</td >";
    echo "</tr >";
}