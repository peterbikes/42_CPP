#include "../includes/animals.hpp"

// othodox canonical;
Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Mistery";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called\n";
}

Animal::Animal(Animal &original)
{
	this->type = original.type;
	std::cout << "Animal Copy Constructor called\n";
}

Animal& Animal::operator=(Animal &original)
{
	this->type = original.type;
	std::cout << "Animal assignment operator called\n";
	return *this;
}

void Animal::makeSound () const
{
	std::cout << "A misterious animal sound" << std::endl;
}

// optional constructor

Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = type;
}

std::string Animal::getType() const
{
	return (this->type);
}
