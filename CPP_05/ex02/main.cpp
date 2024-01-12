#include <exception>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include <unistd.h>
#include "Bureaucrat.hpp" 
#include "AForm.hpp" 
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp" 

int main()
{
    system("clear");
	{
		std::cout << "<--- Bureaucrat and Forms Creation Testing --->\n\n";
		Bureaucrat  Paul("Paul", 1);
		ShrubberyCreationForm shrub;
		ShrubberyCreationForm shrub1("Shrub2");
		RobotomyRequestForm robot;
		RobotomyRequestForm robot1("Robot1");
		PresidentialPardonForm pres;
		PresidentialPardonForm pres1("Pres1");

		std::cout << "\n<--- Paul will now try to execute unsigned forms--->\n\n";

		Paul.executeForm(shrub1);
		Paul.executeForm(robot1);
		Paul.executeForm(pres1);
	}

	/* std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    system("read");
    system("clear"); */

	{
		std::cout << "<--- ShrubberyCreationForm Testing --->\n\n";
		std::cout << "1) Creating Bureaucrat and form\n";

		Bureaucrat Peter("Peter", 1);
		Bureaucrat Peter_Fail("Peter_Fail", 150);
		ShrubberyCreationForm Shrub1("new_file");

		std::cout << "\n2) Signing ... \n";

		Peter.signForm(Shrub1);

		std::cout << "\n3) Executing ... \n";
		Peter.executeForm(Shrub1);
		std::cout << "\n4) Executing and failing... \n";
		Peter_Fail.executeForm(Shrub1);
	}

	/* std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    system("read");
    system("clear"); */

	{
		std::cout << "<--- RobotomyRequestForm Testing --->\n\n";
		std::cout << "1) Creating Bureaucrat and form\n";

		Bureaucrat Robert("Robert", 1);
		RobotomyRequestForm Robotomy;

		std::cout << "\n2) Signing ... \n";

		Robert.signForm(Robotomy);

		std::cout << "\n3) Executing, will try three times ... \n";
		Robert.executeForm(Robotomy);
		Robert.executeForm(Robotomy);
		Robert.executeForm(Robotomy);
	}

	/* std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    system("read");
    system("clear"); */

	{
		std::cout << "<--- PresidentialPardonForm Testing --->\n\n";
		std::cout << "1) Creating Bureaucrat and form\n";

		Bureaucrat Mark("Mark", 1);
		Bureaucrat Mark_Fail("Mark_Fail", 1);
		PresidentialPardonForm Pardon;

		std::cout << "\n2) Signing ... \n";

		Mark.signForm(Pardon);

		std::cout << "\n3) Executing... \n";
		Mark.executeForm(Pardon);
		std::cout << "\n4) Executing and failing... \n";
		Mark_Fail.executeForm(Pardon);
	}

}
