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

    bool operator<( const Fixed& other ) const;
    bool operator>( const Fixed& other ) const;
    bool operator<=( const Fixed& other ) const;
    bool operator>=( const Fixed& other ) const;
    bool operator==( const Fixed& other ) const;
    bool operator!=( const Fixed& other ) const;    

    Fixed   operator+( const Fixed& other ) const;
    Fixed   operator-( const Fixed& other ) const;
    Fixed   operator*( const Fixed& other ) const;
    Fixed   operator/( const Fixed& other ) const;
  
    Fixed   &operator++( void );
    Fixed   &operator-- ( void );
    Fixed   operator++ ( int );
    Fixed   operator-- ( int );

    static Fixed &min ( Fixed &fix_point_1, Fixed &fix_point_2 );
    static const Fixed &min ( const Fixed &fix_point_1, const Fixed &fix_point_2 );
    static Fixed &max ( Fixed &fix_point_1,Fixed &fix_point_2 );
    static const Fixed &max ( const Fixed &fix_point_1,const Fixed &fix_point_2 );

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
