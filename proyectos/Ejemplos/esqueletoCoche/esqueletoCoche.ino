/*
 * 
Pin Function
Digital 4 Motor 1 Direction control
Digital 5 Motor 1 PWM control
Digital 6 Motor 2 PWM control
Digital 7 Motor 2 Direction control
 */

int DirM1=4;
int DirM2=7;
int VelM1=5;
int VelM2=6;

int VelocidadMax=255;
int VelocidadMedia=120;
int Parado=0;

void setup() {
pinMode(DirM1,OUTPUT);
pinMode(DirM2,OUTPUT);
pinMode(VelM1,OUTPUT);
pinMode(VelM2,OUTPUT);
}


void adelante()
{
   digitalWrite(DirM1,HIGH);
   digitalWrite(DirM2,LOW);
}


void atras()
{
   digitalWrite(DirM1,LOW);
   digitalWrite(DirM2,HIGH);
}

void velocidad(int valorVelocidad)  // entre 0 y 255
{
  analogWrite(VelM1,valorVelocidad);
  analogWrite(VelM2,valorVelocidad);
}

void derecha()
{
   digitalWrite(DirM1,LOW);
   digitalWrite(DirM2,LOW);
}



void izquierda()
{
   digitalWrite(DirM1,HIGH);
   digitalWrite(DirM2,HIGH);
}


int distancia()
{
   return 10;
}

void loop() {
  


  if(distancia()>200)
  { velocidad(VelocidadMax); }

  if(distancia()>100)
  { velocidad(VelocidadMedia); }

  if(distancia()<10)
  {
    atras();
    delay(500); // medio segundo
    derecha();
    delay(1000); // 1 segundo
    adelante();
  }

  if(distancia()<2)
  { velocidad(Parado);}

}
