/*
An Arduino code example for interfacing with the HMC5883

by: Jordan McConnell
 SparkFun Electronics
 created on: 6/30/11
 license: OSHW 1.0, http://freedomdefined.org/OSHW

Analog input 4 I2C SDA
Analog input 5 I2C SCL
*/

#if !defined(SPARK)
  #include <Wire.h> //I2C Arduino Library
#endif

#define address 0x1E //0011110b, I2C 7bit address of HMC5883

void setup(){
  //Initialize Serial and I2C communications
  Serial.begin(9600);
  Wire.begin();

  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  #if !defined(SPARK)
    Wire.send(0x02); //select mode register
    Wire.send(0x00); //continuous measurement mode
  #else
    Wire.write(0x02); //select mode register
    Wire.write(0x00); //continuous measurement mode
  #endif
  Wire.endTransmission();
}

void loop(){

  int16_t x,y,z; //triple axis data

  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(address);
  #if !defined(SPARK)
    Wire.send(0x03); //select register 3, X MSB register
  #else
    Wire.write(0x03); //select register 3, X MSB register
  #endif
  Wire.endTransmission();


 //Read data from each axis, 2 registers per axis
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    #if !defined(SPARK)
      x = Wire.receive()<<8; //X msb
      x |= Wire.receive(); //X lsb
      z = Wire.receive()<<8; //Z msb
      z |= Wire.receive(); //Z lsb
      y = Wire.receive()<<8; //Y msb
      y |= Wire.receive(); //Y lsb
    #else
      x = Wire.read()<<8; //X msb
      x |= Wire.read(); //X lsb
      z = Wire.read()<<8; //Z msb
      z |= Wire.read(); //Z lsb
      y = Wire.read()<<8; //Y msb
      y |= Wire.read(); //Y lsb
    #endif

  }

  //Print out values of each axis
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);

  delay(250);
}
