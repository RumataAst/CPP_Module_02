#include "Fixed.hpp"

Fixed::Fixed ( void ) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = copy.getRawBits();
};

Fixed &Fixed::operator = ( const Fixed &source ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source){
        _fixedPointValue = source.getRawBits();
    }
    return *this;
};

Fixed::~Fixed ( void ) {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    _fixedPointValue = raw;
}
