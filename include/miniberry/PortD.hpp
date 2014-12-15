#ifndef MINIBERRY_PORT_D_HPP
#define MINIBERRY_PORT_D_HPP

#include "miniberry/Port.hpp"
#include <avr/io.h>
#include <stdint.h>

namespace miniberry {

    class PortD: public Port
    {
    public:
        PortD()
        {
            port = &PORTD;
            pin = &PIND;
            ddr = &DDRD;
        }
    };

}

#endif
