/* This arduino code is sending data to mysql server every 30 seconds.
Created By Embedotronics Technologies*/

#include "DHT.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
//#include <MFRC522.h>

#define DHTPIN D2

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);


float humidityData;
float temperatureData;


const char* ssid = "Loading......";// 
const char* password = "satyam@007";
//WiFiClient client;
char server[] = "192.168.2.11";   //eg: 192.168.0.222
//const char* deviceId = "d038527-INCORRECT";
const char* deviceId = "d038527a794dc208b8805e708517041c";

WiFiClient client;    


void setup()
{
 Serial.begin(115200);
  delay(10);
  dht.begin();
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
//  server.begin();
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
  Serial.println("Connected to Network Succesfully");

//Getting Device Online
if (client.connect(server, 80)) {
  

    client.print("GET /testcode/deviceConnection.php?isOnline="); 
    client.print("true");
    client.print("&deviceId=");         //concat device variable
    client.print(deviceId);
    
    Serial.print("GET /testcode/deviceConnection.php?isOnline="); 
    Serial.print("true");
    Serial.print("&deviceId=");         //concat device variable
    Serial.print(deviceId);
    
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host:192.168.2.20");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }

  

void loop()
{ 
  humidityData = dht.readHumidity();
  temperatureData = dht.readTemperature(); 
  Sending_To_phpmyadmindatabase(); 
  delay(30000); // interval
 }

 void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server, 80)) {
    Serial.println("****************************************");
    
    // Make a HTTP request:
    Serial.print("Device ID :");
    Serial.print(deviceId);
    Serial.print(" << ");
    Serial.println(" "); 
    Serial.print("Temprature => ");
    Serial.println(temperatureData);
    Serial.print("Humidity => ");
    Serial.println(humidityData);
    Serial.println("****************************************");
    client.print("GET /testcode/dht11.php?humidity="); 
    client.print(humidityData);
    client.print("&temperature=");
    client.print(temperatureData);
    client.print("&deviceId=");         //concat device variable
    client.print(deviceId);

    Serial.println("*******************************What is sent to server");
    Serial.print("GET /testcode/dht11.php?humidity="); 
    Serial.print(humidityData);
    Serial.print("&temperature=");
    Serial.print(temperatureData);
    Serial.print("&deviceId=");         
    Serial.print(deviceId);

    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host:192.168.2.13");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
