#ifndef MINIBERRY_PORT_C_HPP
#define MINIBERRY_PORT_C_HPP

#include "miniberry/Port.hpp"
#include <avr/io.h>
#include <stdint.h>

namespace miniberry {

    class PortC: public Port
    {
    public:
        PortC()
        {
            port = &PORTC;
            pin = &PINC;
            ddr = &DDRC;
        }
    };

}

#endif
