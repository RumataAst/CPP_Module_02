#include "Fixed.hpp"
#include "Point.hpp"

Point::Point ( void) : _x(0), _y(0) {}
Point::Point ( const float f1, const float f2 ): _x(f1), _y(f2) {}
Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {}

// Point &Point::operator = (const Point &source){
//     if (this != &source){
//         _x = source._x;
//     _   _y = source._y;
//     }
//     return *this;
// };
Point::~Point ( void ) {
    // std::cout << "Destructor for Point was called" << std::endl;
}

Fixed   Point::get_X( void ) const{
    return _x;
}

Fixed   Point::get_Y( void ) const {
    return _y;
}

Fixed   get_Area(Point const a, Point const b, Point const c) {
    Fixed area;
    Fixed half(0.5f);

    area = half * ((a.get_X() * (b.get_Y() - c.get_Y())) +
                  (b.get_X() * (c.get_Y() - a.get_Y())) +
                  (c.get_X() * (a.get_Y() - b.get_Y())));

    // Area should always be positive
    std::cout << area << std::endl;
    return area;
}

bool isInside(Point const a, Point const b, Point const c, Point const p){
    Fixed areaABC = get_Area(a, b, c);      // Area of the full triangle
    Fixed areaABP = get_Area(a, b, p);      // Area of triangle ABP
    Fixed areaBCP = get_Area(b, c, p);      // Area of triangle BCP
    Fixed areaCAP = get_Area(c, a, p);      // Area of triangle CAP

    // Sum of smaller triangle areas
    Fixed sumOfAreas = areaABP + areaBCP + areaCAP;
    std::cout << sumOfAreas << "vs" << areaABC << std::endl;

    // Compare the total area with the original triangle's area
    // Assuming Fixed can handle a small tolerance for floating-point comparison
    return (sumOfAreas == areaABC) && (areaABP > 0 && areaBCP > 0 && areaCAP > 0);
}