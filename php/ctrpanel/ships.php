<?php  
  // Including global configuration files
  include('init.inc.php');
  include($db);
  
  //Determing if Update/New was submitted
  if(!empty($_POST))
  {
  	if(!isset($_POST["theShipID"]))
      {
      	if($_POST["theShipID"] > 0)
      	{
      		$sql ="UPDATE ships SET (shipName, shipSize, shipEmptyWeight, cargoRating, crewSize, passengers, ";
      		$sql = $sql."engineType, powerType, waterCapacity, oxygenCapacity, volatilesCapacity, environmentalMatrixLevel, ";
      		$sql = $sql."foodCapacity, shipShares) VALUES (\"".$_POST["shipName"]."\", ".$_POST["shipClass"].", ".$_POST["emptyWeight"].", ";
      		$sql = $sql.$_POST["maxCargo"].", ".$_POST["crewSize"].", ".$_POST["passenger"].", ".$_POST["engine"].", ";
      		$sql = $sql.$_POST["power"].", ".$_POST["water"].", ".$_POST["o2"].", ".$_POST["volatiles"].", ";
      		$sql = $sql.$_POST["enviorment"].", ".$_POST["food"].", ".$_POST["shares"].") WHERE ID=".$_POST["ID"].";";
      	}
      	else
      	{
      		$sql ="INSERT INTO ships (shipName, shipSize, shipEmptyWeight, cargoRating, crewSize, passengers, ";
      		$sql = $sql."engineType, powerType, waterCapacity, oxygenCapacity, volatilesCapacity, environmentalMatrixLevel, ";
      		$sql = $sql."foodCapacity, shipShares) VALUES (\"".$_POST["shipName"]."\", ".$_POST["shipClass"].", ".$_POST["emptyWeight"].", ";
      		$sql = $sql.$_POST["maxCargo"].", ".$_POST["crewSize"].", ".$_POST["passenger"].", ".$_POST["engine"].", ";
      		$sql = $sql.$_POST["power"].", ".$_POST["water"].", ".$_POST["o2"].", ".$_POST["volatiles"].", ";
      		$sql = $sql.$_POST["enviorment"].", ".$_POST["food"].", ".$_POST["shares"].");";
      	}
      }  	
  }
  
  // Loading ship Types
  $sql = "SELECT * FROM shiptypes";
  $results = $mysqlu->query($sql);
  $shipTypes = array();
  while(list($ID, $Name) = $results->fetch_row())
  {
  	$shipTypes[]=array($ID, $Name);
  }
  
?>
<!doctype html>
<html>
  <head>
    <title>Captain's Share Control Panel</title>
    <script type="text/javascript" src="./../js/jquery-1.5.1.js"></script>
    <script type="text/javascript">
      $(function(){
    	  $("select#shipType").change(function(){
    	    $.getJSON("enginelist.php",{ID: $(this).val(), ajax: 'true'}, function(j){
    	      var options = '';
    	      for (var i = 0; i < j.length; i++) {
    	        options += '<option value="' + j[i].optionValue + '">' + j[i].optionDisplay + '</option>';
    	      }
    	      $("select#engine").html(options);
    	    })
    	    $.getJSON("powerlist.php",{ID: $(this).val(), ajax: 'true'}, function(j){
    	      var options = '';
    	      for (var i = 0; i < j.length; i++) {
    	        options += '<option value="' + j[i].optionValue + '">' + j[i].optionDisplay + '</option>';
    	      }
    	      $("select#power").html(options);
    	    })
    	  })
    	})
    	      
    </script>
  </head>
  <body>
    <div style="float:left;">
      <div style="text-align:left;float:left;">
        <form id="theShip" name="theShip" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          Ship Name:
          <?php
            if($_POST["theShipID"] > 0)
            {
            	$sql = "SELECT ID, shipName, shipSize, shipEmptyWeight, cargoRating, crewSize, passengers, engineType, powerType, ";
            	$sql = $sql."waterCapacity, oxygenCapacity, volatilesCapacity, environmentalMatrixLevel, foodCapacity, shipShares FROM ships WHERE ID=".$_POST["theShipID"].";";
            	$results = $mysqlu->query($sql);
            	list($ID, $Name, $Class, $emptyWeight, $maxCargo, $crew, $passengers, $engine, $power, $water, $o2, $volitiles, $enviorment, $food, $shares) = $results->fetch_row();
            	?>
            	<input type="hidden" name="ID" value="<?php echo $ID; ?>" />
            	<input type="text" name="shipName" value="<?php echo $Name?>" /><br/>
          Ship Type:
          <select name="shipType">
            <option value="-1">Select Ship Type</option>
            <?php 
              foreach($shipTypes AS $shipType)
              {
                vprintf("<option value=\"%d\">%s</option>", $shipType);
              }
            ?>
          </select><br/>
          Ship Class:
          <select name="shipClass">
            <option value="-1">Select Ship Class</option>
          </select>
          <br/>
          Ship Empty Weight:
          <input type="text" name="emptyWeight" value="<?php echo $emptyWeight; ?>" />MTons
          <br/>
          Max Cargo:
          <input type="text" name="maxCargo" value="<?php echo $maxCargo; ?>" />
          <br/>
          Crew Size:
          <input type="text" name="crewSize" value="<?php echo $crew; ?>" />
          <br/>
          Passengers:
          <input type="text" name="passengers" value="0" />
          <br/>
          Engine:
          <select name="engine">
            <option value="-1">Select Engine</option>
          </select>
          <br/>
          Power:
          <select name="power">
            <option value="-1">Select Power Source</option>
          </select>
          <br/>
          Water Capacity:
          <input type="text" name="water" value="<?php echo $water;?>" />
          <br/>
          O<sub>2</sub> Capacity:
          <input type="text" name="o2" value="<?php echo $o2; ?>" />
          <br/>
          Volatiles Capacity:
          <input type="text" name="volatiles" value="<?php echo $volatiles; ?>" />
          <br/>
          Food Capacity:
          <input type="text" name="food" value="<?php echo $food; ?>" />
          <br/>
          Enviormental Matrix:
          <input type="text" name="enviorment" value="<?php echo $enviorment; ?>" />
          <br/>
          Ship Shares:
          <input type="text" name="shares" value="<?php echo $shares; ?>" />
          <br/>
          <?php
           
            } 
            else
            {
          ?>
          <input type="text" name="shipName" /><br/>
          Ship Type:
          <select name="shipType">
            <option value="-1">Select Ship Type</option>
            <?php 
              foreach($shipTypes AS $shipType)
              {
                vprintf("<option value=\"%d\">%s</option>", $shipType);
              }
            ?>
          </select><br/>
          Ship Class:
          <select name="shipClass">
            <option value="-1">Select Ship Class</option>
          </select>
          <br/>
          Ship Empty Weight:
          <input type="text" name="emptyWeight" />MTons
          <br/>
          Max Cargo:
          <input type="text" name="maxCargo" />
          <br/>
          Crew Size:
          <input type="text" name="crewSize" />
          <br/>
          Passengers:
          <input type="text" name="passengers" value="0" />
          <br/>
          Engine:
          <select name="engine">
            <option value="-1">Select Engine</option>
          </select>
          <br/>
          Power:
          <select name="power">
            <option value="-1">Select Power Source</option>
          </select>
          <br/>
          Water Capacity:
          <input type="text" name="water" value="0" />
          <br/>
          O<sub>2</sub> Capacity:
          <input type="text" name="o2" value="0" />
          <br/>
          Volatiles Capacity:
          <input type="text" name="volatiles" value="0" />
          <br/>
          Food Capacity:
          <input type="text" name="food" value="100" />
          <br/>
          Enviormental Matrix:
          <input type="text" name="enviorment" value="100" />
          <br/>
          Ship Shares:
          <input type="text" name="shares" value="0" />
          <br/>
          <?php 
            }
          ?>
          <br/>
        </form>        
        <input type="submit" onclick="validateForm();" value="Submit" name="submit"/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <input type="reset" value="Reset" />
      </div>
      <div style="text-align:right;float:left;margin-left:100px;">
        <form id="theShips" name="theShips" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
          <select name="theShipID" onclick="theShips.submit();" size="25">
            <?php
              $sql = "SELECT ships.ID, shipName, manufacturers.manufacturer,  model, cargoRating FROM ships LEFT JOIN (models LEFT JOIN manufacturers ON models.manufacturer=manufacturers.ID) ON ships.shipSize=models.ID;";
              $results = $mysqlu->query($sql);
              while(list($ID, $Name, $Maker, $Class, $Rating) = $results->fetch_row())
              {
              	if($_POST["theShipID"] = $ID)
              	{
              		printf("<options value=\"%d\" selected=\"selected\">%s</options>", $ID, $Maker." - ".$Class." - ".$Name." (".$Rating." MTons");
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