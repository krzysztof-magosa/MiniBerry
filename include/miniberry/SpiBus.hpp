#ifndef MINIBERRY_SPI_BUS_HPP
#define MINIBERRY_SPI_BUS_HPP

#include <avr/io.h>

namespace miniberry {

    class SpiBus
    {
    public:
        static void initAsMaster(Pin& mosi, Pin& miso, Pin& sck)
        {
            mosi.makeOutput();
            miso.makeInput();
            sck.makeOutput();

            SPCR = 0;
            SPCR |= (1 << SPE); // SPI Enabled
            SPCR |= (1 << MSTR); // Master Mode
        }
    };

}

#endif
