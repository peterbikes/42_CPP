#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "🤓 Intern Default Constructor Called\n";
}

Intern::Intern(Intern &original)
{
	(void)original;
}

Intern &Intern::operator=(Intern &original)
{
	if (this == &original)
		return(*this);
	return (*this);
}

Intern::~Intern()
{
	std::cout << "💥 Intern destroyed\n";
}

// Forms;
AForm *PPF(std::string &target){return (new PresidentialPardonForm(target));}
AForm *RRF(std::string &target){return (new RobotomyRequestForm(target));}
AForm *SCF(std::string &target){return (new ShrubberyCreationForm(target));}

// Function pointer type for the factory methods
typedef AForm* (*form_types)(std::string&);
form_types selection[3] = {&PPF, &RRF, &SCF};

AForm* Intern::makeForm(std::string type, std::string target)
{
	AForm* result;
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i <= 3; i++)
	{
		if (forms[i] == type)
		{
			result = selection[i](target);
			std::cout << "Intern creates " << result->getName() << std::endl;
			return (result);
		}
	}
	std::cout << "Intern cant find that kind of form\n";
	return NULL;
}
