#include "Fixed.hpp"

Fixed::Fixed ( void ) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed ( const int integer ) : _fixedPointValue(integer << _bits) {
    std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed ( const float floatNumber ) :_fixedPointValue(roundf(floatNumber * (1 << _bits))){
    std::cout << "Float constructor called" << std::endl;
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
    return _fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    _fixedPointValue = raw;
}

// Method to convert to float (for displaying the value)
float Fixed::toFloat( void ) const {
    return (float)_fixedPointValue / (1 << _bits);
}

// Method to convert to integer (for displaying the value as an integer)
int Fixed::toInt( void ) const {
    return _fixedPointValue >> _bits;  // Right shift to remove the fractional part
}

// Definition of the non-member insertion operator (<<)
std::ostream &operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();  // Output the floating-point representation of the fixed-point value
    return out;
}

// Comparison operators:
bool Fixed::operator<(const Fixed& other) const {
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>(const Fixed& other) const {
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator==(const Fixed& other) const {
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed& other) const {
    return (this->toFloat() != other.toFloat());
}

//arithmetic operators:
Fixed   Fixed::operator+(const Fixed& other) const{
    return (this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator-(const Fixed& other) const{
    return (this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed& other) const{
    return (this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed& other) const{
    if (other.toFloat != 0)
        return (this->toFloat() / other.toFloat());
}

//increment/decrement

int &Fixed::min ( int &fix_point_1, int &fix_point_2 ) {
    return (fix_point_1 <= fix_point_2) ? fix_point_1 : fix_point_2;
}
    
const int &Fixed::min ( const int &fix_point_1, const int &fix_point_2 ){
    return (fix_point_1 <= fix_point_2) ? fix_point_1 : fix_point_2;
}

int &Fixed::max ( int &fix_point_1, int &fix_point_2 ) {
    return (fix_point_1 >= fix_point_2) ? fix_point_1 : fix_point_2;
}

const int &Fixed::max ( const int &fix_point_1, const int &fix_point_2 ){
    return (fix_point_1 >= fix_point_2) ? fix_point_1 : fix_point_2;
}