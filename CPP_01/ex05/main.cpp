#include "include/Harl.hpp"

int main (int ac, char **av)
{
	Harl harl;
	if(ac != 2)
	{
		std::cout << "Wrong ac :s try again!\n";
		return 0;
	}
	harl.complain(av[1]);
}
