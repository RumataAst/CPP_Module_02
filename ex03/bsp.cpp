#include "Fixed.hpp"
#include "Point.hpp"

bool    triangle_exists(Point const a, Point const b, Point const c){
    if ((a.get_X() == b.get_X() && a.get_Y() == b.get_Y()) ||
        (a.get_X() == c.get_X() && a.get_Y() == c.get_Y()) ||
        (b.get_X() == c.get_X() && b.get_Y() == c.get_Y()) || 
        (a.get_X() == b.get_X() && a.get_X() == c.get_X()) || 
        (a.get_Y() == b.get_Y() && a.get_Y() == c.get_Y())) {
        return 0;
    }
    return 1;
}

void bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed area;
    if (!triangle_exists(a, b, c) || get_Area(a,b,c) == 0){
        std::cerr << "Triangle doesnt exist" << std::endl;
    }
    else {
        if (isInside(a, b, c, point)) {
            std::cout << "Point is inside the triangle." << std::endl;
        } else {
            std::cout << "Point is outside the triangle." << std::endl;
        }
    }
}