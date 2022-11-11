// File will do Servo Turns and Init the servo
#include "defines.h"

#define MIDDLE = 90;
#define LEFT = 0;
#define RIGHT = 180;
Servo myservo;

void init_servo()
{
    myservo.attach(SERVO_PIN);
    myservo.write(MIDDLE);
}

void servo_left()
{
    myservo.write(LEFT);
}

void servo_right()
{
    myservo.write(RIGHT);
}
