#include <iostream>
#include <cstring>

int main (int ac, char **av)
{
	int i, k = 1;

	if(ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISES *" << std::endl;
		return 0;
	}
	while (av[k])
	{
		i = 0;
		while(av[k][i])
			std::cout << (char)toupper(av[k][i++]);
		k++;
	}
	std::cout << std::endl;
	return 0;
}
