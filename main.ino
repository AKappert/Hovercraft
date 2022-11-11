//_-_-_-_-_-_-_-_-_-_-_-_-_ INCLUDES _-_-_-_-_-_-_-_-_-_-_-_-_\\

#include <avr/interrupt.h>
#include <stdlib.h>
#include <avr/io.h>



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


///_-_-_-_-_-_-_-_-_-_-_-_-_ DEFINES _-_-_-_-_-_-_-_-_-_-_-_-_\\\


#define SERVO_STEP_SIZE 1



//_-_-_-_-_-_-_-_-_-_-_-_-_ VARIABLES _-_-_-_-_-_-_-_-_-_-_-_-_\\



void setup() {

//  (  1 ) Divide servo's 180deg range of motion into 180 / SERVO_STEP
//  (  2 ) Create array or datatype (ie an object class) to store each angle
//  (  3 ) 
//  (  4 ) 
//  (  5 ) 
//  (  6 ) 
//  (  7 ) 
//  (  8 ) 
//  (  9 ) 
//  ( 10 ) 
//  ( 11 ) 
}


////_-_-_-_-_-_-_-_-_-_-_-_-_ MAIN _-_-_-_-_-_-_-_-_-_-_-_-_\\\\

void loop() {






}