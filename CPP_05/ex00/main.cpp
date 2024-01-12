#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include "Bureaucrat.hpp" 

int main()
{
	system("clear");
	{
	std::cout << "<--- Creation / Destruction --->\n";

	Bureaucrat no_one;

	std::cout << &no_one;

	no_one.setName("Robert");

	Bureaucrat John("John", 60);
	Bureaucrat one;
	one = no_one;
	Bureaucrat two(John);

	std::cout << &John;
	std::cout << &one;
	std::cout << &two;
	}

	//std::cout << "Press any key to proceed to next tests:" << std::endl;
	//system("read");
	//system("wait");
	//system("clear");

	{
	std::cout << "<--- Valid Increase/Decrease Testing --- >" << std::endl;

	Bureaucrat Peter("Peter", 60);
	std::cout << &Peter;
	try{
		Peter.incrementGrade(20);
	}
	catch(Bureaucrat::GradeTooHighException &except){}
	std::cout << &Peter;
	try{
		Peter.decreaseGrade(40);
	}
	catch(Bureaucrat::GradeTooHighException &except){}
	std::cout << &Peter;
	}
	
	//std::cout << "Press any key to proceed to next tests:" << std::endl;
	//system("read");
	//system("clear");

	{
	std::cout << "<--- Invalid Increase/Decrease Testing --- >" << std::endl;

	Bureaucrat Carl("Carl", 145);
	std::cout << &Carl;
	try{
		Carl.decreaseGrade(10);
	}
	catch(Bureaucrat::GradeTooLowException &except){}
	std::cout << &Carl;

	try{
		Carl.incrementGrade(200);
	}
	catch(Bureaucrat::GradeTooHighException &except){}
	std::cout << &Carl;
	}

	//std::cout << "Press any key to proceed to next tests:" << std::endl;
	//system("read");
	//system("clear");

	std::cout << "<--- Initialization with invalid values --- >" << std::endl;

	std::cout << "Attempting to create Mary, grade 160\n";
	Bureaucrat Mary("Mary", 160);
	std::cout << "Attempting to create Phill, grade -160\n";
	Bureaucrat Phill("Phill", -160);
}
