#include "../includes/animals.hpp"

// othodox canonical;
Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called\n";
}

Dog::Dog(Dog &original)
{
	this->type = original.type;
	std::cout << "Dog Copy Constructor called\n";
}

Dog& Dog::operator=(Dog &original)
{
	this->type = original.type;
	std::cout << "Dog assignment operator called\n";
	return *this;
}

void Dog::makeSound () const
{
	std::cout << "woof woof" << std::endl;
}
