#include "./include/Zombie.hpp"

int main ()
{
	Zombie *dead;
	std::string name;
	std::cout << "let's create a random Zombie, how should we call it?\n";
	getline(std::cin, name);
	if(name.length() == 0)
	{
		std::cout << "you need to name the zombie something, exiting\n";
		return EXIT_SUCCESS;
	}
	randomChump(name);

	std::cout << "let's create another stronger Zombie, how should we call it?\n";
	getline(std::cin, name);
	if(name.length() == 0)
	{
		std::cout << "you need to name the zombie something, exiting\n";
		return EXIT_SUCCESS;
	}
	dead = newZombie(name);
	delete dead;

	return EXIT_SUCCESS;
}
