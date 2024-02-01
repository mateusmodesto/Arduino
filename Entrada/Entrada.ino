#include <LiquidCrystal.h>	
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int tempo_e = 0; 
int distancia_e = 0;
int temp_s = 0;
int distancia_s = 0;
int echo_entrada = 3;
int echo_saida = 4 ;
int trigger_saida = 5 ;
int trigger_entrada = 2;
int contador_entrada = 0;
int contador_saida = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  pinMode( echo_entrada, INPUT);
  pinMode( trigger_entrada, OUTPUT);
  pinMode( echo_saida, INPUT);
  pinMode( trigger_saida, OUTPUT);
}

void loop() {
  entrada();
  saida();

  lcd.setCursor(0, 1);
  lcd.print("Saida: ");
  lcd.setCursor(9, 1);
  lcd.print(contador_saida);
  lcd.setCursor(0,0);
  lcd.print("Entrada: ");
  lcd.setCursor(9,0);
  lcd.print(contador_entrada);
  delay(1000);
  lcd.clear();
}

void entrada(){
  digitalWrite(trigger_entrada, HIGH);
  digitalWrite(trigger_entrada, LOW);
  tempo_e = pulseIn(echo_entrada, HIGH);
  distancia_e = tempo_e * 0.0175;
  if (distancia_e <= 50){
    contador_entrada = contador_entrada + 1;
  }
  
}

void saida(){
  digitalWrite(trigger_saida, HIGH);
  digitalWrite(trigger_saida, LOW);
  temp_s = pulseIn(echo_saida, HIGH);
  distancia_s = temp_s * 0.0175;
  if (distancia_s <= 50){
    if (contador_saida < contador_entrada){
      contador_saida = contador_saida + 1;
    }
  }
}
