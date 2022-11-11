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


#DEFINE SERVO_STEP 1



//_-_-_-_-_-_-_-_-_-_-_-_-_ VARIABLES _-_-_-_-_-_-_-_-_-_-_-_-_\\



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


//      ( 1 ) Divide servo's 180deg range of motion into 180 / SERVO_STEP
//      ( 2 ) 
}