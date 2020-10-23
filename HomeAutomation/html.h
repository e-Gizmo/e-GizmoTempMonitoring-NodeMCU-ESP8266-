#ifndef HTML_H
#define HTML_H

const char HTML_HOME[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
	<head>
  		<title>ESP WEB</title>
		<meta charset="utf-8">
  		<meta name="viewport" content="width=device-width, initial-scale=1">
		<style>
			.onS1 {
			  	background-color: #4CAF50;
			  	border: none;
			  	color: white;
			  	padding: 15px 32px;
			  	text-align: center;
			  	text-decoration: none;
			  	display: inline-block;
			  	font-size: 16px;
			  	margin: 4px 2px;
			  	cursor: pointer;
				width:200px;
			}

			.offS1 {
			  	background-color: #FF0000;
			  	border: none;
			  	color: white;
			  	padding: 15px 32px;
			  	text-align: center;
			  	text-decoration: none;
			  	display: inline-block;
			  	font-size: 16px;
			  	margin: 4px 2px;
			  	cursor: pointer;
				width:200px;
			}
			.onS2 {
			  	background-color: #4CAF50;
			  	border: none;
			  	color: white;
			  	padding: 15px 32px;
			  	text-align: center;
			  	text-decoration: none;
			  	display: inline-block;
			  	font-size: 16px;
			  	margin: 4px 2px;
			  	cursor: pointer;
				width:200px;
			}

			.offS2 {
			  	background-color: #FF0000;
			  	border: none;
			  	color: white;
			  	padding: 15px 32px;
			  	text-align: center;
			  	text-decoration: none;
			  	display: inline-block;
			  	font-size: 16px;
			  	margin: 4px 2px;
			  	cursor: pointer;
				width:200px;
			}
			.onS3 {
			  	background-color: #4CAF50;
			  	border: none;
			  	color: white;
			  	padding: 15px 32px;
			  	text-align: center;
			  	text-decoration: none;
			  	display: inline-block;
			  	font-size: 16px;
			  	margin: 4px 2px;
			  	cursor: pointer;
				width:200px;
			}

			.offS3 {
			  	background-color: #FF0000;
			  	border: none;
			  	color: white;
			  	padding: 15px 32px;
			  	text-align: center;
			  	text-decoration: none;
			  	display: inline-block;
			  	font-size: 16px;
			  	margin: 4px 2px;
			  	cursor: pointer;
				width:200px;
			}
			.onF1 {
			  	background-color: #4CAF50;
			  	border: none;
			  	color: white;
			  	padding: 15px 32px;
			  	text-align: center;
			  	text-decoration: none;
			  	display: inline-block;
			  	font-size: 16px;
			  	margin: 4px 2px;
			  	cursor: pointer;
				width:200px;
			}

			.offF1 {
			  	background-color: #FF0000;
			  	border: none;
			  	color: white;
			  	padding: 15px 32px;
			  	text-align: center;
			  	text-decoration: none;
			  	display: inline-block;
			  	font-size: 16px;
			  	margin: 4px 2px;
			  	cursor: pointer;
				width:200px;
			}

		</style>
	</head>
	<body>
		<center>
			<h2>
				HOME AUTOMATION SYSTEM
			</h2>

			<input type="button" class="onS1" value="LIGHT 1 ON" id="on1" onclick="onLED1">
			<br/>
			<input type="button" class="offS1" value="LIGHT 1 OFF" id="off1" onclick="offLED1">
			<br/>
			<input type="button" class="onS2" value="LIGHT 2 ON " id="on2" onclick="onLED2">
			<br/>
			<input type="button" class="offS2" value="LIGHT 2 OFF" id="off2" onclick="offLED2">
			<br/>
			<input type="button" class="onS3" value="LIGHT 3 ON" id="on3" onclick="onLED3">
			<br/>
			<input type="button" class="offS3" value="LIGHT 3 OFF" id="off3" onclick="offLED3">
			<br/>
			<input type="button" class="onF1" value="FAN ON" id="onFan" onclick="onFan1">
			<br/>
			<input type="button" class="offF1" value="FAN OFF" id="offFan" onclick="offFan1">

			<script>
				function onLED1()
				{
					var xhttp = new XMLHttpRequest();	
				  	xhttp.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
			  												
						}
				 	};
		
				 	xhttp.open("GET", "/on1", true);
				  	xhttp.send();
				}

				function offLED1()
				{
					var xhttp1 = new XMLHttpRequest();	
				  	xhttp1.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
			  												
						}
				 	};

		
				 	xhttp1.open("GET", "/off1", true);
				  	xhttp1.send();
				}
				function onLED2()
				{
					var xhttp = new XMLHttpRequest();	
				  	xhttp.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
			  												
						}
				 	};
		
				 	xhttp.open("GET", "/on2", true);
				  	xhttp.send();
				}

				function offLED2()
				{
					var xhttp1 = new XMLHttpRequest();	
				  	xhttp1.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
			  												
						}
				 	};
				 	
		
				 	xhttp1.open("GET", "/off2", true);
				  	xhttp1.send();
				}
				function onLED3()
				{
					var xhttp = new XMLHttpRequest();	
				  	xhttp.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
			  												
						}
				 	};
		
				 	xhttp.open("GET", "/on3", true);
				  	xhttp.send();
				}

				function offLED3()
				{
					var xhttp1 = new XMLHttpRequest();	
				  	xhttp1.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
			  												
						}
				 	};
				 	
		
				 	xhttp1.open("GET", "/off3", true);
				  	xhttp1.send();
				}
				function onFan1()
				{
					var xhttp = new XMLHttpRequest();	
				  	xhttp.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
			  												
						}
				 	};
		
				 	xhttp.open("GET", "/onFan", true);
				  	xhttp.send();
				}

				function offFan1()
				{
					var xhttp1 = new XMLHttpRequest();	
				  	xhttp1.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
			  												
						}
				 	};
				 	
		
				 	xhttp1.open("GET", "/offFan", true);
				  	xhttp1.send();
				}
			</script>
		</center>
	</body>
</html>

)=====";

#endif
