MiniBerry AVR Framework
=======================

A bunch of little components to make AVR developer's life easier.


Example of getting value from MCP 3008 ADC converter
```c++
#include <avr/io.h>
#include <stdlib.h>

int main(void)
{
    miniberry::PortB portB;

    miniberry::Pin ss(portB, 2);
    miniberry::Pin mosi(portB, 3);
    miniberry::Pin miso(portB, 4);
    miniberry::Pin sck(portB, 5);
    
    miniberry::SpiChannel adc(ss);

    mb::SpiBus::initAsMaster(mosi, miso, sck);

    uint8_t channel = 0; // (0-7)

    adc.select();
    adc.transfer(1);
    uint8_t upper = adc.transfer((8 + channel) << 4);
    uint8_t lower = adc.transfer(0);
    adc.deselect();

    uint16_t output = ((upper & 0b11) << 8) + lower;

    return 0;
}
```
