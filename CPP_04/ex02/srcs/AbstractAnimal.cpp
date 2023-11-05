#include "../includes/animals.hpp"

// othodox canonical;
AbstractAnimal::AbstractAnimal()
{
	std::cout << "AbstractAnimal constructor called" << std::endl;
	this->type = "Mistery";
}

AbstractAnimal::~AbstractAnimal()
{
	std::cout << "AbstractAnimal Destructor called\n";
}

AbstractAnimal::AbstractAnimal(AbstractAnimal &original)
{
	this->type = original.type;
	std::cout << "AbstractAnimal Copy Constructor called\n";
}

AbstractAnimal& AbstractAnimal::operator=(AbstractAnimal &original)
{
	this->type = original.type;
	std::cout << "AbstractAnimal assignment operator called\n";
	return *this;
}

void AbstractAnimal::makeSound () const
{
	std::cout << "A misterious animal sound" << std::endl;
}

// optional constructor

AbstractAnimal::AbstractAnimal(std::string type)
{
	std::cout << "AbstractAnimal constructor called" << std::endl;
	this->type = type;
}

std::string AbstractAnimal::getType() const
{
	return (this->type);
}
