#include <Wire.h>
const int ENA=6;
void setup()
{
  Wire.begin();
  pinMode(ENA,OUTPUT);
  
}

void loop()
{
  Wire.requestFrom (0x3c,1) ;
  int octet=Wire.read() ;
  if(octet>=1)
  {
   if(octet>=3)
   {
     if(octet==3)
     {
         analogWrite(ENA ,0);
     }
     if(octet==5)
     {
         analogWrite(ENA ,255);
         Wire.beginTransmission (0x38) ;
         Wire.write(2) ;
         Wire.endTransmission() ;
     }
     if(octet==7)
     {
         analogWrite(ENA ,255);
         Wire.beginTransmission (0x38) ;
         Wire.write(1) ;
         Wire.endTransmission() ;
     }
     if(octet==9)
     {
         analogWrite(ENA ,255);
         Wire.beginTransmission (0x38) ;
         Wire.write(2) ;
         Wire.endTransmission() ;
     }
  }
    if(octet==11)
    {
       analogWrite(ENA ,255);
       Wire.beginTransmission (0x38) ;
       Wire.write(2) ;
       Wire.endTransmission() ;
    }
  }
  if(octet==1)
  {
   analogWrite(ENA ,0); 
  }
  else
  {
   analogWrite(ENA ,0); 
  }
}
