
#include <Wire.h>// bibliotheque de gestion I²C
#define Moteur_ad 0x38// adresse du brochement de moteur
#define Pwm_Dr  5// constante de la broche 5
#define Pwm_Ga  6// constante de la broche 6
void setup()
{
  Wire.begin();//initialisation de la liaison I²C
}
void loop ()
{
  Wire.available();
  analogWrite(Pwm_Dr,0);// vitesse du moteur du  droite ( tourner a droite)
  analogWrite(Pwm_Ga,150);// vitesse du moteur du  gauche
  Wire.beginTransmission(Moteur_ad);// adresse du moteur 
  Wire.write(5);// sens du moteur ( avant)
  Wire.endTransmission();// fin de transmission 
  delay (2000);
  
  analogWrite(Pwm_Dr,0);
  analogWrite(Pwm_Ga,0);
  delay(2000);
}
  
