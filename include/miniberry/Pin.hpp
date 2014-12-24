#ifndef MINIBERRY_PIN_HPP
#define MINIBERRY_PIN_HPP

#include "miniberry/Port.hpp"
#include <avr/io.h>
#include <stdint.h>

namespace miniberry {

    class Pin
    {
    public:
        Pin(Port& port, uint8_t no): port(port), no(no)
        {
        }
        
        void setValue(bool const value)
        {
            if (value) {
                *port.port |= (1 << no);
            }
            else {
                *port.port &= ~(1 << no);
            }
        }

        bool getValue()
        {
            return *port.pin & (1 << no);
        }

        void setPullUp(bool const value)
        {
            setValue(value);
        }

        void makeInput()
        {
            *port.ddr &= ~(1 << no);
        }

        void makeOutput()
        {
            *port.ddr |= (1 << no);
        }
        
    protected:
        Port& port;
        int const no;
    };

}

#endif
