#include <iostream>
#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"

int main ()
{
	std::cout << "Whats this ClapTrap's name?  🤖\n";
	std::string name;
	getline(std::cin, name);	
	ClapTrap clap(name);
	
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(5);

	std::cout << "Now for a ScavTrap's name?  🤖\n";
	getline(std::cin, name);	
	ScavTrap scav(name);
	
	scav.attack("enemy");
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.guardGate();
}
