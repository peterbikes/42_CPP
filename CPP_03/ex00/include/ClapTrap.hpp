#ifndef CLAPTRAP_HPP 
#define CLAPTRAP_HPP
#include <string>

class ClapTrap{

	std::string _name;
	int _hit_points;
	int _attack_damage;
	int _energy_points;

	public:
		// orthodox canonical form;
		ClapTrap(std::string);
		~ClapTrap();
		ClapTrap(ClapTrap &original);
		ClapTrap& operator=(ClapTrap &original);

		// subj functions;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif

