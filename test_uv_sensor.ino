void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue;

sensorValue=analogRead(A0);
Serial.print("The voltage value:");
Serial.print(sensorValue*5000/1023.0);
Serial.println("mV");
delay(1000);
Serial.print("\n");
}
