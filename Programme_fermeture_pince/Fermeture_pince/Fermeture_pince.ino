#include <Wire.h>
#include <Servo.h>
Servo S;

int distance; //création variable distance

void setup()
{
  S.attach(11); // E/S2, connecteur 4
}

void loop()
{
  if(distance < 5) // si la distance detectée est plus petite que 5cm 
  {
   S.write(170); //fermeture de la pince quand l'oeuf est présent
   delay(200);
  }
  
  else
  {
  }

}
