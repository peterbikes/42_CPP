#include "../includes/animals.hpp"

// othodox canonical;
WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called\n";
}

WrongCat::WrongCat(WrongCat &original)
{
	this->type = original.type;
	std::cout << "WrongCat Copy Constructor called\n";
}

WrongCat& WrongCat::operator=(WrongCat &original)
{
	this->type = original.type;
	std::cout << "WrongCat assignment operator called\n";
	return *this;
}

void WrongCat::makeSound () const
{
	std::cout << "if you are seeing this message, Wrong Cat was called directly" << std::endl;
}
