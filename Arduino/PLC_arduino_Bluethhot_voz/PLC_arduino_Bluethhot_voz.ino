#include <blinked.h>

#include <TimeLib.h>
#include <TimeAlarms.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

byte estado8=0;
byte estado9=0;
byte estado10=0;
char dato;
void setup()  {
  Serial.begin(9600);
  pinMode(A2,1);
  pinMode(A1,1);
  pinMode(A0,1);
    pinMode(8,0);
    pinMode(9,0);
    pinMode(10,0);
  
  digitalWrite(A2,0);
  digitalWrite(A1,0);
  digitalWrite(A0,0);
    setSyncProvider(RTC.get);   // the
}

void loop()
{
   estado8=digitalRead(8);
   estado9=digitalRead(9);
   estado10=digitalRead(10);
 

      
     if(Serial.available()>0){
      
      dato=Serial.read();
      
      }

        if(dato=='a'){
        digitalWrite(A0,1);
        }
        if(dato=='b'){
        digitalWrite(A0,0);
        }
        if(dato=='c'){
        digitalWrite(A1,1);
        }
         if(dato=='d'){
        digitalWrite(A1,0);
        }
         if(dato=='e'){
        digitalWrite(A2,1);
        }
         if(dato=='f'){
        digitalWrite(A2,0);
        }
        
      
        digitalClockDisplay();
   Alarm.delay(100);
    
   
   
   
   
}
void digitalClockDisplay(){

   
    if(hour()==6&&minute()==40&&second()==0){
      digitalWrite(A2,1);
      
     
      
      
      }
    if(hour()==6&&minute()==55&&second()==0){
      digitalWrite(A2,0);
      
     
      
      
      }
     

}





      
 



