#include "defines.h"

volatile struct {
  uint8_t TX_finished:1;
  uint8_t sample:1;
  uint8_t mode:1;
  uint8_t stop:1;
//  uint8_t ADC_ready:1;
  uint8_t T1_ovf0:2;
  uint8_t T1_ovf1:2;
} flags;

static volatile struct {
  uint16_t pulse0;
  uint16_t pulse1;
//  uint16_t pulse3;
  uint16_t t_start0;
  uint16_t t_end0;
  uint16_t t_start1;
  uint16_t t_end1;
} PULSE_data; 

int int0_trigged = 0;
int counter = 0;




void config_ISR()
{
  EICRA = ((1<<ISC00));  //Any logical change on INT0 generates interrupt INT0
  EIMSK = (1<<INT0);  //Enable external pin interrupt
  sei(); //Set global interrupts
}

void timer1_1Hz_init(uint8_t en_IRQ) { //en_IRQ eanbles 
//set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
}

void timer2_PWM_init(){
  DDRB = (1<<LED_PIN); // PB3 = Pin #11 set as output for PWM
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22); 
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
  counter++;
  //digitalWrite(TRIG_PIN, LOW);
  PORTB &= ~(1<<TRIG_PIN);
  delayMicroseconds(11);
  PORTB &= (1<<TRIG_PIN);
  //digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(11);
  //digitalWrite(TRIG_PIN, LOW);
  PORTB &= ~(1<<TRIG_PIN);
  
  flags.T1_ovf0++;
  flags.T1_ovf1++;
}

ISR (INT0_vect) {// This gets called every time pin PB2 is changed
  int0_trigged++;
  
  if (PIND&(1<<ECHO_PIN)) { //raising edge IRQ - start of pulse
    flags.T1_ovf0=0;
    PULSE_data.t_start0=TCNT1; // There is no need to disable global interrupts as they are already disabled while and ISR is being executed.
  }
  if (!(PIND&(1<<ECHO_PIN))) { //falling edge IRQ - end of pulse
    PULSE_data.t_end0=TCNT1;
    if (flags.T1_ovf0==1)
      PULSE_data.pulse0=PWM_TOP-PULSE_data.t_start0+PULSE_data.t_end0; //one ovf
    else if (flags.T1_ovf0==2)
      PULSE_data.pulse0=PWM_TOP-PULSE_data.t_start0+PULSE_data.t_end0+PWM_TOP; //two ovfs
    else if(flags.T1_ovf0==0)
      PULSE_data.pulse0=PULSE_data.t_end0-PULSE_data.t_start0; //no ovf
    else PULSE_data.pulse0=0xFFFF; // something went wrong    
  }
}

long analog;
int dist;
int range;

void writeUSToLED(int dist)
{  
    if(dist > MAX_RANGE)
    {
      range = 250;
      PORTB = ((1<<NANO_LED_PIN));
    }

    else if(dist < MIN_RANGE)
    {
      range = 0;
      PORTB = ((1<<NANO_LED_PIN) | (1<<TRIG_PIN));
    }
    else
    {
      range = (dist-MIN_RANGE)*10.2;
      PORTB &= ~((1<<NANO_LED_PIN) | (1<<TRIG_PIN));
    }
    OCR2A = range;
    OCR2B = range;
}

void print_US_distance()
{
  Serial.print("Distance = ");
  Serial.print(PULSE_data.pulse0);
}