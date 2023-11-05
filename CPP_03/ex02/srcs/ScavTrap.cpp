#include "../include/ScavTrap.hpp"
#include <iostream>

// constructor initialization list
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_attack_damage = 20;
	this->_energy_points = 50;
	std::cout << "🏗 ScavTrap Constructed!"
		<< std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "💣 ScavTrap Destroyed!" << std::endl;
}

bool check_scav(int energy_points, int hit_points, std::string name)
{
    if(energy_points <= 0)
    {   
        std::cout << "🤖 " << name <<" is out of energy 😴\n";
        return false;
    }   
    else if(hit_points <= 0)
    {   
        std::cout << "🤖 " << name <<" is dead 🕱\n";
        return false;
    }   
    return true;
}

void ScavTrap::attack(const std::string& target)
{
    if (check_scav(this->_energy_points, this->_hit_points, this->_name))
    {
        std::cout << "🤖 " <<
        this->_name << " attacked " <<
        target << " causing " <<
        this->_attack_damage << " damage!" << std::endl;
        this->_energy_points -= 1;
	}
}

void ScavTrap::guardGate(void) 
{
	std::cout << "ScarvTrap " << this->_name << " is in Gate keeper mode 🤺" << std::endl;
}

