int pinMoteur = 6; // pin controlant le moteur 
void setup  ()
{
}
void loop ()
{
  analogWrite(pinMoteur,0);
  delay (1000);
  analogWrite(pinMoteur,255);
  delay (1000);
}
 
  
  
