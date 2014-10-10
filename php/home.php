<?php
  // This is loaded if not logged in
?>
<script type="text/javascript">  

$(function() {
	$( '#dialog' ).dialog({
		autoOpen: false,
		modal: true,
		resizable: false,
		buttons: {
			Cancel: function() {
				$( this ).dialog( "close" );
			}
		}
	});

	$("#submit").click(function(){
		$("#dialog").dialog("open");
	});


	

$( "#newAccountInfo" ).dialog({
	autoOpen: false,
	height: 310,
	width: 500,
	modal: true,
	resizable: false,
	buttons: {
		"Create an account": function() {		 
				$( this ).dialog( "close" );
			
		},
		Cancel: function() {
			$( this ).dialog( "close" );
		}
	},
	close: function() {
		allFields.val( "" ).removeClass( "ui-state-error" );
	}
});

$( "#newAccount" )
	.button()
	.click(function() {
		$( "#newAccountInfo" ).dialog( "open" );
	});

$( "#newAccountInfo form" ).validate({
	rules: {
	  fname: {
	    minlength: 3,
	    required: true,
      },
      lname: {
          minlength: 3,
          required: true,
      },
      uname: {
          required: true,
      },
      email: {
          required: true,
          email: true,
      },
      password: {
          minlength: 6,
          required: true,
      },
      cpassword: {
          equalTo: "#password"
      }
    },
  success: function(label) {
          label.text('OK!').addClass('valid');
      }
  });	    
	
});


</script>

<table width="100%" style="border: 0em solid black;">
  <tr>
    <td style="border: 0em solid black;">
      <div style="text-align: center;">
        <image src="centred/img/title.jpg" alt="Title" />
      </div>
      <div style="text-align:left;color:rgb(255,255,0);font-size:0.75em;">
        <p>
          Welcome to Captain's Share: The Game! Captain's Share: The Game is a <u>free</u> trading simulation game where you, the player, 
          are the captain of your own merchant space vessel. Ship goods, hire crew, negotiate trade agreements and buy larger vessels. 
          Start today and become the Kufiri Quadrant's most successful clipper captain! 
        </p>
        <p>
          For the latest news on development, please visit our <a href='' target='_new'>Forums</a>. For awnsers to common questions, please
          visit our <a href='page_faq.php'>FAQ</a>.
        </p>
        <p>
          <b>About the Game</b> - Captain's Share: The Game is based on the 'Golden Age of the Solar Clipper' universe created by Nathan 
          Lowell. You can find more information about the Golden Age and Nathan Lowell by visiting <a href='http://solarclipper.com' target='_new'>
          www.SolarClipper.com</a>.
        </p>
        <p>
          <b>Getting Started</b> - Before you can play the game, the first thing you'll need to do is <a href='page_register.php'>create a 
          FREE account</a>. Once you've successfully registered an account you'll have access to the main game screen from where you'll 
          interact with the various game interfaces.
        </p>
        <p>
          <b>Playing the Game</b> - Once you've obtained a username and password you'll be able to login to the game through the login 
          interface to the right. Once logged in, You'll see new links at the top of the screen. These links will let you navigate through 
          the various playng screens, including Ship Status, Manifest, Crew Roster, Dock Yard and Chandlery. Each screen allows you to 
          perform a specific action such as managing your ship and crew, buying and selling cargo and re-supplying your ship's consumables.
        </p>
        <p>
          <b>Goals</b> - Captain's Share: The Game is an open ended game with no set scenario that you have to beat in order to win. You 
          are a captain of a solar clipper, a merchant spaceship that hauls cargo from one star system to another. Like any real life 
          company, your goal is to make money. Lots and lots of money.
        </p>
        <p>
          <b>Help</b> - Many tips and tricks for playing the game can be found on our <a href='page_faq.php'>FAQ</a>. Also, you could 
          check our <a href=''>forums</a> and post a question. If neither of these answers your question, you can always contact the game
          <a href='page_contact.php'>staff</a> directly.
        </p>
      </div>
    </td>
    <td style="width:16%; border:0em solid black; background-color:rgb(32,48,80);">
      <div style="" >
        <div id='HGray' style="text-align:center;">
          <h1>Player Login</h1>
        </div>
        <div id='Login' style="text-align:right;">
          <form action="" method='post'>
            <p>
              Username<br/>
              <input type='text' name='username' />
              <br/>
              Password<br/>
              <input type='password' name='password' />
              <br/><br/>
              Remember Sign In: 
              <input type='checkbox' name='remembersignin' value='1' checked />
              <br/><br/>
              <input type='button' value='login' name='submit' id="submit" />
            </p>
          </form>
          <br/><br/>
          <button id="newAccount" >Create New Account</button>
        </div>
      </td>
    </tr>
  </table> 
</div>
<div id="dialog" title="Verifing Login" >
	<p>
		Verifying Login.
		<br/>
		Please wait...
	</p>
</div>
<div id="newAccountInfo" title="Create new user">
	  <form id="newAccountForm">
	    <div>
		  <label for="fname">First Name</label>
		  <input type="text" name="fname" id="fname" />
		</div>
		<div>
		  <label for="lname">Last Name</label>
	      <input type="text" name="lname" id="lname" />
	    </div>
	    <div>
		  <label for="uname">Username</label>
		  <input type="text" name="uname" id="uname" />
		</div>
		<div>
		  <label for="email">Email</label>
		  <input type="text" name="email" id="email" />
		</div>
		<div>
		  <label for="password">Password</label>
		  <input type="password" name="password" id="password" />
		</div>
		<div>
		  <label for="cpassword">Confirm Password</label>
	  	  <input type="password" name="cpassword" id="cpassword" />
	  	</div>
	    </fieldset>
	  </form>
</div>



<?php 
  // This is what would be loaded if user is logged in.
?>
<!--  This is where the homepage would be located. Once coding is complete it will be added to the main system.  -->