<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  // Determining if a Update/New entry was submitted.
  if(!empty($_POST))
  {
  	if(!isset($_POST[""]))
	{
		if($_POST["ID"] > 0)
		{
		  $sql = "UPDATE models SET ";
		  $sql = $sql."manufacturer=".$_POST["Maker"].", ";
		  $sql = $sql."model=\"".$_POST["Class"]."\" WHERE ID=".$_POST["ID"].";";
		}
		else
		{
		  $sql = "INSERT INTO models VALUES (NULL, ";
		  $sql = $sql.$_POST["Maker"].", ";
		  $sql = $sql.$_POST["Class"].")";
		}
  	//$result = $mysqlu->query($sql)
	}
  }
  
  // Getting list of GoodType
  $sql = "SELECT * FROM manufacturers;";
  $Makers = array();
  $result = $mysqlu->query($sql);
  while(list($ID, $Name) = $result->fetch_row())
  {
  	$Makers[]=array($ID, $Name);
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
        Ship Classes for Captain's Share the video game.
      </p
    </div>
    <div style="float:left;">
      <div style="text-align:left;float:left;">
        <form name="theGood" id="theGood" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          Ship Class:
          <?php 
          if ($_POST["shipClassID"] > 0)
          {
          	$sql = "SELECT * FROM models WHERE ID=\"".$_POST["shipClassID"]."\";";
          	$results = $mysqlu->query($sql);
          	list($ID, $Maker, $Name) = $results->fetch_row();
          ?>
          <input type="hidden" name="ID" value="<?php echo $ID; ?>" />
          <input type="text" name="Class" value="<?php echo $Name; ?>" /><br/>
          Manufacturer:
          <select name="Maker">
            <option value="-1">Select Manufacturer Type</option>
            <?php
              foreach($Makers AS $MakerArr)
              {
              	if ($MakerArr->$ID == $Maker)
              	{
              	  vprintf("<option value=\"%d\" selected=\"selected\">%s</option>", $MakerArr); 
              	}
              	else
              	{
                  vprintf("<option value=\"%d\">%s</option>", $MakerArr);
              	} 
              }
            ?>
          </select>
          <?php
          }
          else
          {
          ?>
          <input type="text" name="Class" /><br/>
          Manufacturer:
          <select name="Maker">
            <option value="-1">Select Manufacturer Type</option>
            <?php
              foreach($Makers AS $MakerArr)
                vprintf("<option value=\"%d\">%s</option>", $MakerArr); 
            ?>
          </select>
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
        <form name="theMakers" id="theMakers"  action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          <select name="shipClassID" onclick="theMakers.submit()" size="25">
            <?php
              $sql = "SELECT models.ID, manufacturers.manufacturer, model FROM models LEFT JOIN manufacturers ON models.manufacturer = manufacturers.ID;";
              $results = $mysqlu->query($sql);
              while(list($ID, $Maker, $Name) = $results->fetch_row())
              {
             	if($_POST["shipClassID"] == $ID)
              	{
              	  printf("<option value=\"%d\" selected=\"selected\">%s</option>", $ID, Maker." - ".$Name);
              	}
              	else
              	{
              	  printf("<option value=\"%d\">%s</option>", $ID, $Maker." - ".$Name);
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