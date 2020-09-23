#include <Wire.h>// bibliotheque de gestion I²C
#include <Servo.h> // Bibliothèque de gestion du Servomoteur
Servo S; // Création d’un objet de type servomoteur
#define Moteur_ad 0x38// adresse du brochement de moteur
#define Pwm_Dr  5// constante de la broche 5
#define Pwm_Ga  6// constante de la broche 6
int capteur_droit = A0;  //entree analogique du capteur droit
int capteur_gauche = A1;  // entree analogique du capteur gauche
int valeur_capteur_droit = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A0
int valeur_capteur_gauche = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A1
int couleur_gauche; //
int couleur_droit; //
const int Capteur_oeuf = A3; // E/S2, connecteur 2
int distance = 0; // initialisation de la distance à 0cm 
int nombre_franges=0; 

void setup() {
  Wire.begin();//initialisation de la liaison I²C
  pinMode(Capteur_oeuf, INPUT);
}

void suivi_ligne()
{
  valeur_capteur_droit = analogRead(capteur_droit); //lecture de la valeur retourné par le capteur
  if(valeur_capteur_droit>100){couleur_droit=0;} //case droite blanche
  else{couleur_droit=1;} //case droite noire
  
  valeur_capteur_gauche = analogRead(capteur_gauche); //lecture de la valeur retourné par le capteur
  if(valeur_capteur_gauche>500){couleur_gauche=0;} //case gauche blanche
  else{couleur_gauche=1;} //case gauche noire
  
  if (couleur_droit !=couleur_gauche) //le robot dérive à gauche
  {
    Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,150);// envoie vitesse moteur droit
    analogWrite(Pwm_Ga,100);// envoie vitesse moteur gauche plus rapide
  }
  else //le robot dérive à droite
  {
    Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,100);// envoie vitesse moteur droit plus rapide
    analogWrite(Pwm_Ga,150);// envoie vitesse moteur gauche
  }
}

void loop() {
Wire.available();
distance = analogRead(Capteur_oeuf);

//ligne supérieure
  analogWrite(Pwm_Dr,255);// vitesse du moteur droit
  analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
  Wire.beginTransmission(Moteur_ad);// adresse du moteur du  droite
  Wire.write(5);// sens du moteur ( avant)
  Wire.endTransmission();// fin de transmission 
  
  //verticale droite
  if(distance>95)
  {
    delay(1000);
    analogWrite(Pwm_Dr,0);// vitesse du moteur droit
    analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
    delay(3000); //temps pour tourner; à modifier avec alignement capteurs
    
    suivi_ligne(); //appel sous-programme suivi de ligne
    
     //ligne inférieure
     if(distance>100)
     {
       delay(1000);
       analogWrite(Pwm_Dr,0);// vitesse du moteur droit
       analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
       delay(3000); //temps pour tourner; à modifier avec alignement capteurs
       
       suivi_ligne(); //appel sous-programme suivi de ligne
         
         //entrée ligne verticale gauche
         if (nombre_franges == 6)
         {
           delay(1000);
           analogWrite(Pwm_Dr,0);// vitesse du moteur droit
           analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
           delay(3000); //temps pour tourner; à modifier avec alignement capteurs
         
           nombre_franges=0;
           suivi_ligne(); //appel sous-programme suivi de ligne
           
           //entrée ligne horizontale
           if (nombre_franges == 5)
           {
             delay(1000);
             analogWrite(Pwm_Dr,0);// vitesse du moteur droit
             analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
             delay(3000); //temps pour tourner; à modifier avec alignement capteurs
         
             nombre_franges=0;
             suivi_ligne(); //appel sous-programme suivi de ligne
             
             //entrée ligne verticale descendante
             if (nombre_franges ==3)
               {
                 delay(1000);
                 analogWrite(Pwm_Dr,0);// vitesse du moteur droit
                 analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
                 delay(3000);
                 
                 nombre_franges=0;
                 suivi_ligne(); //appel sous-programme suivi de ligne
                 
                   if (nombre_franges==1)
                   {
                     delay(1000);
                     // arrêt du robot
                     analogWrite(Pwm_Dr,0);//vitesse moteur droit
                     analogWrite(Pwm_Ga,0);//vitesse moteur gauche
                     delay(3000);
                     S.write(0); //ouverture de la pince 
                     delay(200);
                   }
               }
           }
         }
     }
  }
}
