#include "Fixed.hpp"


#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

// std::cout << "------------------------" << std::endl;

// std::cout << Fixed::min(a,b) << std::endl;
// std::cout << "Int:" << std::endl;
// Fixed c;
// std::cout << "c: " << c << std::endl;
// Fixed d(5);
// std::cout << "d: " << d << std::endl;
// Fixed e(3);
// std::cout << "e: " << e << std::endl;
// c = d-e;
// std::cout << c << std::endl;
// c = d+e;
// std::cout << c << std::endl;
// c = d * e;
// std::cout << c << std::endl;
// c = d / e;
// std::cout << c << std::endl;

// std::cout << "Float:" << std::endl;
// Fixed g(0.5f);
// std::cout << "g: " << g << std::endl;
// Fixed h(0.3f);
// std::cout << "h: " << h << std::endl;
// c = g-h;
// std::cout << c << std::endl;
// c = g+h;
// std::cout << c << std::endl;
// c = g * h;
// std::cout << c << std::endl;
// c = g / h;
// std::cout << c << std::endl;

return 0;
}