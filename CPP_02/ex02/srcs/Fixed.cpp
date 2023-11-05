#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

// def constructor, destructor, copy const, copy assig;
Fixed::Fixed()
{
	this->_fixed_point = 0;
}

Fixed::Fixed(const int x)
{
    this->_fixed_point = x*(1 << Fixed::_bits);
}

Fixed::Fixed(const float x)
{
    this->_fixed_point = roundf(x*(1 << Fixed::_bits)); 
}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed &original)
{
	this->_fixed_point = original._fixed_point;
}

Fixed& Fixed::operator=(Fixed const &original)
{
	this->_fixed_point = original._fixed_point;
	return *this;
}

//getter and setter
int Fixed::getRawBits() const
{
    return this->_fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed_point = raw;
}


// toFloat and toInt functions
float Fixed::toFloat() const
{
	return (float)this->_fixed_point / (float)(1 << Fixed::_bits);	
}

int Fixed::toInt() const
{
	return this->_fixed_point >> Fixed::_bits;	
}

// insertion (<<) op overload
std::ostream &operator<<(std::ostream &stream, const Fixed &number)
{
	stream << number.toFloat();
	return stream;
}

// 6 comparison operators: >, <, >=, <=, == and !=;
bool Fixed::operator>(Fixed const &right_side)
{
	return (this->_fixed_point > right_side._fixed_point);
}

bool Fixed::operator<(Fixed const &right_side)
{
	return (this->_fixed_point < right_side._fixed_point);
}

bool Fixed::operator>=(Fixed const &right_side)
{
	return (this->_fixed_point >= right_side._fixed_point);
}

bool Fixed::operator<=(Fixed const &right_side)
{
	return (this->_fixed_point <= right_side._fixed_point);
}

bool Fixed::operator==(Fixed const &right_side)
{
	return this->_fixed_point == right_side._fixed_point;
}

bool Fixed::operator!=(Fixed const &right_side)
{
	return !(this->_fixed_point == right_side._fixed_point);
}

// 4 arithmetic operators: +, -, *, and /;
Fixed Fixed::operator+(const Fixed &right_side)
{
	return Fixed (this->toFloat() + right_side.toFloat());
}

Fixed Fixed::operator-(const Fixed &right_side)
{
	return Fixed (this->toFloat() - right_side.toFloat());
}

Fixed Fixed::operator*(const Fixed &right_side)
{
	return Fixed (this->toFloat() * right_side.toFloat());
}

Fixed Fixed::operator/(const Fixed &right_side)
{
	return Fixed (this->toFloat() / right_side.toFloat());
}

// 4 increment/decrement: i++, i--, ++i, --i;

// pre-increment
Fixed &Fixed::operator++(void)
{
	this->_fixed_point += 1;
	return *this;
}

// post-increment
Fixed Fixed::operator++(int)
{
	// copy before increment
	float temp;
	temp = this->toFloat();
	Fixed tmp(temp);
	this->_fixed_point += 1;
	return tmp;
}

// pre-decrement
Fixed &Fixed::operator--(void)
{
	this->_fixed_point -= 1;
	return *this;
}

// post-decrement
Fixed Fixed::operator--(int)
{
		// copy before increment
	float temp;
	temp = this->toFloat();
	Fixed tmp(temp);
	this->_fixed_point -= 1;
	return tmp;
}

// and now the functions;

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
