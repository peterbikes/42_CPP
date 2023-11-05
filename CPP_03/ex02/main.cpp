#include <iostream>
#include "include/ClapTrap.hpp"
#include "include/FragTrap.hpp"

int main ()
{
	std::cout << "Whats this ClapTrap's name?  🤖\n";
	std::string name;
	getline(std::cin, name);	
	ClapTrap clap(name);
	
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(5);

	std::cout << "Now for a FragTrap's name?  🤖\n";
	getline(std::cin, name);	
	FragTrap frag(name);
	
	frag.attack("enemy");
	frag.takeDamage(5);
	frag.beRepaired(5);
	frag.highFivesGuys();
}
