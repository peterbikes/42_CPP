#include "../includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name) 
{
	weapon = NULL;
}

void HumanB::attack()
{
	if(!weapon)
		std::cout << this->name << " has no weapon :(" << std::endl;
	else
		std::cout << this->name << " attacks with their " 
		<< weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
