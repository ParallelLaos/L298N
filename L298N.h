
#ifndef	MAX_PWM_SPEED
#define	MAX_PWM_SPEED 255

#include "Arduino.h"


class L298N
{
    public:
    
        L298N(uint8_t ena, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t enb); // init pin l298 motor driver

        void initmotor();
        void motorLeftForward(uint8_t PWM);
        void motorLeftRevert(uint8_t PWM);
        void motorRightForward(uint8_t PWM);
        void motorRightRevert(uint8_t PWM);
        void motorLeftStop();
        void motorRightStop();
        void motorLeftBreak(uint8_t PWM);
        void motorRightBreak(uint8_t PWM);


    private:

        uint8_t ENA;
        uint8_t IN1;
        uint8_t IN2;
        uint8_t IN3;
        uint8_t IN4;
        uint8_t ENB;



};

#endif

