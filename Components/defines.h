// INCLUDES

//#include "C:\Program Files (x86)\Arduino\libraries\Servo\src\Servo.h"
//#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.h"
#include "Arduino.h"
#include "avr/interrupt.h"
#include "stdlib.h"
#include "avr/io.h"

// PIN DEFINITIONS
// LED PINS
#define LED_PIN PB3 
#define NANO_LED_PIN PB5

// SERVO PINS
#define SERVO_PIN PB1

// ULTRASONIC SENSOR PINS
#define ECHO_PIN PD2
#define TRIG_PIN PB5

// INFRARED SENSOR PINS
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define DATA_PIN A0

#define F_CPU 16000000UL
#define BAUD 9600UL
#define UBRR ((F_CPU)/((BAUD)*(16UL))-1)
#define SCL_CLOCK 100000L

#define PWM_TOP 2500

#define MIN_RANGE 15
#define MAX_RANGE 40