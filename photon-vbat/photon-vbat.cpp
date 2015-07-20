#include "application.h"

/*
After cloud synchonization

Mon Jul 20 06:27:47 2015
Mon Jul 20 06:27:47 2015
Mon Jul 20 06:27:47 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:49 2015
Mon Jul 20 06:27:49 2015

USB power supply removed
Powering on after some Time

Mon Jul 20 06:27:45 2015
Mon Jul 20 06:27:45 2015
Mon Jul 20 06:27:45 2015
Mon Jul 20 06:27:45 2015
Mon Jul 20 06:27:45 2015
Mon Jul 20 06:27:46 2015
Mon Jul 20 06:27:46 2015
Mon Jul 20 06:27:46 2015
Mon Jul 20 06:27:46 2015
Mon Jul 20 06:27:46 2015
Mon Jul 20 06:27:47 2015
Mon Jul 20 06:27:47 2015
Mon Jul 20 06:27:47 2015
M

*/
SYSTEM_MODE(MANUAL);

void setup(){
  pinMode(D7,OUTPUT);
  pinMode(WKP,INPUT_PULLDOWN);
  Serial.begin(9600);
  delay(1000);
  if(digitalRead(WKP) == HIGH){
    Spark.connect();
    Spark.syncTime();
  }
}

void loop(){
  digitalWrite(D7,!digitalRead(D7));
  Serial.println(Time.timeStr());
  delay(200);
}
