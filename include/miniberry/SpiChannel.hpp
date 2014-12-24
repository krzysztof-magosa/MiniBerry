#ifndef MINIBERRY_SPI_CHANNEL_HPP
#define MINIBERRY_SPI_CHANNEL_HPP

#include "miniberry/Pin.hpp"
#include <stdint.h>

namespace miniberry {

    class SpiChannel
    {
    public:
        SpiChannel(Pin& ss): ss(ss)
        {
            ss.makeOutput();
            ss.setValue(true);
        }

        void select()
        {
            ss.setValue(false);
        }

        void deselect()
        {
            ss.setValue(true);
        }

        uint8_t transfer(uint8_t data)
        {
            SPDR = data;
            while(!((SPSR) & (1 << SPIF)));
     
            return SPDR;
        }

    protected:
        Pin& ss;
    };

}

#endif
