#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>


int main( void ) {
    // Define points for the triangle
    Point a(2, 3);
    Point b(5, 1);
    Point c(2, 6);

    // Test cases
    Point point1(2, 5);  // Inside the triangle
    Point point2(5, 5);  // Outside the triangle
    Point point3(2, 3);  // On a vertex of the triangle (meaning outside)
    Point point4(3, 4);  // Inside the triangle
    Point point5(2, 7);  // Outside the triangle

    // Test and output results for each point
    std::cout << "Testing points with triangle formed by A(2, 3), B(5, 1), and C(2, 6):\n";

    std::cout << "Point (2, 5): ";
    bsp(a, b, c, point1);

    std::cout << "Point (5, 5): ";
    bsp(a, b, c, point2);

    std::cout << "Point (2, 3): ";
    bsp(a, b, c, point3);

    std::cout << "Point (3, 4): ";
    bsp(a, b, c, point4);

    std::cout << "Point (2, 7): ";
    bsp(a, b, c, point5);

    return 0;
}