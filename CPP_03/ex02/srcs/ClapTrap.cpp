#include "../include/ClapTrap.hpp"
#include <iostream>

// orhodox canonical form; 
// constructor & destructor
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called\n";
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called\n";
}

ClapTrap::ClapTrap(ClapTrap &original)
{
	// Copy constructor called;
	this->_name = original._name;
	this->_energy_points = original._energy_points;
	this->_hit_points = original._hit_points;
	this->_attack_damage = original._attack_damage;
}

ClapTrap& ClapTrap::operator=(ClapTrap &original)
{
	// Copy assignment operator called;
	this->_name = original._name;
	this->_energy_points = original._energy_points;
	this->_hit_points = original._hit_points;
	this->_attack_damage = original._attack_damage;
	return *this;
}

// SUBJECT FUNCTIONS
bool check_clap(int energy_points, int hit_points, std::string name)
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

void ClapTrap::attack(const std::string& target)
{
	if(check_clap(this->_energy_points, this->_hit_points, this->_name))
	{
		std::cout << "🤖 " <<
		this->_name << " attacked " <<
		target << " causing " <<
		this->_attack_damage << " damage!" << std::endl;
		this->_energy_points -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(check_clap(this->_energy_points, this->_hit_points, this->_name))
	{
		std::cout << "🤖 " <<
		this->_name << " took " <<
		amount << " amount of damage!\n";
		this->_hit_points -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(check_clap(this->_energy_points, this->_hit_points, this->_name))
	{
		std::cout << "🤖 " <<
		this->_name << " repaired itself for " <<
		amount << " points!\n";
		this->_hit_points += amount;
		this->_energy_points -= 1;
	}
}


