<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  //Determining is New/Update data submitted
  if(!empty($_POST))
  {
  	if(!isset($_POST["pwrID"]))
      {
      	if($_POST["ID"] > 0)
      	{
      	  $sql = "UPDATE powerSources SET ";
      	  $sql = $sql."powerName=".$_POST["pwrName"].", ";
      	  $sql = $sql."powerOutput=".$_POST["output"].", ";
      	  $sql = $sql."shipCompatibility=".$_POST["shipCompatibility"].", ";
      	  $sql = $sql."powerPrice=".$_POST["price"].", WHERE ID=".$_POST["ID"].";";
      	}
      	else
      	{
      		$sql = "INSERT INTO powerSources VALUES (";
      		$sql = $sql."NULL,\"".$_POST["pwrName"]."\", ";
      		$sql = $sql.$_POST["output"].", ".$_POST["shipCompatibility"].", ";
      		$sql = $sql.$_POST["price"].");";
      	}
      	$result = $mysqlu->query($sql);
      }
  }
  
  // Loading the ShipTypes
  $sql = "SELECT * FROM shiptypes;";
  $result = $mysqlu->query($sql);
  $ships = array();
  while(list($ID, $shipType) = $result->fetch_row())
  {
  	$ships[] = array($ID, $shipType);
  }
  
?>
<!doctype html>
<html>
  <head>
    <title>Captain's Share Control Panel</title>
  </head>
  <body>
    <div style="text-align:center;">
      <p>
        Power Sources for Captain's Share the video game.
      </p
    </div>
    <div style="float:left;">
      <div style="text-align:left;float:left;">
        <form name="powerSource" id="powerSource"  action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          Name:
          <?php 
            if ($_POST["pwrID"] > 0)
            {
              $sql = "SELECT * FROM powerSources WHERE ID=".$_POST["pwrID"].";";
              $results = $mysqlu->query($sql);
              list($ID, $Name, $Output, $shipCompatibility, $Price) = $results->fetch_row();
             ?>
          <input type="hidden" name="ID" value="<?php echo $ID; ?>" />
          <input type="text" name="pwrName" value="<?php echo $Name;?>" /><br/>
          Output:
          <input type="text" name="output" value="<?php echo $Output; ?>" /><br/>
          Ship Compatibility:
          <select name="shipType">
            <option value="-1">Select Ship Type</option>
            <?php
              foreach($ships AS $ship)
              {
              	if($ship[0] == $shipCompatibility)
              	{
              		vprintf("<option value=\"%d\" selected=\"selected\">%s</option>", $ship);
              	}
              	else
              	{
              	    vprintf("<option value=\"%d\">%s</option>", $ship);
              	}
              }
              ?>
            </select><br/>
          Price:
          <input type="text" name="price" value="<?php echo $Price; ?>" />
             <?php  	
            }
            else
            {
          ?>
          <input type="text" name="pwrName" /><br/>
          Output:
          <input type="text" name="output" /><br/>
          Ship Compatibility:
          <select name="shipType">
            <option value="-1">Select Ship Type</option>
            <?php
              foreach($ships AS $ship)
              {
              	    vprintf("<option value=\"%d\">%s</option>", $ship);
              }
              ?>
            </select><br/>
          Price:
          <input type="text" name="price" value="0.00" />
          <?php 
            }
          ?>
          <br/>
          <input type="submit" onclick="validateForm();" value="Submit" name="submit"/>
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <input type="reset" value="Reset" />
          
        </form>
      </div>
      <div style="text-align:right;float:left;margin-left:100px;">
        <form name="powerSources" id="powerSources"  action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          <select name="pwrID" size="15">
            <?php
              $sql = "SELECT ID, powerName, powerOutput FROM powerSources;";
              $results = $mysqlu->query($sql);
              while(list($ID, $Name, $Output) = $results->fetch_row())
              {
              	if($_POST["pwrID"] == $ID)
              	  {
              	    printf("<option value\"%d\" selected=\"selected\">%s</option>", $ID, $Name." (".$Output."BU)");
              	  }
              	else
              	  {
              	    printf("<option value\"%d\">%s</option>", $ID, $Name." (".$Output."BU)");
              	  }
              }
            ?>
          </select>
        </form>
      </div>
    </div>
    <?php include("menu.html"); ?>
  </body>
</html>