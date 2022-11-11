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

void ddr_init()
{
  DDRC = (1<<DATA_PIN);   //Sets only A0 as INPUT
  DDRB = (1<<LED_PIN);
  DDRB |= (1<<NANO_LED_PIN);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
}

void uart_init() { // TX and RX init with IRQ
  UBRR0H = (uint8_t)((UBRR)>>8); // Set the UART speed as defined by UBRR
  UBRR0L = (uint8_t)UBRR;
  UCSR0B|=(1<<TXCIE0)|(1<<TXEN0); // Enable TX and TX IRQ.
  UCSR0B|=(1<<RXCIE0)|(1<<RXEN0); // Enable RX and RX IRQ 
  UCSR0C=(3<<UCSZ00); // Asynchronous UART, 8-N-1
}// end UART init