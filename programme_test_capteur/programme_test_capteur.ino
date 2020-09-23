// programme testant le type de capteur CNY70 afin de savoir si il est fonctionnel
// programme fonctionnel

int signal_analogique_cd = A0;  // declaration de l'entree analogique du capteur droit
int pin_cd = 0;                 // pin sur laquelle le capteur droit est branche
int a = 0;                      // varaible contenant la valeur provenant de la lecture de l'entree A0

void setup()
{
  Serial.begin(9600);
  pinMode(pin_cd, OUTPUT);  
}

void loop()
{
  digitalWrite(pin_cd, HIGH);
  a = analogRead(signal_analogique_cd);    // lecture de l'octet, valeur entre 0 et 1023
  
  if (a > 250)                            // affichage du résultat du capteur droit et gauche
  {
  Serial.print(" case droite blanche valeur de a = ");  
  Serial.print(a);
  Serial.println();
  delay(100);
  }
  else
 {
   Serial.print(" case droite noire valeur de a =");
   Serial.print(a);
   Serial.println();
   delay(100);
 }
}
