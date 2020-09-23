//programme donnant si la case au dessus de laquelle se situe le capteur droit et gauche est noire ou blanche
// programme fonctionnel
// déterminer les meilleurs seuils en faisant des tests avec le robot

int signal_analogique_cd = A0;  //entree analogique du capteur droit
int  signal_analogique_cg = A1;  // entree analogique du capteur gauche
int pin_cd = 0;  // pin sur laquelle le capteur droit est branche
int pin_cg = 1;  // pin sur laquelle le capteur gauche est branche
int a = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A0
int b = 0;  // variable contenant la valeur provenant de la lecture de l'entree analogique A1

 void setup()
{
  Serial.begin(9600);
  pinMode(pin_cd, OUTPUT);  
  pinMode(pin_cg, OUTPUT);
}

void loop()
{
  digitalWrite(pin_cd, HIGH);
  a = analogRead(signal_analogique_cd);    // lecture de l'octet, valeur entre 0 et 1023
  digitalWrite(pin_cg, HIGH);
  b = analogRead(signal_analogique_cg);  // lecture de l'octet, valeur entre 0 et 1023
  
  if (a > 100)                            // affichage du résultat du capteur droit et gauche
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
 
 Serial.println();
 
 if (b > 500)
 {
  Serial.print(" case gauche blanche ");
  Serial.print(" valeur de b =");
  Serial.println(b);
  delay(100);
 }
 else
 {
  Serial.print(" case gauche noire ");
  Serial.print(" valeur de b =");
  Serial.println(b);
  delay(100);
 }
}
