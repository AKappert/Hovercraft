#include "defines.h"

long time;
int dist;
int range;
long return_ir_time(){return time;}
int return_ir_dist(){return dist;}
int return_ir_range(){return range;};

uint8_t analog_reference = DEFAULT;

uint16_t readFromPin(uint8_t pin)
{
    uint8_t low, high;
    if (pin >= 14) pin -= 14; // allow for channel or pin numbers
    ADMUX = (analog_reference << 6) | (pin & 0x07);
    sbi(ADCSRA, ADSC);
    while (bit_is_set(ADCSRA, ADSC));
    low  = ADCL;
    high = ADCH;
    return (high << 8) | low;
}

void writeIRToLED(int dist)
{  
    if(dist > MAX_RANGE)
    {
      range = 255;
      PORTB |= (1<<NANO_LED_PIN);
      _delay_us(500);
    }

    else if(dist < MIN_RANGE)
    {
      range = 0;
      PORTB |= (1<<NANO_LED_PIN);
    }
    else
    {
      range = (dist-MIN_RANGE)*10.2;
      PORTB &= ~(1<<NANO_LED_PIN);
    }
    OCR2A = range;
    OCR2B = range;
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int read_IR_Sensor()
{
  int result = readFromPin(DATA_PIN);
  float volts = result * 0.004882812;
  dist = 13*pow(volts, -1)* 2.54 -3;
  return dist;
}

void print_IR_distance(int dist)
{
  Serial.print("Dist :")
  Serial.println(dist);
}


