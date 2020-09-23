// programme calculant le nombre de cases parcourues par le robot
// programme non fonctionnel


int nombre_cases = 1;          // declaration de la variable contenant le nombre de cases parcourues, vaut car au début le robot est sur une case
int etat_capteur_cc = A2;      // declaration de la variable contenant l'etat du capteur conteur de balle
int new_etat_capteur_cc = A2;  // declaration de la variable contenant le nouvelle etat du capteur compteur de cases
int pin_cc = 3;  //declaration de la pine ou est branche le capteur
int c = 0;    //variable contenant la valeur de de la lecture de l'entree analogique A2 de la variable etat_capteur_cc
int d = 0;  //variable contenant la valeur de de la lecture de l'entree analogique A2 de la variable new_etat_capteur_cc


void setup()
{
   Serial.begin(9600);
  pinMode(pin_cc, OUTPUT);
}

void loop()
{
  int ce = 0;  // variable contenant la valeur 1 ou 0 case noire ou blanche de la variable etat_capteur_cc
  int de = 0;  // variable contenant la valeur 1 ou 0 case noire ou blanche de la variable new_etat_capteur_cc
  
  digitalWrite(pin_cc, HIGH);
  c = analogRead(etat_capteur_cc);  // lecture de l'etat du capteur compteur de cases (valeur entre 0 et 1023)
  delay(100);
  d = analogRead(new_etat_capteur_cc);  //lecture du nouvel etat du capteur
  delay(100);
  
  if(c > 600)  // donne la valeur 0 ou 1 si la case est noire ou blanche
 {
   ce = 1;
 }
 else
 {
   ce = 0;
 }
 
 if( d > 600)
 {
   de = 1;
 }
 else
{
  de = 0;
} 
  if( ce != de)
  {
   nombre_cases = nombre_cases + 1;  // si la case n'est pas de meme couleur on a parcouru une case on fait + 1
  }
  
  Serial.println(nombre_cases);
  Serial.println(c);
}
