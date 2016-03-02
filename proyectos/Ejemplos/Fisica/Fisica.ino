
/***   Included libraries  ***/
#include <Wire.h>
#include <BitbloqLiquidCrystal.h>
#include <SoftwareSerial.h>
#include <BitbloqSoftwareSerial.h>


/***   Global variables and function definition  ***/
int zumbador_0 = 6;
LiquidCrystal lcd_0(0);
int led_Fin_9 = 9;
int led_inicio_3 = 3;
int sensor_fin_10 = 10;
int sensor_inicio_2 = 2;
int boton_0 = 12;

bqSoftwareSerial puerto_serie_0(0,1,9600);

// Comprobamos si se ha pulsado el botón
void CheckReset ()
{
  if(digitalRead(boton_0) == 1) // Si se pulsa el botón reseteamos el proceso
  {
    // Apagamos los dos leds
    digitalWrite(led_Fin_9,LOW);
    digitalWrite(led_inicio_3,LOW);
    /* Borramos la segunda línea*/
    lcd_0.setCursor(0,0);
    lcd_0.print("Cinematica!!!");
    lcd_0.setCursor(0,1);
    lcd_0.print("                                                    "); // Borramos la 2ª línea
  }
}

/***   Configuración ***/
void setup()
{
// Inicializamos la pantalla
lcd_0.begin(16, 2);
lcd_0.clear();
// Establecemos los pines de entrada y salida
pinMode(led_Fin_9, OUTPUT);
pinMode(led_inicio_3, OUTPUT);
pinMode(sensor_fin_10, INPUT);
pinMode(sensor_inicio_2, INPUT);
pinMode(boton_0, INPUT);
// Dibujamos la pantalla inicial
lcd_0.setBacklight(HIGH);
lcd_0.setCursor(0,0);
lcd_0.print("Cinematica!!!");
lcd_0.setCursor(0,1);
lcd_0.print("                                                    ");
}

/***   Loop  ***/
void loop()
{
  if(digitalRead(sensor_inicio_2) == 1)
  {
    int tiempo_Inicial = millis(); // Empezamos a medir tiempos
    puerto_serie_0.println(tiempo_Inicial);
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
        lcd_0.setCursor(0,1);
        lcd_0.print(Tiempo_transcurrido);
        puerto_serie_0.println(Tiempo_transcurrido);
        break;
      }
      CheckReset(); // Comprobamos el pulsador
    }
  }
  CheckReset(); // Comprobamos el pulsador
}
