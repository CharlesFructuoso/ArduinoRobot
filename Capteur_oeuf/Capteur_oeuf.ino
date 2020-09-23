const int Capteur_oeuf = A3; // E/S2, connecteur 2
int distance = 0; // initialisation de la distance à 0cm 

void setup() 
{
  pinMode(Capteur_oeuf, INPUT);
  Serial.begin (9600); //initialisation liaison série à 9600 bits/seconde
}

void loop() 
{
  distance = analogRead(Capteur_oeuf);
  Serial.println(distance);
  delay(20);
}
