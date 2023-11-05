#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &weapon);
	private:
		std::string name;
		Weapon *weapon;
};

#endif
