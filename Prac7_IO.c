#include <avr/io.h>

// Macros
#define SetBitPort(port, bit) __asm__ ( ?? )
#define ClrBitPort(port, bit) __asm__ ( ?? )

enum ButtonPressStates
{
  eBtnUndefined = 0,
  eBtnShortPressed,
  eBtnLongPressed
}
// External definitions (ASM)
extern void delay(uint16_t mseg);

// Local definitions prototypes
void    InitPorts(void);
uint8_t checkBtn(void);
void    updateLeds(void);

// Global variables
uint8_t  globalCounter;
uint32_t millis;

int main(void)
{
	InitPorts();

	while(1)
    {
		switch(check_Btn())
        {
			case eBtnShortPressed: globalCounter++;
						break;
			case eBtnLongPressed:	globalCounter--;
						break;
		}
		updateLeds();
		delay(1);
		millis++;	
	}
}