<!doctype html>
<html>
  <head>
    <title>Captain's Share Control Panel</title>
  </head>
  <body>
    <div style="text-align:center;">
    <?php
      $text = "Welcome to Captain's Share Control Panel";
      echo "$text"; 
    ?>
      <br/>
      Please select a function to perform.
    </div>
    <div>
      <p>
        <input type="button" onclick="window.location.href='destinations.php'" value="Destinations" />
        <input type="button" onclick="window.location.href='goodstype.php'" value="Type of Goods" />
        <input type="button" onclick="window.location.href='shiptype.php'" value="Type of Ship" />
        <input type="button" onclick="window.location.href='engines.php'" value="Engines" />
        <input type="button" onclick="window.location.href='goods.php'" value="Goods" />
        <input type="button" onclick="window.location.href='manufacturers.php'" value="Manufacturers" />
        <input type="button" onclick="window.location.href='type.php'" value="Ship Class" />
        <input type="button" onclick="window.location.href='power.php'" value="Power Source" />
        <input type="button" onclick="window.location.href='ships.php'" value="Ships" />
      </p>
    </div>
    
  </body>
</html>