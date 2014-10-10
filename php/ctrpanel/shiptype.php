<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  // Determining if New or Update Type of Ship was submitted and if so update the DB.
  if(!empty($_POST))
    {
    if(!isset($_POST["shipTypeID"])){
  	  if($_POST["ID"] > 0)
  	  {
  	  	$sql = "UPDATE shiptypes SET ";
  	  	$sql = $sql."shipType=\"".addslashes($_POST["shipType"])."\",";
  	  	$sql = $sql." WHERE ID=".$_POST["ID"]; 
  	  }
  	  else
  	  {
  	    $sql = "INSERT INTO shiptypes VALUES (";
  	  	$sql = $sql."Null, \"".$_POST["shipType"]."\")";
  	  }
  	  $result = $mysqlu->query($sql); 
    }
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
        Type of Ship for Captain's Share the video game.
      </p
    </div>
    <div style="float:left;">
    <div style="text-align:left;float:left;">
      <form id="newShipType" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post" name="newShipType">
        Type of Ship:
        <?php 
          
          if ($_POST["shipTypeID"] > 0)
          {
          	$sql = "SELECT * FROM shiptypes WHERE ID=".$_POST["shipTypeID"].";";
          	$results = $mysqlu->query($sql, MYSQLI_STORE_RESULT);
            list($ID, $shipType)=$results->fetch_row();
            ?>
        <input type="hidden" name="ID" value="<?php echo $ID; ?>"/>
        <input type="text" id="shipType" size="25" value="<?php echo $shipType;?>" name="shipType"/>
        <?php 
          }
          else
          {
          	?>
            <input type="text" id="shipType" size="25" name="shipType"/>
            <?php 
          }
        ?>
        <br />
        <input type="submit" onclick="validateForm();" value="Submit" name="submit"/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <input type="reset" value="Reset" />
      </form>
    </div>
      <div style="text-align:right;float:left;margin-left:100px;">
      <form id="theShipType" name="theShipType" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        <select id="shipTypeID" name="shipTypeID" size="25" onclick="theShipType.submit();">
      <?php
        $sql = "SELECT * FROM shiptypes;";
        $results = $mysqlu->query($sql, MYSQLI_STORE_RESULT);
        while(list($ID, $shipType)=$results->fetch_row())
          {
          	if($_POST["shipTypeID"] == $ID)
          	{
          	  printf("<option value=%d selected=\"selected\">%s</option>", $ID, $shipType);	
          	}
          	else
          	{
          	  printf("<option value=%d>%s</option>", $ID, $shipType);
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
<?php
  close_db(); 
?>