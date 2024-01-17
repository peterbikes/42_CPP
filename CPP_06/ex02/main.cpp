#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// randomly instantiates A, B or C and returns the instance as a Base pointer.
Base* generate(void)
{
	char type = "ABC"[rand() % 3];

	if (type == 'A')
		return (new A);
	else if (type == 'B')
		return (new B);
	else if (type == 'C')
		return (new C);
	return 0;
}

// prints the type of the object, using a ptr and checking if dynamic_cast is NULL;
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "dynamic_cast failed";
}

// prints the type of the object, using a ptr and checking if dynamic_cast throws exception;
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception& exception){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception& exception){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception& exception){}
}

/*  dynamic_casting : convert pointers or references of a base class to 
	pointers or references of a derived class */

int main(void)
{
	int i = 11;

	while(i-- > 0)
	{
		system("clear");
		std::cout << "Random generating bases, " << i << " left...\n\n";
		Base* base = generate();

		identify(base);
		identify(*base);

		sleep(2);
		delete base;
	}
	std::cout << "\nDone\n";
	return (0);
}
