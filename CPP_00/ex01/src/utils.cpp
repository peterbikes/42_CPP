#include "../include/the_phonebook.hpp"

std::string	format_strings (std::string string)
{
	if(string.length() <= 10)
		return string;
	string = string.substr(0, 9);
	string = string.append(1, '.');
	return string;
}

std::string	validate_phonenumber (std::string string)
{
	int i = -1;
	while(1)
	{
		getline(std::cin, string);
		if(string.length() == 0)
		{
			std::cout << "you have to enter something 🦏 -> ";
			continue ;
		}
		while(++i < string.length())
		{
			if(!isdigit(string[i]))
			{
				std::cout << "I said only numbers please: " << std::endl;
				i = -1;
				break ;
			}
		}
		if(i == string.length())
				break ;
	}
	return string;
}
