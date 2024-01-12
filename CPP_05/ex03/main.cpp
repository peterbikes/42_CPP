#include <exception>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include <unistd.h>
#include "Bureaucrat.hpp" 
#include "Intern.hpp" 
#include "AForm.hpp" 
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp" 

int main()
{
    system("clear");
	{
		std::cout << "<--- Intern Creating Forms--->\n\n";
		std::cout << "1) Presidential Pardon form\n\n";
		Intern intern;
		AForm *form;
		form = intern.makeForm("presidential pardon", "presi form");
		if(form != 0)
		{
			std::cout << form;
			delete form;
		}
	}

	/* std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    system("read");
    system("clear"); */
	{
		std::cout << "2) Robotomy Request form\n\n";
		Intern intern;
		AForm *form;
		form = intern.makeForm("robotomy request", "robot form");
		if(form != 0)
		{
			std::cout << form;
			delete form;
		}
	}

	/* std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    system("read");
    system("clear"); */
	{
		std::cout << "3) Shrubbery Creation form\n\n";
		Intern intern;
		AForm *form;
		form = intern.makeForm("shrubbery creation", "shrub form");
		if(form != 0)
		{
			std::cout << form;
			delete form;
		}
	}

	/* std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    system("read");
    system("clear"); */
	{
		std::cout << "4) Wrong form\n\n";
		Intern intern;
		AForm *form;
		form = intern.makeForm("wrong form", "wrong form");
		if(form != 0)
		{
			std::cout << form;
			delete form;
		}
	}

}
