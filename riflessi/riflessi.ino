#define LED 13                
#define BUTTON 11
#define BUZZER 12
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);             
int  val = 0;
int temporandomled;
int temporandombuzzer;
double tempo;
double tempo2;
double tempoled;
double tempobuzz;
double a = 0;
double stampa; 
 
void setup() {
  pinMode(LED, OUTPUT);      
  pinMode(BUTTON, INPUT);
  pinMode(BUZZER, OUTPUT);
  lcd.begin(16,2);
  randomSeed(analogRead(0));
  lcd.print("Limite: 300");
 riflessiled();
 riflessibuzzer();
  
       
}
void riflessiled(){
  temporandomled = random(1000, 5000); 
  delay(temporandomled);
  digitalWrite(LED, HIGH);
  tempo = millis();
  while (digitalRead(BUTTON) == LOW);
  digitalWrite(LED, LOW);
  lcd.clear();
  tempoled = millis();
  tempo2 = tempoled - tempo;
  lcd.print(tempo2);
  lcd.print("ms");
  if(tempo2 > 300)
  {
    lcd.print(" MALE");
  }
  else{
    lcd.print(" BENE");
      }
}

void riflessibuzzer(){
  temporandombuzzer = random(1000, 5000);
  delay(temporandombuzzer);
  tone(BUZZER, 1000, 3000);
  tempo = millis();
  while(digitalRead(BUTTON) == LOW);
  noTone(BUZZER);
  tempoled = millis();
  tempo2 = tempoled - tempo;
  lcd.setCursor(0,1);
  lcd.print(tempo2);
  lcd.print("ms");
  if(tempo2 > 300)
  {

    lcd.print(" MALE");
  }
  else{
    lcd.print(" BENE");
      }
  
  
}

 
void loop() {

}
  
