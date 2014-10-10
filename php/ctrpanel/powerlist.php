<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  $sql = "SELECT ID, powerName, powerOutput FROM powerSources WHERE shipCompatibility=".$_GET["ID"].";";
  $results = $mysqlu->query($sql);
  $output = "[";
  while(list($ID, $Name, $Power)=$results->fetch_rows())
  {
  	$output = $output."{optionValue:".$ID.", optionDisplay:'".$Name." (".$power." GWatts)'},";
  }
  $output = substr($output,0,(strlen($output)-1))."]";
  
  echo $output
?>