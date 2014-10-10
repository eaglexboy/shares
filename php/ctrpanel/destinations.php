<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  // Loading Goods to be placed in the selection list
  $sqlExport = "SELECT goods.ID, goodName, goodsType.goodType FROM goods LEFT JOIN goodsType ON goods.goodType = goodsType.ID;";
  $results = $mysqlu->query($sqlExport);
  $goods = array();
  while(list($ID, $Name, $gt) = $results->fetch_row())
    {
  	  $goods[]=array($ID, $gt." - ".$Name);
    }

  // Determining if New or Update Destination was submitted and if so update the DB.
  if(!empty($_POST))
    {
      if(!isset($_POST["destinations"]))
      {
  	  if($_POST["ID"] > 0)
  	  {
  	  	$sql = "UPDATE destinations SET ";
  	  	$sql = $sql."Name=\"".$_POST["destinationName"]."\",";
  	  	$sql = $sql."Coordinate=GeomFromText('POINT(".$_POST["x_coord"]." ".$_POST["y_coord"].")'),";
  	  	if($_POST["export1"] < 0)
  	  	{
  	  		$sql = $sql."Export1=NULL,";
  	  	}
  	  	else
  	  	{
  	  		$sql = $sql."Export1=".$_POST["export1"].",";
  	  	}
  	    if($_POST["export2"] < 0)
  	  	{
  	  		$sql = $sql."Export2=NULL,";
  	  	}
  	  	else
  	  	{
  	  		$sql = $sql."Export2=".$_POST["export2"].",";
  	  	}
  	    if($_POST["export3"] < 0)
  	  	{
  	  		$sql = $sql."Export3=NULL,";
  	  	}
  	  	else
  	  	{
  	  		$sql = $sql."Export3=".$_POST["export3"].",";
  	  	}
  	    if($_POST["export4"] < 0)
  	  	{
  	  		$sql = $sql."Export4=NULL";
  	  	}
  	  	else
  	  	{
  	  		$sql = $sql."Export4=".$_POST["export4"];
  	  	}
  	  	$sql = $sql." WHERE ID=".$_POST["ID"]; 
  	  }
  	  else
  	  {
  	    $sql = "INSERT INTO destinations VALUES (";
  	  	$sql = $sql."Null, \"".$_POST["destinationName"]."\",";
  	  	$sql = $sql."GeomFromText('POINT(".$_POST["x_coord"]." ".$_POST["y_coord"].")'),";
  	  	if($_POST["export1"] < 0)
  	  	{
  	  		$sql = $sql."NULL,";
  	  	}
  	  	else
  	  	{
  	  		$sql = $sql.$_POST["export1"].",";
  	  	}
  	    if($_POST["export2"] < 0)
  	  	{
  	  		$sql = $sql."NULL,";
  	  	}
  	  	else
  	  	{
  	  		$sql = $sql.$_POST["export2"].",";
  	  	}
  	    if($_POST["export3"] < 0)
  	  	{
  	  		$sql = $sql."NULL,";
  	  	}
  	  	else
  	  	{
  	  		$sql = $sql.$_POST["export3"].",";
  	  	}
  	    if($_POST["export4"] < 0)
  	  	{
  	  		$sql = $sql."NULL)";
  	  	}
  	  	else
  	  	{
  	  		$sql = $sql.$_POST["export4"].")";
  	  	}
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
        Destinations for Captain's Share the video game.
      </p
    </div>
    <div style="float:left;">
    <div style="text-align:left;float:left;">
      <form id="newDestination" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post" name="newDestination">
        Name:
        <?php 
          
          if ($_POST["destinations"] > 0)
          {
          	$sql = "SELECT ID, Name, X(Coordinate) AS X_Coord, Y(Coordinate) AS Y_Coord, Export1, Export2, Export3, Export4 FROM destinations WHERE ID=".$_POST["destinations"].";";
          	$results = $mysqlu->query($sql, MYSQLI_STORE_RESULT);
            list($ID, $Name, $X_Coord, $Y_Coord, $Export1, $Export2, $Export3, $Export4)=$results->fetch_row();
            ?>
        <input type="hidden" name="ID" value="<?php echo $ID; ?>"/>
        <input type="text" id="destinationName" size="25" value="<?php echo $Name;?>" name="destinationName"/><br/>
        Coordinates
        X:
        <input type="text" id="x_coord" size="6" value="<?php echo $X_Coord;?>" name="x_coord"/>
        Y:
        <input type="text" id="y_coord" size="6" value="<?php echo $Y_Coord;?>" name="y_coord"/><br/>
        Exports:<br />
        Export #1:
        <select id="export1" name="export1">
          <option value=-1>Select Export</option>
          <?php
            foreach($goods AS $good){
            	//list($gID, $Name) = $good;
            	if($Export1 == $good[0])
            	{
            		vprintf("<option value=\"%d\" selected=\"selected\">%s</option>", $good);
            		
            	} 
            	else
            	{
            		vprintf("<option value=\"%d\">%s</option>", $good);
            	}
            }
          ?>
        </select>
        <br />
        Export #2:
        <select id="export2" name="export2">
          <option value=-1>Select Export</option>
           <?php
            foreach($goods AS $good){
            	if($Export2 == $good[0])
            	{
            		vprintf("<option value=\"%d\" selected=\"selected\">%s</option>", $good);
            	} 
            	else
            	{
            		vprintf("<option value=\"%d\">%s</option>", $good);
            	}
            }
          ?>
        </select>
        <br />
        Export #3:
        <select id="export3" name="export3">
          <option value=-1>Select Export</option>
           <?php
            foreach($goods AS $good){
            	if($Export3 == $good[0])
            	{
            		vprintf("<option value=\"%d\" selected=\"selected\">%s</option>", $good);
            	} 
            	else
            	{
            		vprintf("<option value=\"%d\">%s</option>", $good);
            	}
            }
          ?>
        </select>
        <br />
        Export #4:
        <select id="export4" name="export4">
          <option value=-1>Select Export</option>
           <?php
            foreach($goods AS $good){
            	if($Export4 == $good[0])
            	{
            		vprintf("<option value=\"%d\" selected=\"selected\">%s</option>", $good);
            	} 
            	else
            	{
            		vprintf("<option value=\"%d\">%s</option>", $good);
            	}
            }
          ?>
        </select>    
            <?php 
          }
          else
          {
          	?>
        <input type="text" id="destinationName" size="25" name="destinationName"/><br/>
        Coordinates
        X:
        <input type="text" id="x_coord" size="6" name="x_coord"/>
        Y:
        <input type="text" id="y_coord" size="6" name="y_coord"/><br/>
        Exports:<br />
        Export #1:
        <select id="export1" name="export1">
          <option value=-1>Select Export</option>
           <?php
            foreach($goods AS $good){
                vprintf("<option value=\"%d\">%s</option>", $good);
              }
          ?>
        </select>
        <br />
        Export #2:
        <select id="export2" name="export2">
          <option value=-1>Select Export</option>
           <?php
            foreach($goods AS $good){
                vprintf("<option value=\"%d\">%s</option>", $good);
              }
          ?>
        </select>
        <br />
        Export #3:
        <select id="export3" name="export3">
          <option value=-1>Select Export</option>
           <?php
            foreach($goods AS $good){
                vprintf("<option value=\"%d\">%s</option>", $good);
              }
          ?>
        </select>
        <br />
        Export #4:
        <select id="export4" name="export4">
          <option value=-1>Select Export</option>
           <?php
            foreach($goods AS $good){
                vprintf("<option value=\"%d\">%s</option>", $good);
              }
          ?>
        </select>
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
      <form id="theDestinations" name="theDestinations" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        <select id="destinations" name="destinations" size="25" onclick="theDestinations.submit();">
      <?php
        $sql = "SELECT ID, Name, X(Coordinate) AS X_Coord, Y(Coordinate) AS Y_Coord FROM destinations;";
        $results = $mysqlu->query($sql, MYSQLI_STORE_RESULT);
        while(list($ID, $Name, $X_Coord, $Y_Coord)=$results->fetch_row())
          {
          	if($_POST["destinations"] == $ID)
          	{
          	  printf("<option value=%d selected=\"selected\">%s - location (%2.2f, %2.2f)</option>", $ID, $Name, $X_Coord, $Y_Coord);	
          	}
          	else
          	{
          	  printf("<option value=%d>%s - location (%2.2f, %2.2f)</option>", $ID, $Name, $X_Coord, $Y_Coord);
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
 // close_db(); 
?>