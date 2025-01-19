#include <iostream>
#include <cmath>

#pragma once

class Fixed {
private:
    int _fixedPointValue;
    static const int _bits = 8;

public:
    Fixed( void );
    explicit Fixed( const int integer );
    explicit Fixed( const float floatNumber );
    Fixed( const Fixed &copy );
    Fixed &operator = ( const Fixed &source );
    ~Fixed( void );

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
