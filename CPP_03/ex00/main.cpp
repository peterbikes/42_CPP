#include <iostream>
#include "include/ClapTrap.hpp"

int main ()
{
	std::cout << "Whats this ClapTrap's name?  🤖\n";
	std::string name;
	getline(std::cin, name);	
	ClapTrap clap(name);
	
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(5);
}
