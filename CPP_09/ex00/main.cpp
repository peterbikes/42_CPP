#include "BitcoinExchange.hpp"

int main(int ac, char **av)	
{
	if(ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl
			<< "Run me like: $./btc <filename>\n";
		return 0;
	}
	BitcoinExchange btc;
	btc.exchange(av[1]);
}
