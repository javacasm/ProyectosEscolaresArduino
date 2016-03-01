
/***   Included libraries  ***/
#include <Wire.h>
#include <BitbloqLiquidCrystal.h>
#include <SoftwareSerial.h>
#include <BitbloqSoftwareSerial.h>


/***   Global variables and function definition  ***/
int zumbador_0 = 6;LiquidCrystal lcd_0(0);int led_Fin_9 = 9;int led_inicio_3 = 3;int sensor_fin_10 = 10;int sensor_inicio_2 = 2;int boton_0 = 12;bqSoftwareSerial puerto_serie_0(0,1,9600);void CheckReset (){if(digitalRead(12) == 1){digitalWrite(led_Fin_9,LOW);digitalWrite(led_inicio_3,LOW);/*
Borramos la segunda línea
*/lcd_0.setCursor(0,0);lcd_0.print("Cinematica!!!");lcd_0.setCursor(0,1);lcd_0.print("                                                    ");}}

/***   Setup  ***/
void setup(){lcd_0.begin(16, 2);lcd_0.clear();pinMode(led_Fin_9, OUTPUT);pinMode(led_inicio_3, OUTPUT);pinMode(sensor_fin_10, INPUT);pinMode(sensor_inicio_2, INPUT);pinMode(boton_0, INPUT);lcd_0.setBacklight(HIGH);lcd_0.setCursor(0,0);lcd_0.print("Cinematica!!!");lcd_0.setCursor(0,1);lcd_0.print("                                                    ");}

/***   Loop  ***/
void loop(){if(digitalRead(2) == 1){int tiempo_Inicial = millis();puerto_serie_0.println(tiempo_Inicial);tone(zumbador_0,261,20);
delay(20);digitalWrite(led_inicio_3,HIGH);digitalWrite(led_Fin_9,LOW);delay(100);while (digitalRead(10) == 0){delay(100);if(digitalRead(10) == 1){int tiempo_Final = millis();tone(zumbador_0,440,20);
delay(20);float Tiempo_transcurrido = (tiempo_Final - tiempo_Inicial);digitalWrite(led_Fin_9,HIGH);lcd_0.setCursor(0,1);lcd_0.print(Tiempo_transcurrido);puerto_serie_0.println(Tiempo_transcurrido);break;}CheckReset();}}CheckReset();}