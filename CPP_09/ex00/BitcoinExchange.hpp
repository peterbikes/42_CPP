#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	public:
		std::map<std::string, float> database;
	
	// canonical orthodox
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& original);
		BitcoinExchange& operator=(const BitcoinExchange& original);

	// main funcs
		void	exchange(std::string input_db);
		void	start_exchange(std::string input_db);
		void	return_values(std::string date, std::string value);
	
	// parsing and initiating databases
		void	validate_databases(std::string input_db);
		void	initiate_db();
		std::string	validate_date(std::string date);
		std::string	validate_value(std::string value);

	// testing
		void 	print_databases();
};

#endif // BITCOINEXCHANGE_HPP
