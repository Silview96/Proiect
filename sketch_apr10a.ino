#include <Time.h>
#include <TimeLib.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
int temperatura=A3;
int a=0;
int buton1=2;
int buton2=3;
int buton3=4;
int buton4=5;

String m[4]={"1.Mesaje       ","2.Control       ","3.Temperatura       ","4.Inundatii       "};
String mm1[3]={"1.1 Necitite       ","1.2 Citite        ", "1.3 Stergere        "};
String mm2[2]={"2.1 Manual [x]  ","2.2 Automat []   "};

int i=0;
int meniu=0;
int k=0;
int j=0;
int blocat=1;
String cod="";
int sync=0;
long unix=1523384411;
char caractere[]="ceau";
String mesaj;
int adr;

void stangaApasat(int maxelement)
{
  
  if(digitalRead(buton2)==HIGH)
    {
      if(k>=maxelement)
      k--;
      while( digitalRead(buton2)==HIGH)
      {
           
      }
    }
   
}
void dreaptaApasat(int maxelement)
{
  if(digitalRead(buton3)==HIGH)
    {
      if(k<=maxelement)
      k++;
       while( digitalRead(buton3)==HIGH)
      {
           
      }
     
    }
   
}
void inainteApasat()
{
  if(digitalRead(buton4)==HIGH && meniu <=2)
    {
     j=k;
     meniu++;
     k=0;
      while( digitalRead(buton4)==HIGH)
      {
           
      }
    }
   
}
void inapoiApasat()
{
  if(digitalRead(buton1)==HIGH && meniu >=1)
    {
     j=k;
     meniu--;
     k=0;
      while( digitalRead(buton1)==HIGH)
      {
           
      }
     
    }
   
}

void minusApasat()
{
  if(digitalRead(buton2)==HIGH)
  {
    cod=cod+"-";
    while(digitalRead(buton2)==HIGH)
    {
      
    }
    
  }
}

void plusApasat()
{
  if(digitalRead(buton3)==HIGH)
  {    
    cod=cod+"+";
    while(digitalRead(buton3)==HIGH)
    {
      
    }
    
  }
}
void cancelApasat()
{
  if(digitalRead(buton1)==HIGH)
  {
    cod="";
    lcd.clear();
      while(digitalRead(buton1)==HIGH)
    {
      
    }
    
  }
}

void setup() 
{
Serial.begin(9600);
lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
lcd.backlight();//To Power ON the back light
pinMode(buton1,INPUT);
pinMode(buton2,INPUT);
pinMode(buton3,INPUT);
pinMode(buton4,INPUT);
pinMode(temperatura,INPUT);


}
void loop() 
{
  delay(100); 


/*
if(EEPROM.length()==3)
    {
      adr=0;
    }
if(Serial.available())
{
  mesaj=Serial.read();
 
  EEPROM.write(adr,mesaj);
  adr=adr+1;  
}
*/


while(blocat==1)
{
  minusApasat();
  plusApasat();
cancelApasat();
lcd.setCursor(0,0);
lcd.print("Introdu codul");
lcd.setCursor(0,1);
lcd.print(cod);

if(cod=="---+++")
{
  blocat=0;
  lcd.clear();
} 
}



   
if(meniu == 0)
{
  
 lcd.setCursor(0,0); 
  lcd.print(m[k]); 
stangaApasat(1);
dreaptaApasat(2);
inainteApasat();
inapoiApasat();
  
 
}

if(meniu==1)
{
  
 lcd.setCursor(0,0); 
 if(j==0 && k>=0 && k<=2  ){
  lcd.print(mm1[k]); 
  stangaApasat(1);
  dreaptaApasat(1);
inainteApasat();
inapoiApasat();


 }
  
  if(j==1 && k>=0 && k<=1){
  lcd.print(mm2[k]); 
stangaApasat(1);
dreaptaApasat(0);
//inainteApasat();
inapoiApasat();


  }
  
  if(j==2)
  {
    lcd.setCursor(0,0); 
     lcd.print("                      ");  
    lcd.setCursor(0,1); 
     lcd.print("Temp.Curenta ");
     lcd.print(analogRead(temperatura)/2);
     lcd.print("C");   
     inapoiApasat();
  }
  else
  {
     lcd.setCursor(0,1); 
     lcd.print("                      ");  
  }
  
}
  else
  {
     lcd.setCursor(0,1); 
     lcd.print("                      ");  
  }

  if(meniu==2)
  {

  inapoiApasat();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("mesajele");

    
  }


}




