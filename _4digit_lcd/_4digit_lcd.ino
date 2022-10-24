
#include <TM1637.h>
int pushbutton = 12;
int CLK = 4;
int DIO = 3;
int NUMBER = 0;
int button2 = 2;

TM1637 tm(CLK,DIO);

void setup() {
  // put your setup code here, to run once:
   pinMode(pushbutton, INPUT_PULLUP);
   pinMode(button2, INPUT_PULLUP);
 tm.init();
 tm.set(2);
 Serial.begin(9600);
 tm.display(0,0);
 tm.display(1,0);
 tm.display(2,0);
 tm.display(3,0);
 pinMode(8,OUTPUT);
}
void displayNumber(int num){ 
   tm.point(0);  
    tm.display(3, num % 10);   
    tm.display(2, num / 10 % 10);   
    tm.display(1, num / 100 % 10);   
    tm.display(0, num / 1000 % 10);
}
void displayTime(int seconds){
    int minutes = seconds / 60;
    seconds = seconds % 60;

    tm.point(1);
    tm.display(3, seconds % 10);
    tm.display(2, seconds / 10 % 10);
    tm.display(1, minutes % 10);
    tm.display(0, minutes / 10 % 10);
}

void iniciaTimer(){
  while (NUMBER>0){
  NUMBER--;
  displayTime(NUMBER);
  delay(1000); 
  
  }
}

void iniciaMusica(){
  Serial.println("GoT!!!");
  int tempo = 400;
  tone(8,440,tempo); //LA
  delay(tempo);
  tone(8,294,tempo); //RE
  delay(tempo);
  tone(8,349,tempo/2); //FA - O tempo/2 faz com que demore metade do valor estipulado anteriormente, pois essa parte é mais rápida
  delay(tempo/2);
  tone(8,392,tempo/2); //SOL
  delay(tempo/2);
  tone(8,440,tempo); //LA
  delay(tempo);
  tone(8,294,tempo); //RE
  delay(tempo);
  tone(8,349,tempo/2); //FA
  delay(tempo/2);
  tone(8,392,tempo/2); //SOL
  delay(tempo/2);
  tone(8,330,tempo); //MI
  delay(tempo);
  }

void loop() {

if (digitalRead(button2) == LOW) {
  Serial.println("botao pressionado");
  delay(1000);
  iniciaTimer();
  
  while(digitalRead(pushbutton) != LOW){
    iniciaMusica();
  }
   
}

  
 if (digitalRead(pushbutton) == LOW) {
   NUMBER++;
   Serial.println(NUMBER);
   displayTime(NUMBER);
   delay(500);
 }
 
  
 
}
