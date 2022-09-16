<?php

header("Access-Control-Allow-Origin: *");

$mysqli = new mysqli("localhost", "root", "", "pw");
if($mysqli->connect_error) {
  exit('Could not connect');
}

$statiePlecare=$_GET['statiePlecare'];
$sql = "SELECT sosiri FROM orase WHERE plecari = '".$statiePlecare."'";
$result = mysqli_query($mysqli,$sql);

while($row = mysqli_fetch_array($result)) {
  echo "<option>" . $row['sosiri'] . "</option>";
}

$mysqli->close();

?>