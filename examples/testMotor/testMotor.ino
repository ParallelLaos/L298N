// Name          Test Motor Driver (L298N)
// Description   test & library program
// Hardware      Arduino, Microcontroller (Arduino Platform)
// IDE           arduino 1.8.5
// Firmware by   Phonevilai VONGPHOM & Xangnam Phiasakha
// Company       Parallel 

// github      https://github.com/ParallelLaos/L298N

#include <L298N.h>

//pin driver Motor
#define ENA 10
#define IN1  9
#define IN2  8
#define IN3  7
#define IN4  6
#define ENB 5
//---------------------------------//

L298N myMotor(ENA,IN1,IN2,IN3,IN4,ENB);  // (PWM_A, pinA1, pinA2, pinB1, pinB2, PWM_B) 

char inpuT;
String inputString="";

void setup() {
  Serial.begin(9600);    
  myMotor.initmotor();   // set Mode 
}

void loop() {

  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { inpuT = Serial.read() ; }      // clear the serial buffer

    if ( inputString == "1"){
        myMotor.motorLeftForward(150); 
    } else if ( inputString == "2" ){
      myMotor.motorLeftRevert(200);
    }else if ( inputString == "3") {
        myMotor.motorRightForward(255);
    }else if ( inputString == "4" ){
        myMotor.motorRightRevert(200);
    }else if ( inputString == "5"){
       myMotor.motorLeftStop();
       myMotor.motorRightStop();     
    }

    inputString = "";
  }


} // end loop
