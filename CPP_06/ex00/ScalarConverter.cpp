#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>


// orthodox canonical

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter &original)
{
	(void)original;
	//return (*original);
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &original)
{
	(void)original;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

// subject function

void ScalarConverter::convert(std::string input)
{
	if(check_literals(input))
		return ;
	if (type_check(input))
	{
		std::cout << 
		"As Char  : " << turn_to_Char(input) 	<< std::endl << 
		"As Int   : " << turn_to_Int(input) 	<< std::endl <<
		"As Float : " << turn_to_Float(input) 	<< std::endl <<
		"As Double: " << turn_to_Double(input) 	<< std::endl;
	}
}

// converters

std::string ScalarConverter::turn_to_Char(std::string input)
{
	bool character = true;
	if ((input.find_first_not_of("1234567890.") >= input.length()) && input.length() != 1)
		character = false;

	if(!character)
	{
		// input.c_str() is used to obtain the C-style string needed by atoi
		int c = std::atoi(input.c_str());

		if(c < 32 || c > 126)
			return "impossible";

		std::ostringstream res;
		res << "'" << static_cast<char>(c) << "'";

		return res.str();
	}
	//char *a = static_cast<char*>(input.c_str());
	std::ostringstream res;
	res << "'" << static_cast<char>(input[0]) << "'";
	return res.str();
}

std::string ScalarConverter::turn_to_Int(std::string input)
{

	bool character = false;
	if (!(input.find_first_not_of("1234567890") >= input.length()) && input.length() == 1)
		character = true;

	std::ostringstream res;

	if(character)
	{
		res << static_cast<int>(input[0]);
    	return res.str();		
	}

	char* endptr;
    long int i = std::strtol(input.c_str(), &endptr, 10);

	// used for error handling, already done before;
    (void)endptr;

    if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
    {
        return "Out of Bounds Int";
    }
	// static_cast used here
    res << static_cast<int>(i);
    return res.str();
}

std::string ScalarConverter::turn_to_Float(std::string input)
{
	bool character = false;
	if (!(input.find_first_not_of("1234567890") >= input.length()) && input.length() == 1)
		character = true;

	std::ostringstream res;

	if(character)
	{
		res << static_cast<int>(input[0]);
    	return res.str();		
	}

	char* endptr;
	float f = std::strtof(input.c_str(), &endptr);
	(void)endptr;
	// Static_cast used here
	if (std::fmod(f, 1.0) == 0)
	{
		res << std::fixed << std::setprecision(1)  << static_cast<float>(f) << "f";
		return res.str();
	}
	res << static_cast<float>(f) << "f";
	return res.str();

}

std::string ScalarConverter::turn_to_Double(std::string input)
{
	char* endptr;
	double d = std::strtod(input.c_str(), &endptr);
	(void)endptr;

	bool character = false;
	if (!(input.find_first_not_of("1234567890") >= input.length()) && input.length() == 1)
		character = true;

	// Static_cast used here
	std::ostringstream res;

	if(character)
	{
		res << static_cast<int>(input[0]);
    	return res.str();		
	}

	if (std::fmod(d, 1.0) == 0)
	{
		res << std::fixed << std::setprecision(1)  << static_cast<double>(d);
		return res.str();
	}
	res << static_cast<double>(d);
	return res.str();
}

// helpers

bool ScalarConverter::char_counter(std::string input)
{
	int e = 0;
	int dot = 0;
    
    for (size_t i = 0; i < input.length(); ++i) 
	{
        if (input[i] == 'e') 
            e++;
		if (input[i] == '.') 
            dot++;
    }
	if(dot > 1 || e > 1)
		return false;
	return true;
}


bool ScalarConverter::type_check(std::string input)
{
	std::cout << "Input    : " << input;
	if (!char_counter(input) || ((input.find_first_not_of("1234567890e.-+") <= input.length()) && input.length() > 1))
	{
			std::cout << " is invalid!\n";
			return false;
	}
	std::cout << std::endl;
	return true;
}

bool ScalarConverter::check_literals(std::string input)
{
	if(input == "nan" || input == "inf" || input == "-inf" \
	|| input == "inff" || input == "-inff")
	{
		std::cout << 
		"As Char  : impossible"	<< std::endl << 
		"As Int   : impossible" << std::endl <<
		"As Float : " << input << std::endl <<
		"As Double: " << input << std::endl;
		return true;
	}
	return false;
}