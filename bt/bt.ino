#include <SoftwareSerial.h>

SoftwareSerial hc06(3, 2);
String command = "";
char b1;

void setup() {
  //Initialize Serial Monitor
  Serial.begin(38400);
  Serial.println("Digite o Commando:");
  //Initialize Bluetooth Serial Port
  hc06.begin(38400);
}

void loop() {

//Write from Serial Monitor to HC06
  if (Serial.available()>0) {
   delay(10);
   hc06.write(Serial.read());
 }
  
 //Write data from HC06 to Serial Monitor
  if (hc06.available()>0) {

    b1 = hc06.read();
    command += b1;

    if(b1 == '\n'){
      
    Serial.print(command);
    command = "";
    
    }
 }
  
  
}
