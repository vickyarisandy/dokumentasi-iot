const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <title>GConnect :)</title>
        <script>
        var State1;
        var State2;
        var State3;
        var State4;
        var State5;
        var State6;
        var State7;
        var State8;
        var State9;
        var State10;
      function DisplayCurrentTime() {
          var dt = new Date();
  var weekday = new Array(7);
  weekday[0] = "Minngu";
  weekday[1] = "Senin";
  weekday[2] = "Selasa";
  weekday[3] = "Rabu";
  weekday[4] = "Kamis";
  weekday[5] = "Jum'at";
  weekday[6] = "Sabtu";
  var dow = weekday[dt.getDay()];
document.getElementById("datetime").innerHTML = (dow) +" "+ (dt.toLocaleString());
        setTimeout('DisplayCurrentTime()', 1000);
      };
        function GetState()
        {
          var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
                            State1 = this.responseXML.getElementsByTagName("analog")[0].childNodes[0].nodeValue;
                            State2 = this.responseXML.getElementsByTagName("analog")[1].childNodes[0].nodeValue;
                            State3 = this.responseXML.getElementsByTagName("analog")[2].childNodes[0].nodeValue;
                            State4 = this.responseXML.getElementsByTagName("analog")[3].childNodes[0].nodeValue;
                            State5 = this.responseXML.getElementsByTagName("analog")[4].childNodes[0].nodeValue;
                            State6 = this.responseXML.getElementsByTagName("analog")[5].childNodes[0].nodeValue;
                            State7 = this.responseXML.getElementsByTagName("analog")[6].childNodes[0].nodeValue;
                            State8 = this.responseXML.getElementsByTagName("analog")[7].childNodes[0].nodeValue;
                            State9 = this.responseXML.getElementsByTagName("analog")[8].childNodes[0].nodeValue;
                            State10 = this.responseXML.getElementsByTagName("analog")[9].childNodes[0].nodeValue;
                            State11 = this.responseXML.getElementsByTagName("analog")[10].childNodes[0].nodeValue;
                            State12 = this.responseXML.getElementsByTagName("analog")[11].childNodes[0].nodeValue;
                            State13 = this.responseXML.getElementsByTagName("analog")[12].childNodes[0].nodeValue;
                            State14 = this.responseXML.getElementsByTagName("analog")[13].childNodes[0].nodeValue;
                            State15 = this.responseXML.getElementsByTagName("analog")[14].childNodes[0].nodeValue;
                            State16 = this.responseXML.getElementsByTagName("analog")[15].childNodes[0].nodeValue;
    }
    if (State1 == 0) {
    document.getElementById("statled1").innerHTML = "ON";
    var elem = document.getElementById("statled1");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled1").innerHTML = "OFF";
    var elem = document.getElementById("statled1");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }
    if (State2 == 0) {
    document.getElementById("statled2").innerHTML = "ON";
    var elem = document.getElementById("statled2");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled2").innerHTML = "OFF";
    var elem = document.getElementById("statled2");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }
    if (State3 == 0) {
    document.getElementById("statled3").innerHTML = "ON";
    var elem = document.getElementById("statled3");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled3").innerHTML = "OFF";
    var elem = document.getElementById("statled3");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }
    if (State4 == 0) {
    document.getElementById("statled4").innerHTML = "ON";
    var elem = document.getElementById("statled4");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled4").innerHTML = "OFF";
    var elem = document.getElementById("statled4");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }
    if (State5 == 0) {
    document.getElementById("statled5").innerHTML = "ON";
    var elem = document.getElementById("statled5");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled5").innerHTML = "OFF";
    var elem = document.getElementById("statled5");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }
    if (State6 == 0) {
    document.getElementById("statled6").innerHTML = "ON";
    var elem = document.getElementById("statled6");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled6").innerHTML = "OFF";
    var elem = document.getElementById("statled6");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }
    if (State7 == 0) {
    document.getElementById("statled7").innerHTML = "ON";
    var elem = document.getElementById("statled7");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled7").innerHTML = "OFF";
    var elem = document.getElementById("statled7");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }
    if (State8 == 0) {
    document.getElementById("statled8").innerHTML = "ON";
    var elem = document.getElementById("statled8");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled8").innerHTML = "OFF";
    var elem = document.getElementById("statled8");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }

if (State9 == 0) {
    document.getElementById("statled9").innerHTML = "ON";
    var elem = document.getElementById("statled9");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled9").innerHTML = "OFF";
    var elem = document.getElementById("statled9");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }

  if (State10 == 0) {
    document.getElementById("statled10").innerHTML = "ON";
    var elem = document.getElementById("statled10");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled10").innerHTML = "OFF";
    var elem = document.getElementById("statled10");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }

    if (State11 == 0) {
    document.getElementById("statled11").innerHTML = "ON";
    var elem = document.getElementById("statled11");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled11").innerHTML = "OFF";
    var elem = document.getElementById("statled11");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }

   if (State12 == 0) {
    document.getElementById("statled12").innerHTML = "ON";
    var elem = document.getElementById("statled12");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled12").innerHTML = "OFF";
    var elem = document.getElementById("statled12");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }

   if (State13 == 0) {
    document.getElementById("statled13").innerHTML = "ON";
    var elem = document.getElementById("statled13");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled13").innerHTML = "OFF";
    var elem = document.getElementById("statled13");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }

   if (State14 == 0) {
    document.getElementById("statled14").innerHTML = "ON";
    var elem = document.getElementById("statled14");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled14").innerHTML = "OFF";
    var elem = document.getElementById("statled14");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }

   if (State15 == 0) {
    document.getElementById("statled15").innerHTML = "ON";
    var elem = document.getElementById("statled15");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled15").innerHTML = "OFF";
    var elem = document.getElementById("statled15");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }

   if (State16 == 0) {
    document.getElementById("statled16").innerHTML = "ON";
    var elem = document.getElementById("statled16");
    elem.style.color = "green";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  } else {
    document.getElementById("statled16").innerHTML = "OFF";
    var elem = document.getElementById("statled16");
    elem.style.color = "red";
    elem.style.background = "white";
    elem.style.fontSize = "32px";
    elem.style.fontWeight = "bold";
  }
  //batas
  
  }
  xhttp.open("GET", "redstate", true);
  xhttp.send();
            setTimeout('GetState()', 4000);
            
        };
      document.addEventListener('DOMContentLoaded', function() {
        DisplayCurrentTime(),GetState();
      }, false);
    </script>
      <style>

  body {
  text-align: center;
  background-color: #005555;
  }
  table {
  text-align: center;
  border: 2px solid #808080;
  background-color: #a0a0a0;
  width:100%;
  color: #0000ff;
  -moz-border-radius: 7px;
  -webkit-border-radius: 7px;
  }
  td {
  border: 2px solid #ff0000;
  background-color: #ffff00;
  padding: 16px;
  -moz-border-radius: 7px;
  -webkit-border-radius: 7px;
  }
  .button-led {
  padding: 5px 5px 5px 5px;
  width: 100%;
  border: #fbfb00 solid 3px;
  background-color: #2b2b2b;
  color:white;
  font-size:33px;
  padding-bottom:5px;
  font-weight:700;
  -moz-border-radius: 7px;
  -webkit-border-radius: 7px;
  }
  .button-led:hover {
  background-color: #0000ff;
  color: #ff93bd;
  }
  .dtime {
  padding: 5px 5px 5px 5px;
  width: 100%;
  border: #fbfb00 solid 3px;
  background-color: #ffffff;
  color:red;
  font-size:30px;
  padding-bottom:5px;
  font-weight:700;
  -moz-border-radius: 7px;
  -webkit-border-radius: 7px;
  }
  </style>
    </head>
    <body>
   <td>
   
   <b class="dtime"> log Sistem: <span id="datetime"></span></b>
   <br/>
   <b class="dtime"> info : satu ruangan  220v 10a / 2200W Tegangan AC </b>
   </td>
    <table>
   <tr>
        <td>
  <form action="/LED1" method="POST">
      <button type="submit" class="button-led">ruangan 1 <span id="statled1"></span></button>
  </form></td>
        <td style='width:40%'>
  <form action="/LED2" method="POST">
      <button type="submit" class="button-led">ruangan 2 <span id="statled2"></span></button>
  </form></td>
  </tr>
   <tr>
        <td style='width:40%'>
  <form action="/LED3" method="POST">
      <button type="submit" class="button-led">ruangan 3 <span id="statled3"></span></button>
  </form></td>
        <td style='width:40%'>
  <form action="/LED4" method="POST">
      <button type="submit" class="button-led">ruangan 4 <span id="statled4"></span></button>
  </form></td>
  </tr>
   <tr>
        <td>
  <form action="/LED5" method="POST">
      <button type="submit" class="button-led">ruangan 5 <span id="statled5"></span></button>
  </form></td>
        <td style='width:40%'>
  <form action="/LED6" method="POST">
      <button type="submit" class="button-led">ruangan 6 <span id="statled6"></span></button>
  </form></td>
  </tr>
   <tr>
        <td style='width:40%'>
  <form action="/LED7" method="POST">
      <button type="submit" class="button-led">ruangan 7 <span id="statled7"></span></button>
  </form></td>
        <td style='width:40%'>
  <form action="/LED8" method="POST">
      <button type="submit" class="button-led">ruangan 8 <span id="statled8"></span></button>
  </form></td>
  </tr>

 <tr>
        <td style='width:40%'>
  <form action="/LED9" method="POST">
      <button type="submit" class="button-led">ruangan 9 <span id="statled9"></span></button>
  </form></td>
        <td style='width:40%'>
  <form action="/LED10" method="POST">
      <button type="submit" class="button-led">ruangan 10 <span id="statled10"></span></button>
  </form></td>
  </tr>

  <tr>
        <td style='width:40%'>
  <form action="/LED11" method="POST">
      <button type="submit" class="button-led">ruangan 11 <span id="statled11"></span></button>
  </form></td>
        <td style='width:40%'>
  <form action="/LED12" method="POST">
      <button type="submit" class="button-led">ruangan 12 <span id="statled12"></span></button>
  </form></td>
  </tr>
  <tr>
        <td style='width:40%'>
  <form action="/LED13" method="POST">
      <button type="submit" class="button-led">ruangan 13 <span id="statled13"></span></button>
  </form></td>
        <td style='width:40%'>
  <form action="/LED14" method="POST">
      <button type="submit" class="button-led">ruangan 14 <span id="statled14"></span></button>
  </form></td>
  </tr>

  <tr>
        <td style='width:40%'>
  <form action="/LED15" method="POST">
      <button type="submit" class="button-led">ruangan 15 <span id="statled15"></span></button>
  </form></td>
        <td style='width:40%'>
  <form action="/LED16" method="POST">
      <button type="submit" class="button-led">ruangan 16 <span id="statled16"></span></button>
  </form></td>
  </tr>
  
  
   <tr>
        <td style='width:40%'>
  <form action="/allon" method="POST">
      <button type="submit" class="button-led">Semua ruangan ON</button>
  </form></td>
        <td style='width:40%'>
  <form action="/alloff" method="POST">
      <button type="submit" class="button-led">Semua ruangan OFF</button>
  </form></td>
  </tr>
    </table>
    </body>
</html>
)=====";