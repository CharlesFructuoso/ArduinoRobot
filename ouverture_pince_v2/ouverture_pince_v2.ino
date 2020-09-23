#include <Servo.h> // Bibliothèque de gestion du Servomoteur
Servo S; // Création d’un objet de type servomoteur

void setup()
{
  S.attach(11); // E/S2, connecteur 4
  Serial.begin(9600);
}

void loop()
{
// suite chemin après prise de l'oeuf
    {
      S.write(140); //fermeture de la pince 
      delay(2000);
      S.write(120); //ouverture de la pince 
      delay(2000);
    } 
}

