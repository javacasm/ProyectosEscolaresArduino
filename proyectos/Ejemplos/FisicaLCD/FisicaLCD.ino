
/***   Included libraries  ***/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


/***   Global variables and function definition  ***/
int zumbador_0 = 6;
int led_Fin_9 = 9;
int led_inicio_3 = 3;
int sensor_fin_10 = 10;
int sensor_inicio_2 = 2;
int boton_0 = 12;



// Comprobamos si se ha pulsado el botón
void CheckReset ()
{
  if(digitalRead(boton_0) == 1) // Si pulsamos el botón se resetea
  {
  // Apagamos los dos leds
  digitalWrite(led_Fin_9,LOW);
  digitalWrite(led_inicio_3,LOW);
  /* Borramos la segunda línea*/
  lcd.setCursor(0,0);
  lcd.print("Cinematica!!!");
  lcd.setCursor(0,1);
  lcd.print("                                                    "); // Borramos la 2ª línea
  }
}

/***   Configuración ***/
void setup()
{
Serial.begin(9600);
// Inicializamos la pantalla
lcd.begin(16, 2);
lcd.clear();
// Establecemos los pines de entrada y salida
pinMode(led_Fin_9, OUTPUT);
pinMode(led_inicio_3, OUTPUT);
pinMode(sensor_fin_10, INPUT);
pinMode(sensor_inicio_2, INPUT);
pinMode(boton_0, INPUT);
// Dibujamos la pantalla inicial
lcd.setBacklight(HIGH);
lcd.setCursor(0,0);
lcd.print("Cinematica!!!");
lcd.setCursor(0,1);
lcd.print("                                                    ");
}

/***   Loop  ***/
void loop()
{
  if(digitalRead(sensor_inicio_2) == 1)
  {
    int tiempo_Inicial = millis(); // Empezamos a medir tiempos
    Serial.println(tiempo_Inicial);
    tone(zumbador_0,261,20); // Tono inicial
    delay(20);
    digitalWrite(led_inicio_3,HIGH);
    digitalWrite(led_Fin_9,LOW);
    delay(100);
    while (digitalRead(sensor_fin_10) == 0) // Esperamos mientras el sensor de fin no está activo
    {
      delay(100);
      if(digitalRead(sensor_fin_10) == 1) // Si se ha activado el sensor de fin medimos el tiempo
      {
        int tiempo_Final = millis();  // Medimos el tiempo final
        tone(zumbador_0,440,20); // Tono de fin
        delay(20);
        float Tiempo_transcurrido = (tiempo_Final - tiempo_Inicial);
        digitalWrite(led_Fin_9,HIGH);
        lcd.setCursor(0,1);
        lcd.print(Tiempo_transcurrido);
        Serial.println(Tiempo_transcurrido);
        break;
      }
      CheckReset(); // Comprobamos el pulsador
    }
  }
  CheckReset(); // Comprobamos el pulsador
}
