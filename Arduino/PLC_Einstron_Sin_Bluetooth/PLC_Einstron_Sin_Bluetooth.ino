/*
 * TimeRTC.pde
 * example code illustrating Time library with Real Time Clock.
 * 
 */

#include <TimeLib.h>
#include <TimeAlarms.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

byte estado8=0;
byte estado9=0;
byte estado10=0;
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
  while (!Serial) ; // wait until Arduino Serial Monitor opens
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");  
       
}

void loop()
{
  
    digitalClockDisplay();
   Alarm.delay(500);
   estado8=digitalRead(8);
   estado9=digitalRead(9);
   estado10=digitalRead(10);

     if( estado8==0){
      digitalWrite(A2,1);
      }else{digitalWrite(A2,0);}
     if( estado9==0){
      digitalWrite(A1,1);
      }else{digitalWrite(A1,0);}
     if( estado10==0){
      digitalWrite(A0,1);
      }else{digitalWrite(A0,0);}
      
     
   
}

void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  //  if(second()==23){
     //  digitalWrite(8,1);
    //  }
    //   if(second()==30){
    //  digitalWrite(8,0);
    //  }

    
   
    if(hour()==19&&minute()==1&&second()==0){
      digitalWrite(A2,1);
      delay(2000);
      digitalWrite(A1,1);
      delay(2000);
      digitalWrite(A0,1);
      delay(2000);
      digitalWrite(A2,0);
      
      digitalWrite(A1,0);
      
      digitalWrite(A0,0);
      
      }
   
  


      
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

