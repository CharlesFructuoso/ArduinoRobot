#include <Wire.h> // Bibliothèque de gestion I²C
#include <Servo.h> // Bibliothèque de gestion du Servomoteur
Servo S; // Création d’un objet de type servomoteur

const int Contacteur = 12; // E/S2, connecteur 3
int Etat_Contacteur;   //état initial contacteur

void setup()
{
  pinMode(Contacteur, INPUT); //définition du contacteur comme entrée
  Etat_Contacteur = LOW; //état initial bas
  S.attach(11); // E/S2, connecteur 4
  Serial.begin(9600);
}


void loop()
{
    Etat_Contacteur = digitalRead (Contacteur) ; //lecture de l'état du contacteur
    Serial.println(Etat_Contacteur);
  if(Etat_Contacteur == HIGH)   // si le bouton est relaché, faire 
    {
      S.write(0); //ouverture de la pince 
      delay(200);
    } 
    
  else //le bouton est toujours enfoncé, rester fermé
  {
        S.write(170); //ouverture de la pince
        delay(200);
  }
}

