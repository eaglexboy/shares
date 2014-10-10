<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  // Determining if New or Update Good Type was submitted and if so update the DB.
  if(!empty($_POST))
    {
      if(!isset($POST["goodsTypeID"]))
      {
  	  if($_POST["ID"] > 0)
  	  {
  	  	$sql = "UPDATE goodsType SET ";
  	  	$sql = $sql."goodsType=\"".addslashes($_POST["goodsType"])."\",";
  	  	$sql = $sql." WHERE ID=".$_POST["ID"]; 
  	  }
  	  else
  	  {
  	    $sql = "INSERT INTO goodsType VALUES (";
  	  	$sql = $sql."Null, \"".$_POST["goodsType"]."\")";
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
        Type of Goods for Captain's Share the video game.
      </p
    </div>
    <div style="float:left;">
    <div style="text-align:left;float:left;">
      <form id="newGoodsType" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post" name="newGoodsType">
        Type of Goods:
        <?php 
          
          if ($_POST["goodsTypeID"] > 0)
          {
          	$sql = "SELECT * FROM goodsType WHERE ID=".$_POST["goodsTypeID"].";";
          	$results = $mysqlu->query($sql, MYSQLI_STORE_RESULT);
            list($ID, $goodsType)=$results->fetch_row();
            ?>
        <input type="hidden" name="ID" value="<?php echo $ID; ?>"/>
        <input type="text" id="goodsType" size="25" value="<?php echo $goodsType;?>" name="goodsType"/>
        <?php 
          }
          else
          {
          	?>
            <input type="text" id="goodsType" size="25" name="goodsType"/>
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
      <form id="theGoodsType" name="theGoodsType" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        <select id="goodsTypeID" name="goodsTypeID" size="25" onclick="theGoodsType.submit();">
      <?php
        $sql = "SELECT * FROM goodsType;";
        $results = $mysqlu->query($sql, MYSQLI_STORE_RESULT);
        while(list($ID, $goodsType)=$results->fetch_row())
          {
          	if($_POST["goodsTypeID"] == $ID)
          	{
          	  printf("<option value=%d selected=\"selected\">%s</option>", $ID, $goodsType);	
          	}
          	else
          	{
          	  printf("<option value=%d>%s</option>", $ID, $goodsType);
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