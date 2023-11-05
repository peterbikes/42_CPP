#include "../include/Fixed.hpp"
#include <iostream>

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
Fixed::Fixed(Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point = original._fixed_point;
}

// copy assignment operator overload
Fixed& Fixed::operator=(Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = original._fixed_point;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

