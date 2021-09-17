
byte encender=8;
byte parada=9;
byte contador=10;
byte contar=0;

char c;



byte cinta=A2;
byte empaquetar=A1;
byte compuerta=A0;




void setup() {
 Serial.begin(9600);
 pinMode(encender,INPUT);
 pinMode(parada,INPUT);
 pinMode(contador,INPUT);

 pinMode(cinta,OUTPUT);
 pinMode(empaquetar,OUTPUT);
 pinMode(compuerta,OUTPUT);
}
void terminar(byte boton2){
  
   do{
   boton2=digitalRead(parada);
   digitalWrite(cinta,0);
   digitalWrite(empaquetar,0);
   digitalWrite(compuerta,0);
  }while(boton2==0);
 }
void loop() {
 
 
 byte boton1=digitalRead(encender);
 byte boton2=digitalRead(parada);
 byte boton3=digitalRead(contador);
 terminar(boton2);
   if(boton1==0){
       digitalWrite(cinta,1);
       
    

  if(boton3==0){
    delay(100);
    contar++;
  terminar(boton2);
    if(contar==5){
    terminar(boton2); 
    digitalWrite(cinta,0);
    delay(100);
    digitalWrite(empaquetar,1);
    delay(10000);
    digitalWrite(empaquetar,0);
    digitalWrite(compuerta,1);
    delay(2000);
    digitalWrite(compuerta,0);
    contar=0;
    }
    }

   }else{digitalWrite(cinta,0);}
    

  
}

