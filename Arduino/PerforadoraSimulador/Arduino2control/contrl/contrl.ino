
#include "DHT.h"
#define triger 12
#define echo 13


DHT dht(2, DHT11);


float temperatura=0;



int tiempo=23;

byte boton1=4;
byte boton2=5;

byte boton3=6;

byte estadoled=0;

byte motor1a=7;
byte motor1b=8;

byte motor2a=9;
byte motor2b=10;

void setup() {
  Serial.begin(9600);
 

  dht.begin();
  pinMode(triger,OUTPUT);
  pinMode(echo,INPUT);

  pinMode(boton1,INPUT_PULLUP);
  pinMode(boton2,INPUT_PULLUP);
  pinMode(boton3,INPUT_PULLUP);
  
  pinMode(motor1a,OUTPUT);
  pinMode(motor1b,OUTPUT);
 
  digitalWrite(motor1a,0);
  digitalWrite(motor1b,0);


  pinMode(motor2a,OUTPUT);
  pinMode(motor2b,OUTPUT);
 
  digitalWrite(motor2a,0);
  digitalWrite(motor2b,0);
  
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Hora,fecha,Distancia,medida,temp");
  


}
////////////como contar sin interrupmir

  

void loop() {


   
  int estboton1=digitalRead(boton1);
  int estboton2=digitalRead(boton2);
  int estboton3=digitalRead(boton3);
  if(estboton1==0){
      digitalWrite(motor2a,0);
      digitalWrite(motor2b,0);
      delay(500);
      digitalWrite(motor1a,1);
      digitalWrite(motor1b,1);
   
    }
  if(estboton2==0){
      digitalWrite(motor1a,0);
      digitalWrite(motor1b,0);
      delay(500);
      digitalWrite(motor2a,1);
      digitalWrite(motor2b,1);
      }

  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Falla al leer el sensor DHT11!");
    return;
  }
  
   digitalWrite(triger,0);
   delayMicroseconds(2);
   digitalWrite(triger,1);
   delayMicroseconds(10);
   digitalWrite(triger,0);

   
  float duracion;
  float distancia;
   duracion=pulseIn(echo,1);


   
   distancia=duracion/2/29.1;
   Serial.print("DATA,TIME,DATE,");
   Serial.print(distancia);
   Serial.print(" , ");
   Serial.print(" cm ");
   Serial.print(" , ");
   Serial.print(t);
   Serial.print(" , ");
   Serial.println("C");

   delay(250);

   


   
 
 
}
