
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
  Wire.beginTransmission(Moteur_ad);// adresse du moteur droit
  Wire.write(1);// sens du moteur ( avant)
  Wire.endTransmission();// fin de transmission 
  analogWrite(Pwm_Dr,255);// vitesse du moteur du  droite vitesse pour qui tourne a droite 


  Wire.beginTransmission(Moteur_ad);// adresse du moteur  gauche
  Wire.write(4);// sens du moteur (avant)
  Wire.endTransmission();// fin de transmission 
  analogWrite(Pwm_Ga,150);// vitesse du moteur gauche 
}
  
