<?php

header("Access-Control-Allow-Origin: *");

$mysqli = new mysqli("localhost", "root", "", "routes");

$sql = "SELECT nrMatricol FROM elevi;";
$result = $mysqli -> query($sql);

echo "<select id=\"select\" onchange=\"fillform(this.value)\">";
while($row = mysqli_fetch_array($result)){
	
  echo "<option value=\" ".$row[0]. "\"> ".$row[0]."</option>";
  
}
echo "</select>";

?>