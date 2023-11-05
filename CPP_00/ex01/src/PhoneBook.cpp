#include "../include/the_phonebook.hpp"

int stoi_control (std::string str)
{
	if(str.length() != 1 || (str[0] != '1' && str[0] != '2' && str[0] != '3' && str[0] != '4' && 
			str[0] != '5' && str[0] != '6' && 
			str[0] != '7' && str[0] != '8' && str[0] != '9'))
		return false;
	return true;
}

//CONSTRUCTOR BELOW
PhoneBook::PhoneBook(int count)
{
	this->count = count;
}

void	PhoneBook::addContact()
{
	Contact contact;
	std::string string;
	system("clear");
	std::cout << ADD << std::endl;
	std::cout << "Contact's first name? 👾" << std::endl;
	while(1)
	{
		getline(std::cin, string);	
		if(contact.setFirstName(string))
			break ;	
		std::cout << "you have to enter something 🦏 -> ";
	}
	std::cout << "Contact's last name? 🚀" << std::endl;
	while(1)
	{
		getline(std::cin, string);	
		if(contact.setLastName(string))
			break ;	
		std::cout << "you have to enter something 🦏 -> ";
	}
	std::cout << "Contact's nickname? 💂" << std::endl;
	while(1)
	{
		getline(std::cin, string);	
		if(contact.setNickname(string))
			break ;	
		std::cout << "you have to enter something 🦏 -> ";
	}
	std::cout << "Contact's phonenumber? 🤳 Only numbers plz" << std::endl;
	string = validate_phonenumber(string);
	contact.setPhoneNumber(string);
	std::cout << "Contact's Darkest Secret? 💩" << std::endl;
	while(1)
	{
		getline(std::cin, string);	
		if(contact.setDarkestSecret(string))
			break ;	
		std::cout << "you have to enter something 🦏 -> ";
	}
	if(count < 8)
	{
		this->contacts[count] = contact;
		this->count++;
	}
	else
	{
		this->count = 0;
		this->contacts[count] = contact;
		this->count++;
	}
	std::cout << "Contact added 🧑 press any key to continue 💻" << std::endl;
	system("read");
	system("clear");
	std::cout << PEDRO << INTRO << std::endl;
}

void	PhoneBook::searchContact()
{
	system("clear");
	std::cout << SEARCH << std::endl;
	int i = -1;
	std::string input;
	int index;

	if(this->count == 0)
	{
		std::cout << "‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ ⚠️ ‼️ " << std::endl
		<< std::endl << "No contacts to display, try adding one first 🐃" << std::endl;
		//<< "Press any key to continue 💻" << std::endl;
		//system("read");
		//system("clear");
		std::cout << PEDRO << INTRO << std::endl;
		return ;
	}

	std::cout << PHONEBOOK_TABLE << std::endl << std::endl;

	while(++i < 8)
	{
		if((this->contacts[i].getFirstName()).length() == 0)
			break ;
		std::cout << i + 1 << " )|"; 
		std::cout << std::setw(10) << format_strings(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << format_strings(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << format_strings(this->contacts[i].getNickname()) << "|";
		std::cout << std::setw(10) << format_strings(this->contacts[i].getPhoneNumber()) << "|";
		std::cout << std::setw(10) << format_strings(this->contacts[i].getDarkestSecret()) << "|" << std::endl << std::endl;
	}
	std::cout << "What contact do you want to see?" << std::endl;
	getline(std::cin, input);
	
	while(index = stoi_control(input) == false)
	{
		std::cout << "only 1-9 please\n";
		getline(std::cin, input);
	}

	index = stoi(input);

	if(index < 1 || index > 8 || (this->contacts[index-1].getFirstName()).length() == 0)
	{
		std::cout << "invalid input :("/*, press any key to go back to main menu */ << std::endl;
		//system("read");
		//system("clear");
		std::cout << PEDRO << INTRO << std::endl;
		return ;
	}
	std::cout << std::endl << std::endl;
	std::cout << "FIRST NAME: " << this->contacts[index - 1].getFirstName() << std::endl
		<< "LAST NAME: " << this->contacts[index-1].getLastName() << std::endl 
		<< "NICKNAME: " << this->contacts[index-1].getNickname() << std:: endl
		<< "PHONENUMBER: " << this->contacts[index-1].getPhoneNumber() << std::endl
		<< "DARKEST SECRET: " << this->contacts[index-1].getDarkestSecret() << std::endl << std::endl;
		//std::cout << "Press any key to go back to main menu" << std::endl;
		//system("read");
		//system("clear");
		std::cout << PEDRO << INTRO << std::endl;
		return ;
}