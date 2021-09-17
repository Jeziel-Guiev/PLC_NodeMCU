
#include <String.h>

#include <Arduino.h>

String voice;

int posA=0;
int posZ=0;


void setup() {
Serial.begin(9600);
}

void loop() {
   while (Serial.available()>0)
   {            
    delay(10);                        
    char c = Serial.read();               
    voice += c;                       
   }
   char cad[]=voice.toCharArray();
 
}
