#include "../includes/animals.hpp"

// othodox canonical;
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "My type is a Mistery";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &original)
{
	this->type = original.type;
	std::cout << "WrongAnimal Copy Constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal &original)
{
	this->type = original.type;
	std::cout << "WrongAnimal assignment operator called\n";
	return *this;
}

void WrongAnimal::makeSound () const
{
	std::cout << "A misterious WrongAnimal sound" << std::endl;
}

// optional constructor

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = type;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
