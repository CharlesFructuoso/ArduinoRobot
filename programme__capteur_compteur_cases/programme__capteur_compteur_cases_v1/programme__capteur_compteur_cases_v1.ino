// programme calculant le nombre de cases parcourues par le robot
// programme non fonctionnel

int nombre_cases = 1;          // declaration de la variable contenant le nombre de cases parcourues, vaut car au début le robot est sur une case
int etat_capteur_cc = A2;      // declaration de la variable contenant l'etat du capteur conteur de balle
int new_etat_capteur_cc = A2;  // declaration de la variable contenant le nouvelle etat du capteur compteur de cases
int pin_cc = 3;
int c = 0;
int d=0;

void setup()
{
  pinMode(pin_cc, OUTPUT);
}

void loop()
{
  digitalWrite(pin_cc, HIGH);
  c = analogRead(etat_capteur_cc);  // lecture de l'etat du capteur compteur de cases (valeur entre 0 et 1023)
  delay(10);
  d = analogRead(new_etat_capteur_cc);  //lecture du nouvelle etat du capteur
  if( c != d)
  {
    nombre_cases = nombre_cases + 1;  // si la case n'est pas de meme couleur on a parcouru une case on fait + 1
  }
  
}
