//_-_-_-_-_-_-_-_-_-_-_-_-_ INCLUDES _-_-_-_-_-_-_-_-_-_-_-_-_\\ 

#include <avr/interrupt.h>
#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>


///_-_-_-_-_-_-_-_-_-_-_-_-_ CLASSES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 
 
class cLED {
  #define LED_PIN PB3
  #define NANO_LED_PIN PB5

  private:
     //true = on.
    bool IS_ON = false;
  public:
  
    //cLED default constructor
    cLED() {

    }
    //cLED concstructor with initializer
    cLED(bool o) {
      IS_ON = o;
    }
};

class 


///_-_-_-_-_-_-_-_-_-_-_-_-_ DEFINES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 


#define SERVO_STEP_SIZE 1
#define SERVO_CLUSTER_SIZE 3


//_-_-_-_-_-_-_-_-_-_-_-_-_ VARIABLES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 

volatile struct {

  //Enum used as a machine state "flag"
enum MACHINE_STATE {SHUTDOWN, CALCULATING, MOVING, PAUSING};
  uint8_t TX_finished:1;
  uint8_t sample:1;
  uint8_t mode:1;
  uint8_t stop:1;
//  uint8_t ADC_ready:1;
  uint8_t T1_ovf0:2;
  uint8_t T1_ovf1:2;
} flags;


void setup() {

//  (  1 ) Divide servo's 180deg range of motion into 180 / SERVO_STEP
//  (  2 ) Create array or datatype (ie an object class) to store each angle.
//          -> min/max heaps could be a good idea
//  (  3 ) Setup servo pins
//  (  4 ) Setup servo motion
//  (  5 ) Setup timers
//  (  6 ) Setup US sensor pins
//  (  7 ) 
//  (  8 ) 
//  (  9 ) 
//  ( 10 ) 
//  ( 11 ) 
 
}


////_-_-_-_-_-_-_-_-_-_-_-_-_ MAIN _-_-_-_-_-_-_-_-_-_-_-_-_\\\\

void loop() {
//  (  1 ) Check if IS_RUNNING = true.
//  (  2 ) For each step in servo's range of motion, measure distance
//  (  3 ) Store distance and servo angle into array/datatype
//  (  4 ) For search algorithm
//  (  5 ) 
//  (  6 ) 
//  (  7 ) 
//  (  8 ) 
//  (  9 ) 
//  ( 10 ) 
//  ( 11 ) 





}