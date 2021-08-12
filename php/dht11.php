<?php
class dht11{
 public $link='';
 function __construct($temperature, $humidity,$deviceId){
  $this->connect();
  $this->storeInDB($temperature, $humidity,$deviceId);
 }
 
 function connect(){
  $this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the DB');
  mysqli_select_db($this->link,'dht11') or die('Cannot select the DB');
 }
 
 
 function storeInDB($temperature, $humidity,$deviceId){
  $query = "insert into dht11table set humidity='".$humidity."', temperature='".$temperature."', deviceId='".$deviceId."'";
  $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
 }

//  function storeInDBDeviceOnline($deviceId){
//     $query = "insert into devicesonline set isOnline='".$deviceId."', deviceId='".$deviceId."'";
//     $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
//    }
 
}

if($_GET['temperature'] != '' and  $_GET['humidity'] != '' and $_GET['deviceId']!='' ){
 $dht11=new dht11($_GET['temperature'],$_GET['humidity'],$_GET['deviceId']);
}
?>


<!-- http://192.168.2.13/testcode/dht11.php?temperature=10&humidity=9 -->

<!-- http://192.168.2.13/testcode/dht11.php?temperature=10&humidity=9&deviceId=dasd -->
<!-- http://192.168.2.13/testcode/dht11.php?isOnline=10&deviceId=dasd -->