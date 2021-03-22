

#include "Display.h"
#include "Arduino.h"
#include "InputOutput.h"



LiquidCrystal_I2C lcd( 0x27, 16, 2 );


void iniciodisplay()
{
    lcd.backlight();
    lcd.init();
    lcd.setCursor( 0, 0 );
    lcd.print( "PROBANDO LCDs" );
}



