#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>

class ScalarConverter 
{
	private:
	// orthodox canonical
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter &original);
		ScalarConverter& operator=(ScalarConverter &original);

	// converters
		static std::string	turn_to_Char	(std::string input);
    	static std::string	turn_to_Int		(std::string input);
    	static std::string	turn_to_Float	(std::string input);
    	static std::string	turn_to_Double	(std::string input);
	// helpers
		static bool			type_check		(std::string input);
		static bool			check_literals	(std::string input);
		static bool 		char_counter	(std::string input);

	public:
		static void convert(std::string input);
};

#endif // SCALARCONVERTER_HPP
