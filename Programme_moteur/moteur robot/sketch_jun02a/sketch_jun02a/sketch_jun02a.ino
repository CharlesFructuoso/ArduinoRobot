#include <Wire.h>
#define moteur_adress 0x38 // initialisation du moteur
#define Pwm_dr 5// initialisation du premier moteur
#define Pwm_ga 6 // initialisation du deuxieme moteur
void setup ()
{
  Wire.begin();
}
void loop()
{
  Wire.requestFrom(moteur_adress);//l'adress du moteur
  Wire.write(2);//avancer le moteur droite
  Wire.endTransmission();
  analogWrite(Pwm_dr,255);//valeur de vitesse

  Wire.requestFrom(moteur_adress);
  Wire.write(8);
  Wire.endTransmission ();
  analogWrite(Pwm_ga,255);
}
