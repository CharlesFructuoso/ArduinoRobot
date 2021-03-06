// programme calculant le nombre de cases parcourues par le robot
// programme fonctionnel

int nombre_cases = 1;          // declaration de la variable contenant le nombre de cases parcourues, vaut car au début le robot est sur une case
int capteur_cc = A2;  //declaration de la pine ou est branche le capteur  
int etat_capteur = 0;    //variable contenant la valeur de de la lecture de l'entree analogique A2 de la variable etat_capteur_cc
int new_etat_capteur = 0;  //variable contenant la valeur de de la lecture de l'entree analogique A2 de la variable new_etat_capteur_cc
int couleur = 0;  // variable contenant la valeur 1 ou 0 case noire ou blanche de la variable etat_capteur_cc
int new_couleur = 0;  // variable contenant la valeur 1 ou 0 case noire ou blanche de la variable new_etat_capteur_cc

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  etat_capteur = analogRead(capteur_cc);  // lecture de l'etat du capteur compteur de cases (valeur entre 0 et 1023)
  delay(20);
  new_etat_capteur = analogRead(capteur_cc);  //lecture du nouvelle etat du capteur
  
  if(etat_capteur > 500)  // donne la valeur 0 ou 1 si la case est noire ou blanche
 {
   couleur = 1;
 }
 else{couleur=0;}
 
 if( new_etat_capteur > 500)
 {
   new_couleur = 1;
 }
 else{new_couleur=0;}
 
  if( couleur != new_couleur)
  {
    nombre_cases = nombre_cases + 1;  // si la case n'est pas de meme couleur on a parcouru une case on fait + 1
  }
  
  Serial.println(nombre_cases);
}
