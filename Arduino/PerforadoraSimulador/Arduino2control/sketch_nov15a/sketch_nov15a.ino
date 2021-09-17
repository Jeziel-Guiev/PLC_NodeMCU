
byte encender=8;
byte parada=9;
byte contador=10;
byte contar=0;

char c;



byte cinta=A0;
byte empaquetar=A1;
byte compuerta=A2;




void setup() {
 Serial.begin(9600);
 pinMode(encender,INPUT);
 pinMode(parada,INPUT);
 pinMode(contador,INPUT);

 pinMode(cinta,OUTPUT);
 pinMode(empaquetar,OUTPUT);
 pinMode(compuerta,OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    c=Serial.read();
    }
 
 byte boton1=digitalRead(encender);
 byte boton2=digitalRead(parada);
 byte boton3=digitalRead(contador);
 if(boton2==1){
   if(boton1==0){
       digitalWrite(cinta,1);
    }else{digitalWrite(cinta,0);}

  if(boton3==0){
    contar++;

    if(contar==5){
      
    digitalWrite(cinta,0);
    digitalWrite(empaquetar,1);
    delay(10000);
    digitalWrite(empaquetar,0);
    digitalWrite(compuerta,1);
    delay(2000);
    digitalWrite(compuerta,0);
    contar=0;
    }
    }


    

  }else{
    
   Serial.println("maquina detenida");
   digitalWrite(cinta,0);
   digitalWrite(empaquetar,0);
   digitalWrite(compuerta,0);
  }









  
}
