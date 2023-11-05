#include "include/Harl.hpp"

int main (int ac, char **av)
{
	Harl harl;
	if(ac != 2)
	{
		std::cout << "Wrong ac :s try again!\n";
		return 0;
	}

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int choice;
	for(int i = 0; i < 4; i++)
		if(av[1] == levels[i])
			choice = i;

	switch(choice + 1)
	{
		case 1:
			harl.complain("DEBUG");
		case 2:
			harl.complain("INFO");
		case 3:
			harl.complain("WARNING");
		case 4:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "harl is quiet at the moment x_x\n";
	}
}
