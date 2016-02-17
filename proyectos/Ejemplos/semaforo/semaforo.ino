
int pinVerde=7,pinRojo=8,pinAmbar=9;
int pinMicro=A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinVerde,OUTPUT);
  pinMode(pinAmbar,OUTPUT);
  pinMode(pinRojo,OUTPUT);

  Serial.begin(9600);
}

int SonidoBajo=100;
int SonidoMedio=500;
int SonidoAlto=900;

void loop() {

  int nivelSonido=analogRead(pinMicro); 
  Serial.println(nivelSonido);
  if(nivelSonido<SonidoMedio)
  {
     digitalWrite(pinVerde,HIGH);
     digitalWrite(pinRojo,LOW);
     digitalWrite(pinAmbar,LOW);
     Serial.println("VERDE");
  }
  else if(nivelSonido>SonidoMedio)
  {
     digitalWrite(pinVerde,LOW);
     digitalWrite(pinRojo,LOW);
     digitalWrite(pinAmbar,HIGH);
     Serial.println("AMBAR");
  }
  else if(nivelSonido>SonidoAlto)
  {
     digitalWrite(pinVerde,LOW);
     digitalWrite(pinRojo,HIGH);
     digitalWrite(pinAmbar,LOW);
     Serial.println("ROJO");
  }
  
}
