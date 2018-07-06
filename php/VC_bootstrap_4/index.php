<!doctype html>
<html lang="en" class="p-3 mb-2 bg-secondary text-white">
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css"
          integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
    <link href="https://fonts.googleapis.com/css?family=Quicksand" rel="stylesheet">
    <link href="css/style.css" rel="stylesheet">
    <title>numbers</title>
</head>
<body class="p-3 mb-2 bg-secondary text-white">

<!-- Optional JavaScript -->
<!-- jQuery first, then Popper.js, then Bootstrap JS -->
<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js"
        integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN"
        crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js"
        integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q"
        crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"
        integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl"
        crossorigin="anonymous"></script>
<script src="js/script.js" type="text/javascript"></script>
<script src="js/table_script.js" type="text/javascript"></script>
<script src="js/cookies.js" type="text/javascript"></script>

<?php

if (empty($_POST)) { // Отработал метод GET
    include 'main_page.php'; ?>
    <script src="js/script.js" type="text/javascript">
    </script>
<?php
} else { // Отработал метод POST

//предположим валидация пройдена
$is_valid = true;

$pattern_name = '/^[a-zA-Zа-яА-Я]{2,20}$/u';
if (FALSE == preg_match($pattern_name, $_POST['first_name'])) {
    $is_valid = false;
}
if (FALSE == preg_match($pattern_name, $_POST['last_name'])) {
    $is_valid = false;
}
$pattern_email = '/^\w+@\w{2,8}\.\w{2,5}$/';
if (FALSE == preg_match($pattern_email, $_POST['email'])) {
    $is_valid = false;
}
$pattern_phone = '/^\+\d{2}\(\d{3}\)\d{3}-\d{2}-\d{2}$/';
if (FALSE == preg_match($pattern_phone, $_POST['phone'])) {
    $is_valid = false;
}

if ($is_valid === TRUE) {
?>

    <div class="col-lg-12">
        <div class="container">
            <div class="row">
                <div class="col-lg-4">
                    <table class="table  table-bordered">
                        <thead>
                        <tr>
                            <th scope="col" colspan="2"> Personal Information</th>
                        </tr>
                        </thead>
                        <tbody>
                        <tr>
                            <th scope="row">First Name</th>
                            <td>
                                <?php
                                $first_name = $_POST['first_name'];
                                echo "$first_name";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">Last Name</th>
                            <td>
                                <?php
                                $last_name = $_POST['last_name'];
                                echo "$last_name";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">E-mail</th>
                            <td>
                                <?php
                                $email = $_POST['email'];
                                echo "$email";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">Phone number</th>
                            <td>
                                <?php
                                $phone = $_POST['phone'];
                                echo "$phone";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">Gender</th>
                            <td>
                                <?php
                                $gender = $_POST['gender'];
                                echo "$gender";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">Bith Date</th>
                            <td>
                                <?php
                                $bith = $_POST['date'];
                                echo "$bith";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">Nationality</th>
                            <td>
                                <?php
                                $nationality = $_POST['nationality'];
                                echo "$nationality";
                                ?>
                            </td>
                        </tr>
                        </tbody>
                    </table>
                </div>

                <div class="col-lg-4">
                    <table class="table  table-bordered">
                        <thead>
                        <tr>
                            <th scope="col" colspan="2"> Last Work Position</th>
                        </tr>
                        </thead>
                        <tbody>
                        <tr>
                            <th scope="row">Company Name</th>
                            <td>
                                <?php
                                $company = $_POST['company'];
                                echo "$company";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">Position</th>
                            <td>
                                <?php
                                $position = $_POST['position'];
                                echo "$position";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">From</th>
                            <td>
                                <?php
                                $date_from = $_POST['date_from'];
                                echo "$date_from";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">To</th>
                            <td>
                                <?php
                                $date_to = $_POST['date_to'];
                                echo "$date_to";
                                ?>
                            </td>
                        </tr>
                        <tr>
                            <th scope="row">Task and/n Responsibility</th>
                            <td>
                                <?php
                                $responsibilities = $_POST['responsibilities'];
                                echo "$responsibilities";
                                ?>
                            </td>
                        </tr>
                        </tbody>
                    </table>
                </div>

                <div class="col-lg-4">
                    <table class="table table-bordered">
                        <thead>
                        <tr>
                            <th scope="col" colspan="2"> Computer Skills - Programming Languages</th>
                        </tr>
                        </thead>
                        <tbody>
                        <?php for ($i = 0; $i < count($_POST['prog_lang']); $i++) {
                            echo "<tr><th>";
                            $prog = $_POST['prog_lang'][$i];
                            echo "$prog";
                            echo "</th>";
                            echo "<td>";
                            $level = $_POST['prog_level'][$i];
                            echo "$level";
                            echo "</td></tr>";
                        }
                        ?>
                        </tbody>
                    </table>
                    <br>

                    <?php
                    if (!empty($_POST['lang'])) {
                        for ($i = 0; $i < count($_POST['lang']); $i++) {
                            echo '<table class="table  table-bordered">';
                            echo '<thead>';
                            echo '<tr><th scope="col" colspan="2">';
                            $f_lang = $_POST['lang'][$i];
                            echo "$f_lang";
                            echo '</th>';
                            echo '</tr>';

                            echo "<td>";
                            echo 'Comprehension';
                            echo "<td>";
                            $level = $_POST['lang_level_comprehension'][$i];
                            echo "$level";
                            echo "</td></tr>";

                            echo '</tr>';
                            echo "<td>";
                            echo 'Reading';
                            echo "<td>";
                            $level = $_POST['lang_level_reading'][$i];
                            echo "$level";
                            echo "</td></tr>";

                            echo '</tr>';
                            echo "<td>";
                            echo 'Writing';
                            echo "<td>";
                            $level = $_POST['lang_level_writing'][$i];
                            echo "$level";
                            echo "</td></tr>";
                            echo "</thead></table>";
                        }
                    }

                    if(!empty($_POST['license'])){

                        echo  "<lable>License: </lable>";
                        for ($i=0;$i<count($_POST['license']);$i++){
                            $license=$_POST['license'][$i];
                            echo "\t"."$license";
                        }
                    }
                    ?>
                </div>
            </div>
        </div>
        <footer class="mt-4">
            <div class="text-center" style="opacity: 0.25">
                <label>
                    php js jquery bootstrap fonts.google cookie
                    <br>
                    <small>Kulikova 2018 itstep</small>
                </label>
            </div>
        </footer>
    </div>

    <?php
}
}
?>


</body>
</html>