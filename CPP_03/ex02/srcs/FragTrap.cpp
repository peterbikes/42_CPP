#include "../include/FragTrap.hpp"
#include <iostream>

// constructor initialization list
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_attack_damage = 30;
	this->_energy_points = 100;
	std::cout << "🏗 FragTrap Constructed!"
		<< std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "💣 FragTrap Destroyed!" << std::endl;
}

bool check_frag(int energy_points, int hit_points, std::string name)
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

void FragTrap::attack(const std::string& target)
{
    if (check_frag(this->_energy_points, this->_hit_points, this->_name))
    {
        std::cout << "🤖 " <<
        this->_name << " attacked " <<
        target << " causing " <<
        this->_attack_damage << " damage!" << std::endl;
        this->_energy_points -= 1;
	}
}

void FragTrap::highFivesGuys(void) 
{
	std::cout << "FragTrap requests your high five ! 🖐" << std::endl;
}

