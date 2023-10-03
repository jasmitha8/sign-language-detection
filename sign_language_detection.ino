#include <LiquidCrystal.h>
const int rs = 7, en =9, d4 =10, d5 =11, d6 =12, d7 =13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte interruptPin1 = 8;
 
 
int voice1 = 2;
int voice2 = 3;
int voice3 = 4;
int voice4 = 5;
int voice5 = 6;
int voice6 = 0;
 
int pulses=0,Thumb,Index,Middle,Ring,Little,Body_Temp;
int sec1=0,stat1=0;
 
void setup() {
    pinMode(interruptPin1, INPUT);
    pinMode(voice1,OUTPUT);
    pinMode(voice2,OUTPUT);
    pinMode(voice3,OUTPUT);
    pinMode(voice4,OUTPUT);
    pinMode(voice5,OUTPUT);
    pinMode(voice6,OUTPUT);
    Serial.begin(9600);
 
    lcd.begin(16, 2);
    lcd.print("  Welcomr To    ");
    lcd.setCursor(voice6, 1);
    lcd.print("Sign to Speech          ");
    delay(5000);
}
void loop() {
    lcd.clear();
    int t;
    Thumb = analogRead(A0);
    Index = analogRead(A1);
    Middle = analogRead(A2);
    Ring = analogRead(A3);
    Little = analogRead(A4);
    Body_Temp=analogRead(A5);
    Body_Temp=Body_Temp/2-1;
    digitalWrite(voice6,LOW);
    Serial.println(Little);
 
 
    if(Body_Temp>45)
    {
        digitalWrite(voice6,HIGH);
        delay(5000);
        digitalWrite(voice6,LOW); 
    }
    if(Thumb>250)
    {
        digitalWrite(voice1,LOW);
        lcd.setCursor(voice6, 1);
        lcd.print("I Want Water     ");
    }
    if(Thumb<250)
    {
        digitalWrite(voice1,HIGH);
    }
    if(Index>270)
    {
        digitalWrite(voice2,LOW);
        lcd.setCursor(voice6, 1);
        lcd.print("I Want Food     ");
    }
    if(Index<270)
    {
        digitalWrite(voice2,HIGH);
    }
    if(Middle>270)
    {
        digitalWrite(voice3,LOW);
        lcd.setCursor(voice6, 1);
        lcd.print("PLS Help Me      ");
    }
    if(Middle<270)
    {
        digitalWrite(voice3,HIGH);
    }
    if(Ring>270)
    {
        digitalWrite(voice4,LOW);
        lcd.setCursor(voice6, 1);
        lcd.print("Hi How Are U          ");
    }
    if(Ring<270)
    {
        digitalWrite(voice4,HIGH);
    }
    if(Little>250)
    {
        digitalWrite(voice5,LOW);
        lcd.setCursor(voice6, 1);
        lcd.print("I Go Outside");
    }
    if(Little<250)
    {
        digitalWrite(voice5,HIGH);
 
    }
    if(digitalRead(interruptPin1)==HIGH)
    {
        if(stat1==0)
        {
            stat1=1;
            pulses++;
        }
    }
 
 
    else
        stat1=0;
 
    lcd.setCursor(0, 0);
    lcd.print("HB= ");
    lcd.print(pulses);
    Serial.print(pulses);
    Serial.print(";");
    // delay(1000);
    lcd.setCursor(10, 0);
 
    lcd.print("T= ");
    lcd.print(Body_Temp);
 
    sec1++;
    if(sec1==460)
    {
        sec1=0;
        Serial.print(pulses);
 
        pulses=0;
 
    }
    if( pulses>90)
    {
        digitalWrite(voice6,HIGH);
        delay(3000);
        digitalWrite(voice6,LOW);
    }
    delay(100);
 
}