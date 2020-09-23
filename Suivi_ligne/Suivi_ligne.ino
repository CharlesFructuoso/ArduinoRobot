#include <Wire.h>
int capteur_droit = A0;  //entree analogique du capteur droit
int capteur_gauche = A1;  // entree analogique du capteur gauche
int valeur_capteur_droit = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A0
int valeur_capteur_gauche = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A1
int couleur_gauche; //
int couleur_droit; //
#define Pwm_Dr  5// constante de la broche 5
#define Pwm_Ga  6// constante de la broche 6

//VALIDE !!!!!!!!!!
 void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  valeur_capteur_droit = analogRead(capteur_droit); //lecture de la valeur retourné par le capteur
  if(valeur_capteur_droit>500){couleur_droit=0;} //case droite blanche
  else{couleur_droit=1;} //case droite noire
  Serial.println(valeur_capteur_droit);
  valeur_capteur_gauche = analogRead(capteur_gauche); //lecture de la valeur retourné par le capteur
  if(valeur_capteur_gauche>500){couleur_gauche=0;} //case gauche blanche
  else{couleur_gauche=1;} //case gauche noire
  
  if (couleur_droit !=couleur_gauche) //le robot dérive à gauche
  {
    Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,130);// envoie vitesse moteur droit plus rapide
    analogWrite(Pwm_Ga,100);// envoie vitesse moteur gauche
  }
  else //le robot dérive à droite
  {
     Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,100);// envoie vitesse moteur droit
    analogWrite(Pwm_Ga,130);// envoie vitesse moteur gauche plus rapide
  }
}
