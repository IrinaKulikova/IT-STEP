<?php
ob_start();
?>
<!doctype html>
<html lang="en">
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.0/css/bootstrap.min.css"
          integrity="sha384-9gVQ4dYFwwWSjIDZnLEWnxCjeSWFphJiwGPXr1jddIhOegiu1FwO5qRGvFXOdJZ4"
          crossorigin="anonymous">

    <title>files</title>
</head>

<!-- Optional JavaScript -->
<!-- jQuery first, then Popper.js, then Bootstrap JS -->
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"
        integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo"
        crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.0/umd/popper.min.js"
        integrity="sha384-cs/chFZiN24E4KMATLdqdvsezGxaGsi4hLGOzlXwp5UZB1LY//20VyM2taTB4QvJ"
        crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.0/js/bootstrap.min.js"
        integrity="sha384-uefMccjFJAIv6A+rW+L4AHf99KvxDjWSu1z9VI8SKNVmz4sk7buKt/6v9KI65qnm"
        crossorigin="anonymous"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
<!-- Написать приложение «Файловый менеджер», позволяющее
    создавать/переименовывать/удалять папки
    загружать/переименовывать/перемещать/удалять файлы.
Реализовать аутентификацию на базе протокола HTTP -->

<?php

define("ROOTDIR", "upload/");

//функция удаления папки со всем содержимым
function deleteDir($path)
{
    if (is_dir($path) === true) {
        $files = array_diff(scandir($path), array('.', '..'));
        foreach ($files as $file) {
            $p = realpath($path);
            deleteDir($p . '\\' . $file);
        }
        return rmdir($path);
    } else if (is_file($path) === true) {
        return unlink($path);
    }
    return false;
}

if (!empty($_POST)) {
    //создание новой папки
    if (isset($_POST['addnewdir'])) {
        if ($_POST['addnewdir'] != "") {
            mkdir($_POST['currentdir'] . $_POST['addnewdir']);
        }
    }

    //переименование папки
    if (isset($_POST['namenewdir'])) {
        if ($_POST['currentdir'] != ROOTDIR && $_POST['namenewdir'] != "") {
            $end = strripos($_POST['currentdir'], '/');
            $buffer = substr($_POST['currentdir'], 0, $end);
            $end = strripos($buffer, '/');
            $dirparent = substr($buffer, 0, $end + 1);
            $newname = $dirparent . $_POST['namenewdir'];
            rename($_POST['currentdir'], $newname);
            $_POST['currentdir'] = $newname . '/';
        }
    }

    //рекурсивное удаление папки
    if (isset($_POST['deletecurrentdir'])) {
        if ($_POST['currentdir'] != ROOTDIR) {
            if (file_exists($_POST['currentdir'])) {
                deleteDir($_POST['currentdir']);
                $end = strripos($_POST['currentdir'], '/');
                $parent = substr($_POST['currentdir'], 0, $end);
                $end = strripos($parent, '/');
                $parent = substr($_POST['currentdir'], 0, $end + 1);
                $_POST['currentdir'] = $parent;
            }
        }
    }

    //даление текущего файла
    if (isset($_POST['fileslist']) && isset($_POST['deletecurrentfile'])) {
        unlink($_POST['fileslist']);
    }

    if (isset($_POST['renamefile']) && $_POST['renamefile'] != "") {
        $index = strripos($_POST['fileslist'], '.');
        $ex = substr($_POST['fileslist'], $index);
        rename($_POST['fileslist'], $_POST['currentdir'] . $_POST['renamefile'] . $ex);
    }

    if (isset($_POST['replacefile']) && $_POST['replacefile'] != "" && isset($_POST['fileslist']) && $_POST['fileslist'] != "") {
        if (file_exists(ROOTDIR . $_POST['replacefile'] . '/')) {
            $end = strripos($_POST['fileslist'], '/');
            $file = substr($_POST['fileslist'], $end + 1);
            rename($_POST['fileslist'], ROOTDIR . $_POST['replacefile'] . '/' . $file);
        }
    }
}

if (isset($_FILES['addfiles'])) {
    foreach ($_FILES as $f) {
        if (UPLOAD_ERR_OK === $f['error']) {
            move_uploaded_file($f['tmp_name'], $_POST['currentdir'] . $f['name']);
        }
    }
}

?>

<body>
<div class="container col-lg-8 mt-4">
    <div class="mt-2">
        <form method="post" enctype="multipart/form-data">
            <h4>Directory navigator:</h4>
            <div class="input-group">
                <select id="selectdir" class="custom-select" name="currentdir">
                    <?php
                    if (empty($_POST) || !isset($_POST['currentdir'])) {
                        $dirrun = ROOTDIR;
                    }
                    if (!empty($_POST)) {
                        if (isset($_POST['currentdir'])) {
                            $dirrun = $_POST['currentdir'];
                        }
                        if (isset($_POST['exitdir'])) {
                            if ($_POST['currentdir'] != ROOTDIR) {
                                $end = strripos($_POST['currentdir'], '/');
                                $buffer = substr($_POST['currentdir'], 0, $end);
                                $end = strripos($buffer, '/');
                                $dirrun = substr($buffer, 0, $end + 1);
                            }
                        }
                    }

                    echo "<option selected>$dirrun</option>";
                    $dirs = scandir($dirrun, GLOB_ONLYDIR);
                    if (isset($dirs)) {
                        foreach ($dirs as $dir) {
                            $fullpath = $dirrun . $dir . '/';
                            if (is_dir($fullpath)) {
                                if ($dir != "." && $dir != "..") {
                                    echo "<option value=$fullpath>$fullpath</option>";
                                }
                            }
                        }
                    }
                    ?>
                </select>
                <div class="input-group-append">
                    <button name="enterdir" class="btn btn-outline-secondary" type="submit">Enter into</button>
                    <button name="exitdir" class="btn btn-outline-secondary" type="submit">Exit
                </div>
            </div>
            <br>
            <div>
                <label>
                    <?php echo " Current directory is:  " ?>
                    <span
                            style="font-weight: bold"><?php echo $dirrun; ?>
                    </span>
                </label>
            </div>
            <br>
            <div class="container list-group">
                <h4>Directory</h4>
                <div class="row">
                    <div class="col">
                        <div class="input-group mb-3 mt-4">
                            <label>Add new directory</label>
                            <div class="input-group">
                                <input type="text" class="form-control" placeholder="name of new direcory"
                                       name="addnewdir">
                                <div class="input-group-append">
                                    <button class="btn btn-outline-secondary" name="createnewdir" type="submit">Add
                                    </button>
                                </div>
                            </div>
                        </div>
                    </div>

                    <div class="col">
                        <div class="input-group mb-3 mt-4">
                            <label>Rename current directory</label>
                            <div class="input-group">
                                <input type="text" class="form-control" placeholder="enter new name for direcory"
                                       name="namenewdir">
                                <div class="input-group-append">
                                    <button name="renamecurrentdir" class="btn btn-outline-secondary" type="submit">
                                        Rename
                                    </button>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <div class="input-group mb-3 mt-4">
                            <label>Delete current directory</label>
                            <div class="input-group">
                                <button name="deletecurrentdir" class="btn btn-outline-secondary" type="submit">
                                    Delete
                                </button>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <br>
            <div class="mt-4 mb-4">
                <h4>Files</h4>
                <label>Add new file into current directory</label>
                <div class="input-group">
                    <div class="custom-file">
                        <input type="file" class="custom-file-input" name="addfiles">
                        <label class="custom-file-label">Choose file</label>
                    </div>
                    <div class="input-group-append">
                        <button name="addnewfile" class="btn btn-outline-secondary" type="submit">Add file</button>
                    </div>
                </div>
            </div>
            <h4>Files in the current folder</h4>
            <?php
            $dirs = scandir($dirrun, GLOB_ONLYDIR);
            if (isset($dirs)) {
                $i = 0;
                foreach ($dirs as $file) {
                    $fullpath = $dirrun . $file;
                    if (is_file($fullpath)) {
                        echo '<div class="form-check">';
                        echo '<input class="form-check-input" type="radio" name="fileslist"';
                        if ($i == 0) echo 'checked ';
                        echo "value=$fullpath>";
                        echo "<label class='form-check-label' for='exampleRadios1'>$file</label>";
                        echo '</div>';
                        $i++;
                    }
                }
                if ($i == 0) {
                    echo '<div class="form-check"><label>Anyone file..</label></div>';

                }
            }
            ?>
    </div>
    <div class="row">
        <div class="col">
            <div class="input-group mb-3 mt-4">
                <label>Rename current file</label>
                <div class="input-group">
                    <input type="text" class="form-control" placeholder="enter new name of file"
                           name="renamefile">
                    <div class="input-group-append">
                        <button class="btn btn-outline-secondary" type="submit">Rename
                        </button>
                    </div>
                </div>
            </div>
        </div>
        <div class="col">
            <div class="col">
                <div class="input-group mb-3 mt-4">
                    <label>Delete current file</label>
                    <div class="input-group">
                        <button value="yes" name="deletecurrentfile" class="btn btn-outline-secondary" type="submit">
                            Delete
                        </button>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <br>
    <div class="row">
        <div class="col">
            <h4>Replace current file</h4>
            <div class="input-group">
                <div class="input-group mb-3">
                    <div class="input-group-prepend">
                        <span class="input-group-text" id="basic-addon3">upload/</span>
                    </div>
                    <input type="text" class="form-control" name="replacefile"
                           placeholder="Enter the name of an existing directory..." aria-describedby="basic-addon3">
                    <div class="input-group-append">
                        <button class="btn btn-outline-secondary" type="submit">Replace
                        </button>
                    </div>
                </div>
            </div>
        </div>
    </div>
    </form>
</div>
</body>
</html>
<?php
ob_end_flush();
?>


