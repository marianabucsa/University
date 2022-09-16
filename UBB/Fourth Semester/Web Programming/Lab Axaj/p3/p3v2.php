<?php

header("Access-Control-Allow-Origin: *");
$mysqli = new mysqli("localhost", "root", "", "routes");


$sql2 = "SELECT * FROM elevi WHERE nrMatricol = ?;";
$stmt = $mysqli->prepare($sql2);
$stmt -> bind_param('d', $_GET['id']);
$stmt -> execute();
$stmt -> bind_result($aux, $col1, $col2, $col3);



echo "<form>";

while($stmt -> fetch()){
	//echo "$aux";
	//echo "$col1";
	//echo "$col2";
	//echo "$col3";
  echo "<label for=\"fname\">First name:</label><br>";
  echo "<input type=\"text\" id=\"fname\" name=\"fname\" value=" . $col2 . "><br>";
  echo "<label for=\"lname\">Last name:</label><br>";
  echo "<input type=\"text\" id=\"lname\" name=\"lname\" value=" . $col3 . "><br>";
  echo "<label for=\"pnum\">Phone number:</label><br>";
  echo "<input type=\"text\" id=\"pnum\" name=\"pnum\" value=" . $col1 . "><br>";
}

echo "<input type=\"submit\" value=\"Submit\" onclick=\"save()\"";
echo "</form>";
 ?>