#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include "Zombie.hpp"

class Zombie{
	public:
		Zombie();
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
		std::string	getName();
	private:
		std::string name;
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif
