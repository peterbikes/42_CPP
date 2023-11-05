#include "../includes/animals.hpp"

// othodox canonical;
Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called\n";
}

Cat::Cat(Cat &original)
{
	this->type = original.type;
	std::cout << "Cat Copy Constructor called\n";
}

Cat& Cat::operator=(Cat &original)
{
	this->type = original.type;
	std::cout << "Cat assignment operator called\n";
	return *this;
}

void Cat::makeSound () const
{
	std::cout << "miau miau" << std::endl;
}
