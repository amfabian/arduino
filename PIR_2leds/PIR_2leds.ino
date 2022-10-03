// C++ code
//

int ledRed = 12;
int ledBlue = 13;
int pirStat = 0;    
int sensorPIR = 7;

void setup()
{
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(sensorPIR, INPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}

void loop()
{

 delay(1000);
 Serial.println("GoT!!!");
  int tempo = 400;
  tone(10,440,tempo); //LA
  delay(tempo);
  tone(10,294,tempo); //RE
  delay(tempo);
  tone(10,349,tempo/2); //FA - O tempo/2 faz com que demore metade do valor estipulado anteriormente, pois essa parte é mais rápida
  delay(tempo/2);
  tone(10,392,tempo/2); //SOL
  delay(tempo/2);
  tone(10,440,tempo); //LA
  delay(tempo);
  tone(10,294,tempo); //RE
  delay(tempo);
  tone(10,349,tempo/2); //FA
  delay(tempo/2);
  tone(10,392,tempo/2); //SOL
  delay(tempo/2);
  tone(10,330,tempo); //MI
  delay(tempo);

  

/*  
if (digitalRead(sensorPIR) == HIGH) {            // if motion detected
   digitalWrite(ledRed, HIGH);  // turn LED ON
   Serial.println("Hey I got you!!!");
     Serial.println(digitalRead(sensorPIR));
 } 
 else {
   digitalWrite(ledRed, LOW ); // turn LED OFF if we have no motion
    Serial.println("ELSEEEEEEE!!!");
 }
    
  digitalWrite(ledBlue, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(ledBlue, LOW);
  delay(2000); // Wait for 2000 millisecond(s)
//  digitalWrite(ledRed, HIGH);

  */
}
