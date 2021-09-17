
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x20  // Direccion I2C para PCF8574A que es el que lleva nuestra placa diseñada por MJKDZ
//definimos las constantes para esta placa

#define  LED_OFF  0
#define  LED_ON  1

LiquidCrystal_I2C lcd(I2C_ADDR, 4, 5, 6, 0, 1, 2, 3, 7, NEGATIVE);


byte estado8=0;
byte estado9=0;
byte estado10=0;
String voice;
void setup()  {
  Serial.begin(9600);
  pinMode(A2,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A0,OUTPUT);
    pinMode(8,INPUT);
    pinMode(9,INPUT);
    pinMode(10,INPUT);
  
  digitalWrite(A2,0);
  digitalWrite(A1,0);
  digitalWrite(A0,0);
   

       lcd.begin (16,2);  // inicializar lcd 
       // Activamos la retroiluminacion
       lcd.setBacklight(LED_ON);
}

void loop()
{
   estado8=digitalRead(8);
   estado9=digitalRead(9);
   estado10=digitalRead(10);
 
    lcd.clear();
    lcd.setBacklight(LED_OFF);//Backlight OFF 
    delay(100); 
    lcd.backlight(); //Backlight ON 
    lcd.setCursor(0,0);
    lcd.print("Hola dfgfgdgd"); 
    lcd.setCursor(0,1);
    lcd.print("LCD por I2C"); 
    delay(500); 
      
      while (Serial.available()>0) {            //while Serial data is available over bluetooth
       delay(10);                        //delay added to make things stable
       char c = Serial.read();               //conduct a Serial reading of the Bluetooth data
       voice += c;                       //build the strings
      }

        if(estado8==0){
        digitalWrite(A0,1);
        }
        if(estado8==1){
        digitalWrite(A0,0);
        }
        if(estado9==0){
        digitalWrite(A1,1);
        }
         if(estado9==1){
        digitalWrite(A1,0);
        }
         if(voice.indexOf("encender") > -1){
        digitalWrite(A2,1);
        }
         if(voice.indexOf("Apagar") > -1){
        digitalWrite(A2,0);
        }
        
    
   
   
   
   
}

     







      
 



