<?php

function chooseDir($currentDir)
{
    $dirs = scandir($currentDir, GLOB_ONLYDIR);
    if (isset($dirs)) {
        foreach ($dirs as $dir) {
            $fullpath = $currentDir . $dir;
            if (is_dir($fullpath)) {
                if ($dir != "." && $dir != "..") {
                    if ($dir != UPLOAD_DIR) {
                    }
                    echo "<option value='{$fullpath}'>$fullpath</option>";
                }
            }
        }
    }
}