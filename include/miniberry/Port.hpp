#ifndef MINIBERRY_PORT_HPP
#define MINIBERRY_PORT_HPP

#include <stdint.h>

namespace miniberry {

    class Port
    {
    public:
        volatile uint8_t* port;
        volatile uint8_t* pin;
        volatile uint8_t* ddr;

    protected:
        Port() {}
    };

}

#endif
