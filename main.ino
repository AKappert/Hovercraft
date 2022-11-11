#include "Components/ultrasonic.cpp"
#include "Components/infrared.cpp"
//#include "Components/servo.cpp"
#include "Components/gyroscope.cpp"
#include "Components/setup.cpp"
#include "Servo.h"
#include "Servo.h"
// Main functionality
void setup() 
{
    pins_init();
    uart_init();
    config_ISR();
    timer2_PWM_init();
    timer1_1Hz_init(1); //the 1 enables Input Capture Interrupt
    Servo curr_servo;
    curr_servo.attach(SERVO_PIN);
    //init_servo(myservo);
}

void loop() 
{
    //int dist = read_IR_Sensor();
    //print_IR_distance(dist);
    print_US_distance();
}