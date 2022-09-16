<?php

header("Access-Control-Allow-Origin: *");

$mysqli = new mysqli("localhost", "root", "", "pw");
if($mysqli->connect_error) {
  exit('Could not connect');
}

$sql = "SELECT plecari FROM orase";
$result = mysqli_query($mysqli,$sql);

while($row = mysqli_fetch_array($result)) {
  echo "<option>" . $row['plecari'] . "</option>";
}

$mysqli->close();
?>