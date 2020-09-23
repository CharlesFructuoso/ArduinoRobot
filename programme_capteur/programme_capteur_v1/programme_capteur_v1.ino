//programme donnant si la case au dessus de laquelle se situe le capteur droit et gauche est noire ou blanche
// programme non fonctionnel

int readpin1 = A1;
int readpin2 = A2;
int delir = 0;
int delir1 = 1;
int a = 0;
int b = 0;
 void setup()
{
  Serial.begin(9600);
  pinMode(delir, OUTPUT);
  pinMode(delir1, OUTPUT);
}

void loop()
{
  digitalWrite(delir, HIGH);
  a = analogRead(readpin1);    // 0 bis 1023
  digitalWrite(delir1, HIGH);
  b = analogRead(readpin2);

  Serial.print(" cptd = ");
  Serial.print(a);
  Serial.print(" cptg = ");
  Serial.print(b);
  Serial.println();
  delay(100);
}
