//Programa: Ergômetro para atletas
//Autor: Wallace Fortunato

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int rpm = 0;
volatile int rpmcont = 0;
int pinoAnalogico = A0; //PINO ANALÓGICO (MEDE A INTENSIDADE DO CAMPO MAGNÉTICO)
int pinoDigital = 8; //PINO DIGITAL (DETECTA A PRESENÇA DO CAMPO MAGNÉTICO)


void setup()
{
  pinMode(pino_sensor, INPUT);
  //Inicializa o display LCD 16x2 I2C
  lcd.begin (16, 2);
  //informacoes iniciais
  pinMode(pinoAnalogico, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoDigital, INPUT); //DEFINE O PINO COMO ENTRADA
  lcd.setCursor(0, 0);
  lcd.print("Potência do Atleta ");
  lcd.setCursor(0, 1);
  lcd.print("Potência: 0");
  Serial.println("Ergômetro");
}
