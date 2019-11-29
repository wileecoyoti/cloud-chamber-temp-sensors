#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//#define ONE_WIRE_BUS 2

OneWire surface(6);
OneWire vapor(7);
OneWire midplate(8);
OneWire waterblock(9);

DallasTemperature sensorSurface(&surface);
DallasTemperature sensorVapor(&vapor);
DallasTemperature sensorMidplate(&midplate);
DallasTemperature sensorWaterblock(&waterblock);



LiquidCrystal_I2C lcd1(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd2(0x26,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display



void setup()
{

    sensorSurface.begin();
    sensorVapor.begin();
    sensorMidplate.begin();
    sensorWaterblock.begin();



  lcd1.init();                      // initialize the lcd 
  lcd2.init();
  // Print a message to the LCD. 
  lcd1.backlight();
  lcd1.setCursor(0,0); //(+right, line 0/1)
  lcd1.print("Surface:");
  lcd1.setCursor(0,1); //(+right, line 0/1)
  lcd1.print("Vapor:");
  
  lcd2.backlight();
  lcd2.setCursor(0,0);
  lcd2.print("M.Plate:");
  lcd2.setCursor(0,1);
  lcd2.print("W.Block:");

}


void loop()
{

  sensorSurface.requestTemperatures();
  sensorVapor.requestTemperatures();
  sensorMidplate.requestTemperatures();
  sensorWaterblock.requestTemperatures();

  
  lcd1.setCursor(10,0); //(+right, line 0/1)
  lcd1.print(sensorSurface.getTempCByIndex(0));
  lcd1.setCursor(10,1); //(+right, line 0/1)
  lcd1.print(sensorVapor.getTempCByIndex(0));


  lcd2.setCursor(10,0);
  lcd2.print(sensorMidplate.getTempCByIndex(0));
  lcd2.setCursor(10,1);
  lcd2.print(sensorWaterblock.getTempCByIndex(0));

  delay(1000);

}
