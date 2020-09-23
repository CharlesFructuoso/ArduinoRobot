#include <Wire.h>
const int ENA = 5; 

void setup()
{
  Wire.begin() ;
  pinMode (ENA, OUTPUT);
  Serial.begin(9600);
}

void loop()
{  
  int n;
  Wire.requestFrom(0x3C,1);
  n = Wire.read();
 
 //vitesse 3
  if(n==5)
    {
      analogWrite(ENA, 80);
      Wire.beginTransmission (0x38) ;
      Wire.write(1) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
    if (n==6)
    {
      analogWrite(ENA, 80);
      Wire.beginTransmission (0x38) ;
      Wire.write(2) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
    
 //vitesse 4
  if(n==9)
    {
      analogWrite(ENA, 100);
      Wire.beginTransmission (0x38) ;
      Wire.write(1) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
    if (n==10)
    {
      analogWrite(ENA, 100);
      Wire.beginTransmission (0x38) ;
      Wire.write(2) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
    
 //vitesse 5
    if(n==17)
    {
      analogWrite(ENA, 120);
      Wire.beginTransmission (0x38) ;
      Wire.write(1) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
    if (n==18)
    {
      analogWrite(ENA, 120);
      Wire.beginTransmission (0x38) ;
      Wire.write(2) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
 
 //vitesse 6 
    if(n==33)
    {
      analogWrite(ENA, 140);
      Wire.beginTransmission (0x38) ;
      Wire.write(1) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
    if (n==34)
    {
      analogWrite(ENA, 140);
      Wire.beginTransmission (0x38) ;
      Wire.write(2) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
 //vitesse 7
  if(n==65)
    {
      analogWrite(ENA, 145);
      Wire.beginTransmission (0x38) ;
      Wire.write(1) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
    if (n==66)
    {
      analogWrite(ENA, 145);
      Wire.beginTransmission (0x38) ;
      Wire.write(2) ;
      Wire.endTransmission() ;
      Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
    
 //vitesse 8
    if(n==129)
    {
      analogWrite(ENA, 150);
      Wire.beginTransmission (0x38) ;
      Wire.write(1) ;
      Wire.endTransmission() ;
      for (int i=0; i<2; i++)
    { int u = pow(2,i);
      Wire.beginTransmission (0x39) ; // Envoie de l'adresse du périphérique I²C
      Wire.write(u) ;
      Wire.endTransmission() ;
      delay (50);
    }
  for (int i=2; i<8; i++)
    { int u = pow(2,i);
      Wire.beginTransmission (0x39) ; // Envoie de l'adresse du périphérique I²C
      Wire.write(u+1) ;
      Wire.endTransmission() ;
      delay (50);
    }
    }
    
    if (n==130)
    {
      analogWrite(ENA, 150);
      Wire.beginTransmission (0x38) ;
      Wire.write(2) ;
      Wire.endTransmission() ;
      for (int i=0; i<2; i++)
    { int u = pow(2,i);
      Wire.beginTransmission (0x39) ; // Envoie de l'adresse du périphérique I²C
      Wire.write(u) ;
      Wire.endTransmission() ;
      delay (50);
    }
  for (int i=2; i<8; i++)
    { int u = pow(2,i);
      Wire.beginTransmission (0x39) ; // Envoie de l'adresse du périphérique I²C
      Wire.write(u+1) ;
      Wire.endTransmission() ;
      delay (50);
    }
    }
    
    if (n<3)
    {
    analogWrite(ENA, 0);
    Wire.beginTransmission (0x38) ;
    Wire.write(1) ;
    Wire.endTransmission() ;
    Wire.beginTransmission (0x39) ;
      Wire.write(n) ;
      Wire.endTransmission() ;
    }
}  
  
