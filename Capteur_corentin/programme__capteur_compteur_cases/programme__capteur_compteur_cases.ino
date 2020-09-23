// programme calculant le nombre de cases parcourues par le robot
// programme non fonctionnel

int signal_analogique_cc = A2;  //entree analogique du capteur compteur de cases
int pin_cc = 0;                 // pin sur laquelle le capteur compteur de cases est branche
int c = 0;
int n = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(pin_cc, OUTPUT);  
}

void loop()
{
  digitalWrite(pin_cc, HIGH);
  c = analogRead(signal_analogique_cc);    // lecture de l'octet, valeur entre 0 et 1023
  
   if(c > 500)
   {
     
   }
}
