<?php 
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  // Determining if New/Update has been sent
  if(!empty($_POST))
  {
  	if(!isset($_POST["theEnginesID"]))
  	{
  	if($_POST["ID"] > 0)
  	{
  	  $sql = "UPDATE engines SET ";
  	  $sql = $sql."engineName=\"".$_POST["engineName"]."\", ";
  	  $sql = $sql."engineSpeed=".$_POST["engineSpeed"].", ";
  	  $sql = $sql."shipCompatibility=".$_POST["shipCompatibility"].", ";
  	  $sql = $sql."enginePrice=".$_POST["enginePrice"].";";	
  	}
  	else
  	{
  	  $sql = "INSERT INTO engine values(NULL, ";
  	  $sql = $sql.$_POST["engineName"].", ";
  	  $sql = $sql.$_POST["engineSpeed"].", ";
  	  $sql = $sql.$_POST["shipCompatibility"].", ";
  	  $sql = $sql.$_POST["enginePrice"].");";	
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
        Engine Types for Captain's Share the video game.
      </p
    </div>
    <div style="float:left;">
      <div style="text-align:left;float:left;">
        <form name="theEngine" id="theEngine" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          <?php 
            if($_POST["theEnginesID"] > 0)
            {
              $sql = "SELECT * FROM engines WHERE ID=".$_POST["theEnginesID"].";";
              $results = $mysqlu->query($sql);
              list($ID, $engineName, $engineSpeed, $shipCompatibility, $enginePrice) = $result->fetch_row();
              ?>
          <input type="hidden" name="ID" value="<?php echo $ID; ?>"/>
          Engine Name:
          <input type="text" name="engineName" value="<?php echo $engineName; ?>" /><br/>
          Engine Speed:
          <input type="text" name="engineSpeed" value="<?php echo $engineSpeed; ?>" /><br/>
          Ship Compatability:
          <select name="shipType">
            <option value="-1">Select Ship Type</option>
            <?php
              foreach($ships AS $ship)
              {
              	if($ship->$ID == $shipCompatibility)
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
          Engine Price:
          <input type="text" name="enginePrice" value="<?php echo $enginePrice; ?>" /><br/>
          <?php 
            }
            else
            {
            ?>
              Engine Name:
              <input type="text" name="engineName" /><br/>
              Engine Speed:
              <input type="text" name="engineSpeed" /><br/>
              Ship Compatability:
              <select name="shipType">
                <option value="-1">Select Ship Type</option>
                <?php
                  foreach($ships AS $ship){
                    vprintf("<option value=\"%d\">%s</option>", $ship);
                  }
                ?>
              </select><br/>
              Engine Price:
              <input type="text" name="enginePrice" value="0.00" onclick="this.value=''" onblur="javascript:if(len(this.value)<1){this.value='0.00'}" /><br/>
              <?php
            }
          ?> 
          <input type="submit" onclick="validateForm();" value="Submit" name="submit"/>
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <input type="reset" value="Reset" />
        </form>
      </div>
      <div style="text-align:right;float:left;margin-left:100px;">
        <form name="theEngines" id="theEngines" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          <select name="theEngines" id="theEngines" size="10">
            <?php 
              $sql = "SELECT ID, engineName FROM engines;";
              $result = $mysqlu->query($sql);
              while(list($ID, $engineName) = $result->fetch_row())
                {
              	  if ($_POST["theEnginesID"] == $ID)
              	    {
              	  	  printf("<option value=\"$ID\" selected=\"selected\">%s</option>", $ID, $engineName);
              	    }
              	  else
              	    {
              	  	  printf("<option value=\"$ID\">%s</option>", $ID, $engineName);
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