<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  $sql = "SELECT ID, engineName, engineSpeed FROM engines WHERE shipCompatibility=".$_GET["ID"].";";
  $results = $mysqlu->query($sql);
  $output = "[";
  while(list($ID, $Name, $Speed)=$results->fetch_rows())
  {
  	$output = $output."{optionValue:".$ID.", optionDisplay:'".$Name." (".$Speed." BU)'},";
  }
  $output = substr($output,0,(strlen($output)-1))."]";
  
  echo $output
?>