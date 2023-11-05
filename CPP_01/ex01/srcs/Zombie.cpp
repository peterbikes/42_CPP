#include "../include/Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << this->getName() << " died again ☠️\n";
}

void Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::getName()
{
	return this->name;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

