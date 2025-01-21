#include "Fixed.hpp"    
#pragma once

class Point {
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point( void );
    Point( const float f1, const float f2);
    Point( const Point &copy );
    Point &operator=(const Point &source);
    ~Point( void );
    Fixed   get_X( void ) const;
    Fixed   get_Y( void ) const;
};

Fixed   get_Area( Point const a, Point const b, Point const c );
bool isInside(Point const a, Point const b, Point const c, Point const p);
void bsp( Point const a, Point const b, Point const c, Point const point);
