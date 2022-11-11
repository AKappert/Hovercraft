#include "Components/ultrasonic.cpp"
#include "Components/infrared.cpp"
#include "Components/servo.cpp"
#include "Components/gyroscope.cpp"


// Main functionality
void setup() 
{
    pins_init();
    uart_init();
    config_ISR();
    timer2_PWM_init();
    timer1_1Hz_init(1); //the 1 enables Input Capture Interrupt
}

void loop() 
{
    int dist = read_IR_Sensor();
    print_IR_distance(dist);
    print_US_distance();

    
}