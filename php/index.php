<!DOCTYPE html>
<html>
  <head>
	<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
	<link type="text/css" href="css/shares-theme/jquery-ui-1.8.10.custom.css" rel="stylesheet" />
	<script type="text/javascript" src="js/jquery-1.5.1.js"></script>
	<script type="text/javascript" src="js/jquery-ui-1.8.10.custom.min.js"></script>
	<script type="text/javascript">
	  $(function() 
	    {
		  $('#tabs').tabs();
	    });
	  
	    
	    
	</script>
	<title>Captain's Share The Game</title>	
  </head>
  <body style="background-image:url(./images/stars.png);">
    <div id="tabs">
      <ul id="nav">
        <li><a href="home.php" title="loadedPage">Home</a></li>
        <li><a href="shipstatus.php" title="loadedPage">Ship Status</a></li>
        <li><a href="sectormap.php" title="loadedPage">Sector Map</a></li>
        <li><a href="manifesto.php" title="loadedPage">Manifesto</a></li>
        <li><a href="dockyard.php" title="loadedPage">Dock Yard</a></li>
        <li><a href="unionhall.php" title="loadedPage">Union Hall</a></li>
        <li><a href="passengerlist.php" title="loadedPage">Passenger List</a></li>
        <li><a href="chandlery.php" title="loadedPage">Chandlery</a></li>
        <li><a href="cargospeculation.php" title="loadedPage">Cargo Speculation</a></li>
      </ul>
      <div id="loadedPage"></div>
    </div>
  </body>
</html>