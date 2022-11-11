//_-_-_-_-_-_-_-_-_-_-_-_-_ INCLUDES _-_-_-_-_-_-_-_-_-_-_-_-_\\ 

#include <avr/interrupt.h>
#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>


///_-_-_-_-_-_-_-_-_-_-_-_-_ CLASSES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 
 
class cLED {

  private:
    enum LED_TYPE led_type;
    bool IS_ON = false;    //true = on.
    float dim_value = 0;   //0-255.

  public:
  
    //cLED default constructor
    cLED() {
      led_type = DISCRETE;
    }

    //cLED constructor with initializer. IDEALY USE THIS CONSTRUCTOR FOR DISCRETE LEDs
    cLED(bool on, LED_TYPE l_type) {
      IS_ON = on;
      led_type = l_type;
    }

    //cLED constructor with initializer. IDEALY USE THIS CONSTRUCTOR FOR PWM LEDs
    cLED(bool on, LED_TYPE l_type, float dimmness) {
      IS_ON = on;
      led_type = l_type;
      dim_value = dimmness;
    }

    // Function used to set arduino ports
    void initialize_LED(){
      
    }


    // Function used to set the LED
    void set_LED(){
      // LED is dimmable since it is PWM
      if (led_type == PWM){

      }
      // LED can only be on / off since it is DISCRETE
      else if (led_type == DISCRETE) {

      }
    }





};

class MAX_HEAP {
  
};


///_-_-_-_-_-_-_-_-_-_-_-_-_ DEFINES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 


#define SERVO_STEP_SIZE 1
#define SERVO_CLUSTER_SIZE 3

#define ECHO_PIN PD2
#define TRIG_PIN PB5

#define LED_PIN PB3
#define NANO_LED_PIN PB5
//_-_-_-_-_-_-_-_-_-_-_-_-_ VARIABLES _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 
  
  //Enum used as a machine state "flag"
  enum MACHINE_STATE {SHUTDOWN, CALCULATING, MOVING, PAUSING};
  enum LED_TYPE {PWM, DISCRETE};

// Flags structure
  volatile struct {
  uint8_t TX_finished:1;
  uint8_t sample:1;
  uint8_t mode:1;
  uint8_t stop:1;
  uint8_t T1_ovf0:2;
  uint8_t T1_ovf1:2;
  } flags;

// Pulse data structure
static volatile struct {
  uint16_t pulse0;
  uint16_t pulse1;
//  uint16_t pulse3;
  uint16_t t_start0;
  uint16_t t_end0;
  uint16_t t_start1;
  uint16_t t_end1;
} PULSE_data; 

//_-_-_-_-_-_-_-_-_-_-_-_-_ FUNCTIONS _-_-_-_-_-_-_-_-_-_-_-_-_\\\ 


// Function used to set servo to a int value from 0-180
void setServoAngle(int deg){

}

//Function used to initialize
void gpio_init() {
  cli(); //Stop Interrupts
  DDRD = (0<<ECHO_PIN); //ECHO_PIN as input
  DDRB = ((1<<LED_PIN) | (1<<TRIG_PIN)); // LED_PIN and TRIG_PIN as output
  sei(); //Allow Interrupts
} //end gpio_init













/////_-_-_-_-_-_-_-_-_-_-_-_-_ SETUP _-_-_-_-_-_-_-_-_-_-_-_-_\\\\\ 
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
//  (  4 ) Start a loop that cycles through each value in the array/datatype
//  (  5 ) Average values next to each other in sizes of SERVO_CLUSTER_SIZE
//  (  6 ) Calculate what moves need to be done to move the hover craft
//  (  7 ) 
//  (  8 ) 
//  (  9 ) 
//  ( 10 ) 
//  ( 11 ) 

}