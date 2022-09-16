<?php

header("Access-Control-Allow-Origin: *");

$mysqli = new mysqli("localhost", "root", "", "pw");
if($mysqli->connect_error) {
  exit('Could not connect');
}

$sql = "SELECT nickname , score  FROM highscores order by score asc";
$result = mysqli_query($mysqli,$sql);

while($row = mysqli_fetch_array($result)) {
    echo '<tr><td halign="center">'. $row['nickname'].'</td><td halign="center">'. $row['score'].'</td></tr>'.'*';
   
}
$mysqli->close();
?>