#include "Fixed.hpp"

Fixed::Fixed ( void ) : _fixedPointValue(0) {
    // std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed ( const int integer ) : _fixedPointValue(integer << _bits) {
    // std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed ( const float floatNumber ) :_fixedPointValue(roundf(floatNumber * (1 << _bits))){
    // std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &copy) {
    // std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = copy.getRawBits();
};

Fixed &Fixed::operator = ( const Fixed &source ) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source){
        _fixedPointValue = source.getRawBits();
    }
    return *this;
};

Fixed::~Fixed ( void ) {
    // std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const {
    return _fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    _fixedPointValue = raw;
}

float Fixed::toFloat( void ) const {
    return (float)_fixedPointValue / (1 << _bits);
}

int Fixed::toInt( void ) const {
    return _fixedPointValue >> _bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

// Comparison operators:
bool Fixed::operator<(const Fixed& other) const {
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed& other) const {
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->toFloat() != other.toFloat();
}

//arithmetic operators:
Fixed   Fixed::operator+(const Fixed& other) const{
    Fixed output;

    output.setRawBits(this->_fixedPointValue + other.getRawBits());
    return output;
}

Fixed   Fixed::operator-(const Fixed& other) const{
    Fixed output;

    output.setRawBits(this->_fixedPointValue - other.getRawBits());
    return output;
}

Fixed   Fixed::operator*(const Fixed& other) const{
    Fixed output;

    output.setRawBits((this->_fixedPointValue * other.getRawBits()) >> _bits);
    return output;
}

Fixed   Fixed::operator/(const Fixed& other) const{
    Fixed output;

    output.setRawBits((this->_fixedPointValue << _bits) / other.getRawBits());
    return output;
}

//increment/decrement
Fixed   &Fixed::operator++( void ) {
        _fixedPointValue += 1;
        return *this;
}

Fixed   &Fixed::operator-- ( void ) {
        _fixedPointValue -= 1;
        return *this;
}

Fixed   Fixed::operator++ ( int ) {
        Fixed   temp = *this;
        _fixedPointValue+= 1;
        return *this;
}

Fixed   Fixed::operator-- ( int ) {
        Fixed   temp = *this;
        _fixedPointValue-= 1;
        return *this;
}


Fixed &Fixed::min ( Fixed &fix_point_1, Fixed &fix_point_2 ) {
    return (fix_point_1 <= fix_point_2) ? fix_point_1 : fix_point_2;
}
    
const Fixed &Fixed::min ( const Fixed &fix_point_1, const Fixed &fix_point_2 ){
    return (fix_point_1 <= fix_point_2) ? fix_point_1 : fix_point_2;
}

Fixed &Fixed::max ( Fixed &fix_point_1, Fixed &fix_point_2 ) {
    return (fix_point_1 >= fix_point_2) ? fix_point_1 : fix_point_2;
}

const Fixed &Fixed::max ( const Fixed &fix_point_1, const Fixed &fix_point_2 ){
    return (fix_point_1 >= fix_point_2) ? fix_point_1 : fix_point_2;
}