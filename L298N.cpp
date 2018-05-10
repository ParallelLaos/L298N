
#include "L298N.h"

#ifndef PWM_LOW
#define PWM_LOW 0

L298N::L298N(uint8_t ena, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t enb){
    this->ENA = ena;
    this->ENB = enb;
    this->IN1 = in1;
    this->IN2 = in2;
    this->IN3 = in3;
    this->IN4 = in4;
}

void L298N::initmotor(){
        pinMode(ENA, OUTPUT);
        pinMode(ENB, OUTPUT);
        pinMode(IN1, OUTPUT);
        pinMode(IN2, OUTPUT);
        pinMode(IN3, OUTPUT);
        pinMode(IN4, OUTPUT);    
}

void L298N::motorLeftForward(uint8_t PWM){
    analogWrite(ENA,PWM);
	digitalWrite(IN1,HIGH);
	digitalWrite(IN2,LOW);
}

void L298N::motorRightForward(uint8_t PWM){
    analogWrite(ENB,PWM);
	digitalWrite(IN3,HIGH);
	digitalWrite(IN4,LOW);
}

void L298N::motorLeftRevert(uint8_t PWM){
    analogWrite(ENA,PWM);
	digitalWrite(IN1,LOW);
	digitalWrite(IN2,HIGH);
}

void L298N::motorRightRevert(uint8_t PWM){
    analogWrite(ENB,PWM);
	digitalWrite(IN3,LOW);
	digitalWrite(IN4,HIGH);
}

void L298N::motorLeftBreak(uint8_t PWM){
	analogWrite(ENA,PWM);
	digitalWrite(IN1,HIGH);
	digitalWrite(IN2,HIGH);
}

void L298N::motorRightBreak(uint8_t PWM){
	analogWrite(ENB,PWM);
	digitalWrite(IN3,HIGH);
	digitalWrite(IN4,HIGH);
}

void L298N::motorLeftStop(){
	analogWrite(ENA,PWM_LOW);
	digitalWrite(IN1,LOW);
	digitalWrite(IN2,LOW);
}

void L298N::motorRightStop(){
	analogWrite(ENB,PWM_LOW);
	digitalWrite(IN3,LOW);
	digitalWrite(IN4,LOW);
}

#endif

