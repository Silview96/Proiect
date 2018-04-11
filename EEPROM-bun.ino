#include <Time.h>
#include <TimeLib.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

String m;
String r;
 int eeAddress = 0;
void setup() 
{
Serial.begin(9600);
lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
lcd.backlight();//To Power ON the back light

   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}
 
void loop() 
{
    delay(1000);
    while(Serial.available())
    {
      m=Serial.readStringUntil('\0');
      EEPROM.put(0,m);
    }
EEPROM.get(0,r);
lcd.setCursor(0,0);
lcd.print(r);

}




