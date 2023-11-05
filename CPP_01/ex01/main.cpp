#include "./include/Zombie.hpp"
#include <stdlib.h>


int		 main ()
{
	Zombie	*horde;	
	std::string zombie_name;
	int horde_size;

	std::cout << "What should (all) zombies be called?\n";
	
	while(1)
	{
		getline(std::cin, zombie_name);
		if(!zombie_name.empty())
			break;
		std::cout << "you have to name them something:\n";
	}

	std::cout << "How big should the horde be?\n";
	std::cin >> horde_size;


	horde = zombieHorde(horde_size, zombie_name);

	for(int i = 0; i < horde_size; i++)
		horde[i].announce();
	delete[] horde;
}
