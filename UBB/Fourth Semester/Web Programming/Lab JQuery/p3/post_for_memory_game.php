<?php

header("Access-Control-Allow-Origin: *");

$mysqli = new mysqli("localhost", "root", "", "pw");
if($mysqli->connect_error) {
  exit('Could not connect');
}
$nickname=$_POST['nickname'];
$score= $_POST['score'];

$sql = "INSERT INTO highscores (nickname, score) VALUES ('".$nickname."',".$score.")";
$result = mysqli_query($mysqli,$sql);

echo $result;

$mysqli->close();
?>