<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  // Determining if a Update/New entry was submitted.
  if(!empty($_POST))
  {
  	if(!isset($_POST["theGoodsID"]))
  	{
  	if($_POST["ID"] > 0)
  	{
  	  $sql = "UPDATE goods SET ";
  	  $sql = $sql."goodName=\"".$_POST["goodName"]."\", ";
  	  $sql = $sql."goodType=".$_POST["goodType"]." WHERE ID=".$_POST["ID"].";";
  	}
  	else
  	{
  	  $sql = "INSERT INTO goods	VALUES (NULL, ";
  	  $sql = $sql.$_POST["goodName"].", ";
  	  $sql = $sql.$_POST["goodType"].")";
  	}
  	
  	$result = $mysqlu->query($sql);
  }
  }
  
  // Getting list of GoodType
  $sql = "SELECT * FROM goodsType;";
  $goodTypes = array();
  $result = $mysqlu->query($sql);
  while(list($ID, $Name) = $result->fetch_row())
  {
  	$goodTypes[]=array($ID, $Name);
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
        Goods for Captain's Share the video game.
      </p
    </div>
    <div style="float:left;">
      <div style="text-align:left;float:left;">
        <form name="theGood" id="theGood" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          Good Name:
          <?php 
          if ($_POST["theGoodsID"] > 0)
          {
          	$sql = "SELECT * FROM goods WHERE ID=\"".$_POST["theGoodsID"]."\";";
          	$results = $mysqlu->query($sql);
          	list($ID, $goodName, $goodTypeID) = $results->fetch_row();
          ?>
          <input type="hidden" name="ID" value="<?php echo $ID; ?>" />
          <input type="text" name="goodName" value="<?php echo $goodName; ?>" /><br/>
          Good Type:
          <select name="goodType">
            <option value="-1">Select Good Type</option>
            <?php
              foreach($goodTypes AS $goodType)
              {
              	if ($goodType->$ID == $goodTypeID)
              	{
              	  vprintf("<option value=\"%d\" selected=\"selected\">%s</option>", $goodType); 
              	}
              	else
              	{
                  vprintf("<option value=\"%d\">%s</option>", $goodType);
              	} 
              }
            ?>
          </select>
          <?php
          }
          else
          {
          ?>
          <input type="text" name="goodName" /><br/>
          Good Type:
          <select name="goodType">
            <option value="-1">Select Good Type</option>
            <?php
              foreach($goodTypes AS $goodType)
                vprintf("<option value=\"%d\">%s</option>", $goodType); 
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
        <form name="theGoods" id="theGoods"  action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          <select name="theGoodsID" onclick="theGoods.submit()" size="25">
            <?php
              $sql = "SELECT goods.ID, goods.goodName, goodsType.goodType FROM goods LEFT JOIN goodsType ON goods.goodType = goodsType.ID;";
              $results = $mysqlu->query($sql);
              while(list($ID, $goodName, $goodTypeID) = $results->fetch_row())
              {
             	if($_POST["theGoodsID"] == $ID)
              	{
              	  printf("<option value=\"%d\" selected=\"selected\">%s</option>", $ID, $goodTypeID." - ".$goodName);
              	}
              	else
              	{
              	  printf("<option value=\"%d\">%s</option>", $ID, $goodTypeID." - ".$goodName);
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