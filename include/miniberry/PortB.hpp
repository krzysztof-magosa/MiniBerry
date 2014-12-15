#ifndef MINIBERRY_PORT_B_HPP
#define MINIBERRY_PORT_B_HPP

#include "miniberry/Port.hpp"
#include <avr/io.h>
#include <stdint.h>

namespace miniberry {

    class PortB: public Port
    {
    public:
        PortB()
        {
            port = &PORTB;
            pin = &PINB;
            ddr = &DDRB;
        }
    };

}

#endif
