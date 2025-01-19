#include <iostream>
#pragma once

class Fixed {
private:
    int _fixedPointValue;
    static const int _bits = 8;

public:
    Fixed( void ) {};
    Fixed(const Fixed &copy) {};
    Fixed &operator = (const Fixed &source){};
    ~Fixed( void ) {};
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
