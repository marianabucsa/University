<?php

header("Access-Control-Allow-Origin: *");
$mysqli = new mysqli("localhost", "root", "", "routes");

$sql = "UPDATE elevi SET nume=?, prenume=?, telefon=? WHERE nrMatricol=?;";
$stmt = $mysqli->prepare($sql);
$stmt -> bind_param("sssd", $_GET['fname'], $_GET['lname'], $_GET['pnum'], $_GET['id']);
$stmt -> execute();

 ?>