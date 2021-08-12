<?php
class deviceConnection{
 public $link='';
 function __construct($isOnline,$deviceId){
  $this->connect();
  $this->storeInDB($isOnline,$deviceId);
 }
 
 function connect(){
  $this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the DB');
  mysqli_select_db($this->link,'dht11') or die('Cannot select the DB');
 }
 
 function storeInDB($isOnline,$deviceId){
  $query = "update devicesonline set isOnline='".$isOnline."' where deviceId='".$deviceId."'";
  $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
 }

//  function storeInDB($isOnline,$deviceId){
//    $query = "insert into devicesonline set isOnline='".$isOnline."' , deviceId='".$deviceId."'";
//    $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
//   }
  
 
}

if($_GET['isOnline'] != '' and  $_GET['deviceId']!='' ){
 $deviceConnection=new deviceConnection($_GET['isOnline'],$_GET['deviceId']);
}
?>


<!-- http://192.168.2.13/testcode/deviceConnection.php?isOnline=10&deviceId=dasd -->