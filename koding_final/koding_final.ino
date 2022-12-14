#include <ESP8266WiFi.h>
#define limit 2
#define limitt 3
#define rain 12
byte ldr =A0; // D6
  int in1 = 15; //  PIN D8
  int in2 = 14; // PIN D5

  
 int limitbaca2 = 1;
  int limitbaca = 1;
void limitread() {
 limitbaca = digitalRead(limit);
 limitbaca2 = digitalRead(limitt);
  Serial.println(limitbaca);
}
void gerakkanan() {
      digitalWrite(in1,LOW);
    digitalWrite(in2, HIGH); 
}
void gerakkiri() {
        digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
}
void mandek() {
          digitalWrite(in1,HIGH);
    digitalWrite(in2, HIGH);
}
void setup () {
  Serial.begin(9600);
  pinMode(rain, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(limit, INPUT_PULLUP);
  pinMode(limitt, INPUT_PULLUP);
}

void loop() {
  limitread();
  int dataldr = analogRead(ldr);
int Rain = digitalRead(rain);
     Serial.print ("ldr : ");
  Serial.println(dataldr);
  
  Serial.print("Hujan : ");
  Serial.println(Rain);
  delay(1000);
//KONDISI MALAM START 


if (dataldr < 700 && Rain == HIGH) // PAGI &TIDAKHUJAN
{
  if(limitbaca == LOW) {
 Serial.println("GERAKKIRI");
 gerakkiri();
}

else if(limitbaca2 == LOW) {
  mandek();
}
}

if (dataldr  < 600 && Rain == LOW) {
  if(limitbaca2 == LOW) {
    Serial.println("GERAKKANAN");
    gerakkanan();
  }
  else if(limitbaca == LOW) {
    mandek();
  }
}
if (dataldr > 600 && Rain == HIGH) {
  if(limitbaca2 ==LOW) {
    Serial.println ("GERAKKANAN MALAM ") ;
    gerakkanan();
  }
  else if(limitbaca== LOW) {
    mandek();
  }
}
}
