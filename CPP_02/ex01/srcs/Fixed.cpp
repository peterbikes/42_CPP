#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

// default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

// default destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point = original._fixed_point;
}

// copy assignment (=) op overload
Fixed& Fixed::operator=(Fixed const &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = original._fixed_point;
	return *this;
}

// insertion (<<) op overload
std::ostream &operator<<(std::ostream &stream, const Fixed &number)
{
	stream << number.toFloat();
	return stream;
}

// requested constructors
Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = x*(1 << Fixed::_bits);
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(x*(1 << Fixed::_bits)); 
}

// rest of functions
float Fixed::toFloat() const
{
	float A = (float)this->_fixed_point / (1 << Fixed::_bits);
	return A;
	//return (float)this->_fixed_point / (1 << Fixed::_bits);	
}

int Fixed::toInt() const
{
	return this->_fixed_point / (1 << Fixed::_bits);	
}

