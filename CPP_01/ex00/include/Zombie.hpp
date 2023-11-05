#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>


class Zombie{
	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
		std::string	getName();
	private:
		std::string name;
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

// NOTES
/*
Stack allocation is generally more eff    icient and has automatic deallocation when     the object's scope ends. However, the sta    ck size is limited, and large objects or o    bjects with a long lifetime might not be s    uitable for stack allocation.
  
Heap allocation, on the other hand, allows     for dynamic memory allocation with a pote    ntially larger size, but it requires expli    cit deallocation to avoid memory leaks. It     is often used for objects with unknown or     longer lifetimes.
 
In this context, the subject seems to be e    xploring the trade-offs and considerations     when deciding between stack and heap allo    cation for zombies, which could be objects     with varying lifetimes and sizes.
*/
#endif
