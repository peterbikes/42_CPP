#include "../includes/animals.hpp"

// othodox canonical;
Dog::Dog()
{
	std::cout << "🔨🐶 -> dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "💥🐶 -> dog destructor called\n";
	delete this->brain;
}

Dog::Dog(Dog &original)
{
	std::cout << "Dog Copy Constructor called\n";
	this->brain = new Brain();
	*this = original;
}

Dog& Dog::operator=(Dog &original)
{
	this->type = original.type;
	delete this->brain;
	this->brain = new Brain (*original.brain);
	std::cout << "Dog assignment operator called\n";
	return *this;
}

void Dog::makeSound () const
{
	std::cout << "woof woof" << std::endl;
}

void Dog::brainAddress ()
{
	std::cout << &(this->brain) << std::endl;
}
