#include <Wire.h>
const int Capteur_oeuf = A3; // E/S2, connecteur 2
int distance = 0; // initialisation de la distance à 0cm 
int capteur_droit = A0;  //entree analogique du capteur droit
int capteur_gauche = A1;  // entree analogique du capteur gauche
int valeur_capteur_droit = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A0
int valeur_capteur_gauche = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A1
int couleur_gauche; //
int couleur_droit; //
#define Moteur_ad 0x38// adresse du brochement de moteur
#define Pwm_Dr  5// constante de la broche 5
#define Pwm_Ga  6// constante de la broche 6

void setup() {
  pinMode(Capteur_oeuf, INPUT);
  Serial.begin (9600); //initialisation liaison série à 9600 bits/seconde
  Wire.begin();
}

void loop() 
{
  capteur(); //appel fonction capteur infrarouge
  while (distance<300) //tant que le bord est assez loin
  { capteur(); //appel de la fonction capteur
    ligne(); //suivre la ligne
  }
   virage(); //tourner à droite
   delay(500);
   capteur(); //appel fonction capteur infrarouge
   
   while (distance<300) //tant que le bord est assez loin
  { capteur(); //appel de la fonction capteur
    ligne(); //suivre la ligne
  }
   virage(); //tourner à droite
   arret(); //arreter le robot
   delay(15000);
}

void capteur()
{   distance = analogRead(Capteur_oeuf);
    delay(30);
    Serial.println(distance);
}
  
void ligne()
{
  valeur_capteur_droit = analogRead(capteur_droit); //lecture de la valeur retourné par le capteur
  if(valeur_capteur_droit>500){couleur_droit=0;} //case droite blanche
  else{couleur_droit=1;} //case droite noire
  
  valeur_capteur_gauche = analogRead(capteur_gauche); //lecture de la valeur retourné par le capteur
  if(valeur_capteur_gauche>500){couleur_gauche=0;} //case gauche blanche
  else{couleur_gauche=1;} //case gauche noire
  
  if (couleur_droit != couleur_gauche) //le robot dérive à gauche
  {
    Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,140);// envoie vitesse moteur droit plus rapide
    analogWrite(Pwm_Ga,100);// envoie vitesse moteur gauche
  }
  
  else //le robot dérive à droite
  {
    Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,100);// envoie vitesse moteur droit
    analogWrite(Pwm_Ga,140);// envoie vitesse moteur gauche plus rapide
  } 
}

void virage()
{ 
    Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,0);// envoie vitesse moteur droit plus rapide
    analogWrite(Pwm_Ga,130);// envoie vitesse moteur gauche
    delay(1000);
}

void arret()
{   Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,0);// envoie vitesse moteur droit plus rapide
    analogWrite(Pwm_Ga,0);// envoie vitesse moteur gauche
}
