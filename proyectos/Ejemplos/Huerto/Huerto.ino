#include "DHT.h" // Librería del sensor DHT (Humedad y temperatura)

int pinHumedadSuelo=9; // Sensor analógico
int pinNivelAgua=7;    // Sensor analógico

int pinSensorDHT=2;

int DHTTYPE=DHT22; // el sensor es normalmente de  color blanco
//int DHTTYPE=DHT11; // el sensor es normalmente de color azul

int pinBombaRiego=8;    // Relé de la bomba de riego
int pinBombaDeposito=9; // Relé de la bomba que llena el depósito
int pinVentilador=10;

DHT dht(pinSensorDHT, DHTTYPE);

void setup() {
  Serial.begin(9600);                         // Configuramos la conexión con el PC
  
  pinMode(pinVentilador,OUTPUT);
  pinMode(pinBombaRiego,OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000); // Esperamos un tiempo para medir

// Sensores que usan librerías

  float humedadAmbiente = dht.readHumidity();
  float temperatura = dht.readTemperature();

// Sensores analógicos: hay que consultar la especificación del fabricante para los niveles y unidades

  int iHumedadSuelo=analogRead(pinHumedadSuelo);

  int iNivelAgua=analogRead(pinNivelAgua);


  if(iHumedadSuelo<70)
  { 
    digitalWrite(pinBombaRiego,HIGH); // Activamos el relé
  }
  else
  { 
    digitalWrite(pinBombaRiego,LOW);
  }

  if(iNivelAgua<60)
  { 
    digitalWrite(pinBombaDeposito,HIGH); // Activamos el relé
  }
  else
  { 
    digitalWrite(pinBombaDeposito,LOW);
  }

  if(temperatura>25)
  { 
    digitalWrite(pinVentilador,HIGH); // Activamos el relé
  }
  else
  { 
    digitalWrite(pinVentilador,LOW);
  }
  

  Serial.print("Humedad: ");
  Serial.print(humedadAmbiente);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" *C\n");
  Serial.print("Humedad Suelo: ");
  Serial.print(iHumedadSuelo);
  Serial.print(" %\t");
  Serial.println(iNivelAgua);


  
}
