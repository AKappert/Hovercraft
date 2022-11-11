//_-_-_-_-_-_-_-_-_-_-_-_-_ INCLUDES _-_-_-_-_-_-_-_-_-_-_-_-_\\ 
#include "defines.h"
//#include <avr/iom328p.h>
///_-_-_-_-_-_-_-_-_-_-_-_-_ DEFINES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 

void setup(){}

void loop(){


}

//_-_-_-_-_-_-_-_-_-_-_-_-_ VARIABLES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 
  
  // Enums
//   enum MACHINE_STATE {SHUTDOWN, CALCULATING, MOVING, PAUSING};
//   enum LED_TYPE {PWM, DISCRETE};
//   enum SERVO_STATE {STATIC, MOVING_CW, MOVING_CCW};

// // Flags structure
//   volatile struct {
//   uint8_t TX_finished:1;
//   uint8_t sample:1;
//   uint8_t mode:1;
//   uint8_t stop:1;
//   uint8_t T1_ovf0:2;
//   uint8_t T1_ovf1:2;
//   } flags;

// // Pulse data structure
// static volatile struct {
//   uint16_t pulse0;
//   uint16_t pulse1;
// //  uint16_t pulse3;
//   uint16_t t_start0;
//   uint16_t t_end0;
//   uint16_t t_start1;
//   uint16_t t_end1;
// } PULSE_data; 




///_-_-_-_-_-_-_-_-_-_-_-_-_ CLASSES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 
 




//_-_-_-_-_-_-_-_-_-_-_-_-_ FUNCTIONS _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 


// Function used to set servo to a int value from 0-180
// void setServoAngle(int deg) {

// }

// Function used to initialize
// void gpio_init() {
//   cli(); //Stop Interrupts
//   DDRD = (0<<ECHO_PIN); //ECHO_PIN as input
//   DDRB = ((1<<LED_PIN) | (1<<TRIG_PIN)); // LED_PIN and TRIG_PIN as output
//   sei(); //Allow Interrupts
// }


///_-_-_-_-_-_-_-_-_-_-_-_-_ SETUP _-_-_-_-_-_-_-_-_-_-_-_-_\\\\\ 

// ////_-_-_-_-_-_-_-_-_-_-_-_-_ MAIN _-_-_-_-_-_-_-_-_-_-_-_-_\\\\ 
// void loop() {
// //  (  1 ) Check if IS_RUNNING = true.
// //  (  2 ) For each step in servo's range of motion, measure distance
// //  (  3 ) Store distance and servo angle into array/datatype
// //  (  4 ) Start a loop that cycles through each value in the array/datatype
// //  (  5 ) Average values next to each other in sizes of SERVO_CLUSTER_SIZE
// //  (  6 ) Calculate what moves need to be done to move the hover craft
// //  (  7 ) 
// //  (  8 ) 
// //  (  9 ) 
// //  ( 10 ) 
// //  ( 11 ) 

// }