#include <exception>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include "Bureaucrat.hpp" 
#include "Form.hpp" 

int main()
{
    system("clear");
	{
	std::cout << "<--- Construction, Destruction, Copying and Assigning --->\n\n";
	std::cout << "1) Construction\n\n";
	Form form1("AAAA", 11, 22);
	Form form2("BBBB", 33, 44);
	std::cout << "2) Copying and assigning\n\n";
	Form form3 = form1;
	std::cout << &form1 << "\n";
	std::cout << &form3 << "\n";
	Form form4(form2);
	std::cout << &form2 << "\n";
	std::cout << &form4 << "\n";
	std::cout << "3) Destruction\n\n";
	}

	//std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    //system("read");
    //system("clear");
	
	{
	std::cout << "<--- Bureaucrat and Signing tests --->\n";
	std::cout << "1) Bureaucrat can sign\n\n";
	Bureaucrat bur("John", 10);
	std::cout << &bur;
	Form form("XYZ", 100, 100);

	try
	{
		bur.signForm(form);
	}
	catch(std::exception& except)
	{
		std::cout << except.what();
	}
	std::cout << "Checking if form is signed...\n" << &form;
	}

	//std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    //system("read");
    //system("clear");
	
	{
	std::cout << "<--- Bureaucrat and Signing tests --->\n";
	std::cout << "2) Bureaucrat can't sign\n\n";
	Bureaucrat bur("Carl", 130);
	std::cout << &bur;
	Form form("ABC", 10, 10);
	try
	{
		bur.signForm(form);
	}
	catch(std::exception& except)
	{
		std::cout << except.what();
	}
	std::cout << "Checking if form is signed...\n" << &form;
	}

	//std::cout << "\n\nPress any key to proceed to next tests:" << std::endl;
    //system("read");
    //system("clear");
	
	{
	std::cout << "<--- Bureaucrat and Signing tests --->\n";
	std::cout << "3) Bureaucrat can't sign - form is already signed\n\n";
	Bureaucrat bur("Mike", 1);
	Form form("JKL", 10, 10);
	try
	{
		bur.signForm(form);
	}
	catch(std::exception& except)
	{
		std::cout << except.what();
	}
	std::cout << &form << "Signing second time -> should fail now\n";
	try
	{
		bur.signForm(form);
	}
	catch(std::exception& except)
	{
		std::cout << except.what();
	}
	}
}
