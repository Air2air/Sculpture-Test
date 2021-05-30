#include <avr/eeprom.h>
#include <stdlib.h>


void setup( void );

void loop( void );


void reseedRandom( uint32_t* address )
{
  static const uint32_t HappyPrime = 937;
  uint32_t raw;
  unsigned long seed;
  uint32_t* code;
  uint8_t i;
  uint32_t offset;

  offset = 0;

  /* The following adds 1050 - 922 = 128 bytes of code.  Is it worth the 128 bytes? */
/* */
  code = (uint32_t*)(setup);
  i = 0;
  do
  {
    offset ^= pgm_read_dword( code );
    ++code;
    ++i;
  }
  while ( i != 0 );
/* */

  raw = eeprom_read_dword( address );

  do
  {
    raw += HappyPrime;
    seed = (raw + offset) & 0x7FFFFFFF;
  }
  while ( (seed < 1) || (seed > 2147483646) );

  srandom( seed );  

  eeprom_write_dword( address, raw );
}

inline void reseedRandom( unsigned short address )
{
  reseedRandom( (uint32_t*)(address) );
}


uint32_t reseedRandomSeed EEMEM = 0xFFFFFFFF;
