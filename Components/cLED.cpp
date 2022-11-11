/*
This class is used to represent an LED. It can either be a pwm controlled LED
with adjustable brightness, or a discrete LED that can be on or off. This LED
object will be responsible for initializing it's port pins, turning the object 
on or off, and setting the brightness if possible.
*/


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
    cLED(bool on, LED_TYPE l_type, float dimness) {
      IS_ON = on;
      led_type = l_type;
      dim_value = dimness;
    }

    // Function used to set arduino ports
    void initialize_LED(){

    }

    // Function used to set PWM dimness value
    void set_dimness (float dimness){
      dim_value = dimness;
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


