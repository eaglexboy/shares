<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  // Determining if New or Update Good Type was submitted and if so update the DB.
  if(!empty($_POST))
    {
      if(!isset($_POST["MakerID"]))
      {
  	  if($_POST["ID"] > 0)
  	  {
  	  	$sql = "UPDATE manufacturers SET ";
  	  	$sql = $sql."goodsType=\"".addslashes($_POST["Maker"])."\",";
  	  	$sql = $sql." WHERE ID=".$_POST["ID"]; 
  	  }
  	  else
  	  {
  	    $sql = "INSERT INTO manufacturers VALUES (";
  	  	$sql = $sql."Null, \"".$_POST["Maker"]."\")";
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
        Manufacturers for Captain's Share the video game.
      </p
    </div>
    <div style="float:left;">
    <div style="text-align:left;float:left;">
      <form id="newMaker" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post" name="newMaker">
        Manufacturer:
        <?php 
          
          if ($_POST["MakerID"] > 0)
          {
          	$sql = "SELECT * FROM manufacturers WHERE ID=".$_POST["MakerID"].";";
          	$results = $mysqlu->query($sql, MYSQLI_STORE_RESULT);
            list($ID, $Maker)=$results->fetch_row();
            ?>
        <input type="hidden" name="ID" value="<?php echo $ID; ?>"/>
        <input type="text" id="Maker" size="25" value="<?php echo Maker;?>" name="Maker"/>
        <?php 
          }
          else
          {
          	?>
            <input type="text" id="Maker" size="25" name="Maker"/>
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
      <form id="theMakers" name="theMakers" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        <select id="MakerID" name=MakerID size="25" onclick="theMakers.submit();">
      <?php
        $sql = "SELECT * FROM manufacturers;";
        $results = $mysqlu->query($sql, MYSQLI_STORE_RESULT);
        while(list($ID, $Maker)=$results->fetch_row())
          {
          	if($_POST["MakerID"] == $ID)
          	{
          	  printf("<option value=%d selected=\"selected\">%s</option>", $ID, $Maker);	
          	}
          	else
          	{
          	  printf("<option value=%d>%s</option>", $ID, $Maker);
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
  //close_db(); 
?>