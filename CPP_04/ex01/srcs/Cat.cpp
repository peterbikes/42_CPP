#include "../includes/animals.hpp"

// othodox canonical;
Cat::Cat()
{
	std::cout << "🔨🐱 -> cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "💥🐱 -> cat destructor called\n";
	delete this->brain;
}

Cat::Cat(Cat &original)
{
	std::cout << "Cat Copy Constructor called\n";
	this->brain = new Brain();
	*this = original;
}

Cat& Cat::operator=(Cat &original)
{
	this->type = original.type;
	delete this->brain;
	this->brain = new Brain (*original.brain);
	std::cout << "Dog assignment operator called\n";
	return *this;
}

void Cat::makeSound () const
{
	std::cout << "miau miau" << std::endl;
}

void Cat::brainAddress ()
{
	std::cout << &(this->brain) << std::endl;
}
