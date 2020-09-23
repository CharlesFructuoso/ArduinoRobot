#include <Wire.h>
#include <Servo.h> // Bibliothèque de gestion du Servomoteur
Servo S; // Création d’un objet de type servomoteur
int capteur_droit = A0;  //entree analogique du capteur droit
int capteur_gauche = A1;  // entree analogique du capteur gauche
int valeur_capteur_droit = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A0
int valeur_capteur_gauche = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A1
int couleur_gauche; 
int couleur_droit; 
#define Moteur_ad 0x38// adresse du brochement de moteur
#define Pwm_Dr  5// constante de la broche 5
#define Pwm_Ga  6// constante de la broche 6
int nombre_cases = 1;          // declaration de la variable contenant le nombre de cases parcourues, vaut car au début le robot est sur une case
int capteur_cc = A2;  //declaration de la pine ou est branche le capteur  
int etat_capteur = 0;    //variable contenant la valeur de de la lecture de l'entree analogique A2 de la variable etat_capteur_cc
int new_etat_capteur = 0;  //variable contenant la valeur de de la lecture de l'entree analogique A2 de la variable new_etat_capteur_cc
int couleur = 0;  // variable contenant la valeur 1 ou 0 case noire ou blanche de la variable etat_capteur_cc
int new_couleur = 0;  // variable contenant la valeur 1 ou 0 case noire ou blanche de la variable new_etat_capteur_cc
const int Capteur_oeuf = A3; // E/S2, connecteur 2
int distance = 0; // initialisation de la distance à 0cm 
int n=0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  S.attach(11); // E/S2, connecteur 4
  pinMode(Capteur_oeuf, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ligne();
  nombre();
  while (nombre_cases<6)
  {
     ligne();
     nombre();
  }
  delay(300);
  virage();
  nombre_cases=1;
  nombre();
  ligne();
  while(nombre_cases<6)
  {
    ligne();
    nombre();
  }
  delay(300);
  virage();
  nombre_cases=1;
  nombre();
  ligne();
  while(nombre_cases<6)
  {
    ligne();
    nombre();
    if(n==0)
    {  capteur();
      S.write(120); //pince ouverte
    if(distance > 500) // si la distance detectée est plus petite que 5cm 
      {
         arret();
         delay(1500);
         S.write(155); //fermeture de la pince quand l'oeuf est présent
         delay(1500);
         while(nombre_cases<6)
          {
          ligne();
           nombre();
           distance =100;
           n=1;
           delay(300);
           virage();
           delay(400);
           nombre_cases=1;
           nombre();
           ligne();
           while(nombre_cases<6)
           {     ligne();
               nombre();}
           delay(300);
           virage();
           nombre_cases=1;
           nombre();
           ligne();
           while(nombre_cases<4)
           {     ligne();
                 nombre();}
           delay(300);
           virage();
           nombre_cases=1;
           nombre();
           ligne();
           if(nombre_cases==1)
           {
             arret();
             delay(1500);
             S.write(120);
             delay(1500);} //pince ouverte}
        }
       }}
   }
   delay(300);
   virage();
   nombre_cases=1;
   nombre();
   ligne();
   while(nombre_cases<6)
   {     ligne();
     nombre();}
   delay(300);
   virage();
   nombre_cases=1;
   nombre();
   ligne();
   while(nombre_cases<4)
   {     ligne();
     nombre();}
   delay(300);
   virage();
   nombre_cases=1;
   nombre();
   ligne();
   if(nombre_cases==1)
   { arret();
     delay(1500);
     S.write(120);
     delay(1500);} //pince ouverte}
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

void nombre()
{
  etat_capteur = analogRead(capteur_cc);  // lecture de l'etat du capteur compteur de cases (valeur entre 0 et 1023)
  delay(20);
  new_etat_capteur = analogRead(capteur_cc);  //lecture du nouvelle etat du capteur
  
  if(etat_capteur > 500)  // donne la valeur 0 ou 1 si la case est noire ou blanche
 {couleur = 1;}
 else{couleur=0;}
 
 if( new_etat_capteur > 500)
 {new_couleur = 1;}
 else{new_couleur=0;}
 
  if( couleur != new_couleur)
  {nombre_cases = nombre_cases + 1;}  // si la case n'est pas de meme couleur on a parcouru une case on fait + 1
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

void capteur()
{   distance = analogRead(Capteur_oeuf);
    delay(30);
    Serial.println(distance);
}

void arret()
{   Wire.beginTransmission(0x38);// adresse des moteurs
    Wire.write(5);// sens des moteurs (avant)
    Wire.endTransmission();// fin de transmission 
    analogWrite(Pwm_Dr,0);// envoie vitesse moteur droit plus rapide
    analogWrite(Pwm_Ga,0);// envoie vitesse moteur gauche
}
