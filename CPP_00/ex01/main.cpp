#include "./include/the_phonebook.hpp"

/* Maybe add some colors;
 - https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal */
// Center the fucking text;
// I still need to test if Makefile is blocking post 98 or whatever

int main ()
{
    system("clear");

	std::string input;
	std::cout << PEDRO << INTRO << std::endl;

	PhoneBook phonebook(0);

	while(std::cin)
	{
        std::cout << "What would you like to do?\n" << INSTRUCTIONS
 			<< std::endl << "----> ";	
		getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			return 0;
		}
        system("clear");
		if (input == "ADD")
			phonebook.addContact();	
		else if (input == "SEARCH")
			phonebook.searchContact();	
		else
        {
            system ("clear");
			std::cout << ERROR << "Invalid option, try again!" << std::endl;
        }
	}
}
