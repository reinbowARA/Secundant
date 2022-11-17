#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int h, m, s, ms; 

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,1); 
  lcd.print("HAVE A NICE DAY"); 
}

void loop(){
  lcd.setCursor(0,0); 
  ms=ms + 1; 
  lcd.setCursor(2, 0);
  if(h < 10){
    lcd.print(0);
    lcd.print(h);
  }else{
    lcd.print(h);
  }
  lcd.print(":"); 
  if(m < 10){
    lcd.print(0);
    lcd.print(m);
  }else{
    lcd.print(m);
  }
  lcd.print(":"); 
  if(s < 10){
    lcd.print(0);
    lcd.print(s);
  }else{
    lcd.print(s);
  }
  lcd.print(":");
  if(ms < 10){
    lcd.print(0);
    lcd.print(ms);
  }else{
    lcd.print(ms);
  }

  delayMicroseconds(1); //SPEED TIME

  if(ms == 99)
  {
    ms = 0;
    s=s+1;
  }
  if(s==59){ 
    s=0; 
    m=m+1; 
  } 
  if(m==59) 
  { 
  m=0; 
  h=h+1; 
  } 
  if(h==24) 
  { 
  h=0; 
  }
}