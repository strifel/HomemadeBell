<?php
if ($_GET['key'] == 'key') {
    $myfile = fopen("bell.txt", "w") or die("Unable to open file!");
    fwrite($myfile, time() . "\n");
    fclose($myfile);
} else {
    die("No key provided.");
}
