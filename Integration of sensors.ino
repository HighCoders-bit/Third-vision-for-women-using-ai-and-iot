#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include "VoiceRecognitionV3.h"
#include <TinyGPS.h>

float gpslat, gpslon;
int vib_pin=45;
int terminal=40;
int state = 0;
int pin = 42;
int val;
int d=0;
int i,l=1;
int vib_mot=38;

/*initialise lcd*/
LiquidCrystal lcd(8,9,4,5,6,7);
TinyGPS gps; 
VR myVR(52,53);

uint8_t records[7];
uint8_t buf[64];

 int relay = 46;
 


#define help    (0)
#define safe   (1)

void printSignature(uint8_t *buf, int len)
{
  int i;
  for (i = 0; i < len; i++) {
    if (buf[i] > 0x19 && buf[i] < 0x7F) {
      Serial.write(buf[i]);
    }
    else {
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if (buf[0] == 0xFF) {
    Serial.print("NONE");
  }
  else if (buf[0] & 0x80) {
    Serial.print("UG ");
    Serial.print(buf[0] & (~0x80), DEC);
  }
  else {
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if (buf[3] > 0) {
    printSignature(buf + 4, buf[3]);
  }
  else { 
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}
/*vibration motor*/


void setup()
{
  lcd.begin(16, 2);
  lcd.print("SMARTWOMENSECURITY");
  lcd.setCursor(2,1);
  lcd.print("WELCOME");
  delay(10000);
  lcd.clear();
  
  /** initialize */
  myVR.begin(9600);

  Serial.begin(115200);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nControl relay sample");
  //GPS&GSM

  pinMode(relay, OUTPUT);
 
  
 Serial1.begin(9600);
Serial2.begin(9600);
//vibration motor
pinMode(vib_mot,OUTPUT);
//manual button
pinMode(pin,INPUT);
//terminal button
pinMode(terminal,INPUT);
 

  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while (1);
  }

  if (myVR.load((uint8_t)help) >= 0) {
    Serial.println("help loaded");
  }

  if (myVR.load((uint8_t)safe) >= 0) {
    Serial.println("safe loaded");
  }
 

}
void vibration()
{
   digitalWrite(vib_mot,HIGH);
     lcd.print("PresslButton");
     lcd.setCursor(0,1);
     lcd.print("StopDevice");
     delay(10000);
     lcd.clear(); 
   
 if ( digitalRead(terminal) ==HIGH)
  {

    Serial.println(0);
    digitalWrite(vib_mot, LOW);
  
    exit(0);
  } 
  delay(1000);
   digitalWrite(vib_mot,LOW);
   delay(1000);
  }
   

void loop()
{ 
   
 while (Serial1.available())
  {
    int c = Serial1.read();
    if (gps.encode(c))
    {
      gps.f_get_position(&gpslat, &gpslon);
      
    }
  }
digitalWrite(relay,HIGH);
  
  

 
   
  
  
  int ret;
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    vibration();
    lcd.clear();
      lcd.print("ACTIVATING VOICE");
      delay(10000);
   
   
    
    switch (buf[1]) {
      case help:

        digitalWrite(relay, LOW);
       break;
      case safe:

        digitalWrite(relay, HIGH);
      lcd.clear();
       lcd.print("SAFE");
       delay(1000);
       lcd.clear();
        lcd.print("LATITUDE");
        lcd.print(gpslat, 6);
         lcd.setCursor(0,1);
         lcd.print("Longitude:");
         lcd.print(gpslon, 6);
          
         delay(10000);
         lcd.clear();
         Serial2.print("\r");
      delay(1000);
       Serial2.print("AT+CMGF=1\r");
      delay(1000);
      /*Replace XXXXXXXXXX to 10 digit mobile number &
        ZZ to 2 digit country code*/
       Serial2.print("AT+CMGS=\"+917003492328\"\r");
      delay(1000);
      //The text of the message to be sent.
       Serial2.print("Im safe");
       Serial2.print("Latitude :");
       Serial2.println(gpslat, 6);
       Serial2.print("Longitude:");
       Serial2.println(gpslon, 6);
        Serial2.print("https://www.google.com/maps/?q=");
      delay(10000); 
       Serial2.write(0x1A);
      delay(1000);
          

       
     

        break;
      default:
        Serial.println("Record function undefined");
        break;
        
    }
    

    printVR(buf);
   
    } //BUTTON PRESS STARTS
    else{
      if (digitalRead(pin) == HIGH && state == 0) 
      {
        vibration();
        Serial.println(digitalRead(pin));
     lcd.clear();
      lcd.print("ACTIVATING MANUAL");
      delay(1000);
      d++;
        Serial.println(d);
       if(d%2!=0)
       { //FOR HELP WHEN VIBRATION SENSOR LOW
         if  (digitalRead(vib_pin) == 0 )
         {
          digitalWrite(relay, LOW);
         }
          
        
    } 
  
      
      else 
      { /*SAFE WHEN BUTTON PRESS TWICE*/
       for(i=0;i<d/2;i++)
       {
        digitalWrite(relay, HIGH);
        lcd.clear();
       lcd.print("SAFE");
       delay(1000);
       lcd.clear();
        lcd.print("LATITUDE");
        lcd.print(gpslat, 6);
         lcd.setCursor(0,1);
         lcd.print("Longitude:");
         lcd.print(gpslon, 6);
         delay(1000);
         lcd.clear();
     delay(10000);
         Serial2.print("\r");
      delay(1000);
       Serial2.print("AT+CMGF=1\r");
      delay(1000);
      /*Replace XXXXXXXXXX to 10 digit mobile number &
        ZZ to 2 digit country code*/
       Serial2.print("AT+CMGS=\"+917003492328\"\r");
      delay(1000);
      //The text of the message to be sent.
       Serial2.print("Im safe");
      
       Serial2.print("Latitude :");
       Serial2.println(gpslat, 6);
       Serial2.print("Longitude:");
       Serial2.println(gpslon, 6);
         Serial2.print("https://www.google.com/maps/?q=");
      delay(1000);
       Serial2.write(0x1A);
      delay(1000);
      
      }
      }
       
    }
    if (digitalRead(pin) == LOW)
    {
      state = 0;
    }
    }
    /*FOR BOTH BUTTON AND VOICE*/
    if  (digitalRead(vib_pin) == 0 )
    {
     if (digitalRead(relay) == LOW ) 
     {
      Serial.println("Hello");
        lcd.clear();
       lcd.print("(NeedHelp)");
       delay(1000);
       lcd.clear();
       lcd.print("LATITUDE");
        lcd.print(gpslat, 6);
         lcd.setCursor(0,1);
         lcd.print("Longitude:");
         lcd.print(gpslon, 6);
         delay(10000);
         lcd.clear();
      Serial2.print("\r");
      delay(1000);
      Serial2.print("AT+CMGF=1\r");
      delay(1000);
      /*Replace XXXXXXXXXX to 10 digit mobile number &
        ZZ to 2 digit country code*/
      Serial2.print("AT+CMGS=\"+917003492328\"\r");
      delay(1000);
      //The text of the message to be sent.
      Serial2.print("Im in danger");
      Serial2.println("Please check email for pic");
      Serial2.print("https://www.google.com/maps/?q=");
      Serial2.print("Latitude :");
      Serial2.println(gpslat, 6);
      Serial2.print("Longitude:");
      Serial2.println(gpslon, 6);
      delay(1000);
      Serial2.write(0x1A);
      delay(1000);
         }
    }
     
    else
    {
      Serial.println("Hey");
        lcd.clear();
       lcd.print("(Last Location)");
       delay(1000);
       lcd.clear();
        lcd.print("LATITUDE");
        lcd.print(gpslat, 6);
         lcd.setCursor(0,1);
         lcd.print("Longitude:");
         lcd.print(gpslon, 6);
         delay(10000);
         lcd.clear();
         
      Serial2.print("\r");
      delay(1000);
      Serial2.print("AT+CMGF=1\r");
      delay(1000);
      /*Replace XXXXXXXXXX to 10 digit mobile number &
        ZZ to 2 digit country code*/
      Serial2.print("AT+CMGS=\"+917003492328\"\r");
      delay(1000);
      //The text of the message to be sent.
      Serial2.print("This is my last location");
       Serial2.println("Please check email for pic");
      Serial2.print("https://www.google.com/maps/?q=");
      Serial2.print("Latitude :");
      Serial2.println(gpslat,6);
     
      Serial2.print("Longitude:");
      Serial2.println(gpslon, 6);
      delay(1000);
      Serial2.write(0x1A);
      delay(1000);
    
    }

}
