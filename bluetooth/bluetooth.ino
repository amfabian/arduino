/*
#------------------------#
| Bluetoth APP |

#------------------------#
*/
 
#include <SoftwareSerial.h>
 
//Parâmetros de Configuração----------------------
#define Command_1 "12345" //Comando Esperado
#define Command_Size 5 //Tamanho do Comando
 
SoftwareSerial bluetooth(12, 10); // RX, TX
 
void setup()
{
//Define o pino do LED interno como saída
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);
 
//Inicializa a comunicação com o módulo HC-05
bluetooth.begin(9600);
 
//Inicializa a comunicação serial padrão
Serial.begin(9600);
Serial.println("inicio");
Serial.println(Command_1);
String teste = "12345";
Serial.println(teste.length());
}
 
void loop()
{
static bool state = false;
static String command = "";

if(bluetooth.available()> 0) //Módulo recebeu dados
{ 
Serial.println("bt disponivel");
  
command += char(bluetooth.read());
delay(50);
 Serial.println("recebeu dados");

}
//Serial.println(command.length());
//if(command.length() == Command_Size)
//{

 
if(command == Command_1) //Comando recebido é igual ao comando esperado
{
  Serial.println(command);
state = !state;
digitalWrite(LED_BUILTIN, state); //Muda o estado do LED interno
}
 
command = "";
 
//}
}
