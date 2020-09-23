#include <Wire.h>// bibliotheque de gestion I²C
#include <Servo.h> // Bibliothèque de gestion du Servomoteur
Servo S; // Création d’un objet de type servomoteur
#define Moteur_ad 0x38// adresse du brochement de moteur
#define Pwm_Dr  5// constante de la broche 5
#define Pwm_Ga  6// constante de la broche 6

const int Capteur_oeuf = A3; // E/S2, connecteur 2
int distance = 0; // initialisation de la distance à 0cm 
int nombre_franges=0; 

void setup() {
  Wire.begin();//initialisation de la liaison I²C
  pinMode(Capteur_oeuf, INPUT);
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
    
    analogWrite(Pwm_Dr,255);// vitesse du moteur droit
    analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
    
     //ligne inférieure
     if(distance>100)
     {
       delay(1000);
       analogWrite(Pwm_Dr,0);// vitesse du moteur droit
       analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
       delay(3000); //temps pour tourner; à modifier avec alignement capteurs
       
       analogWrite(Pwm_Dr,255);// vitesse du moteur droit
       analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
         
         //entrée ligne verticale gauche
         if (nombre_franges == 6)
         {
           delay(1000);
           analogWrite(Pwm_Dr,0);// vitesse du moteur droit
           analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
           delay(3000); //temps pour tourner; à modifier avec alignement capteurs
         
           nombre_franges=0;
           analogWrite(Pwm_Dr,255);// vitesse du moteur droit
           analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
           
           //entrée ligne horizontale
           if (nombre_franges == 5)
           {
             delay(1000);
             analogWrite(Pwm_Dr,0);// vitesse du moteur droit
             analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
             delay(3000); //temps pour tourner; à modifier avec alignement capteurs
         
             nombre_franges=0;
             analogWrite(Pwm_Dr,255);// vitesse du moteur droit
             analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
             
             //entrée ligne verticale descendante
             if (nombre_franges ==3)
               {
                 delay(1000);
                 analogWrite(Pwm_Dr,0);// vitesse du moteur droit
                 analogWrite(Pwm_Ga,255);// vitesse du moteur gauche
                 delay(3000);
                 
                 nombre_franges=0;
                 analogWrite(Pwm_Dr,255);
                 analogWrite(Pwm_Ga,255);
                 
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
