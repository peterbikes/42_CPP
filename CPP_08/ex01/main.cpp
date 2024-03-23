#include "Span.hpp"
#include <exception>

int main()
{
	{
	std::cout << "1) Creating Span that fits a million ints\n";
	Span lst(1000000);

	std::cout << "2) Filling it with random numbers until it can't take no more\n";
	while(1)
	{
		try{
		lst.addHundredRandNumbers();
		}
		catch(std::exception &except)
		{
			std::cout << except.what();
			break ;
		}
	}
	std::cout << "3) Testing shortestSpan\n";
	try{
		std::cout << lst.shortestSpan();
		}
		catch(std::exception &except)
		{
			std::cout << except.what();
		}
	std::cout << std::endl;

	std::cout << "4) Testing longestSpan\n";
	try{
		std::cout << lst.longestSpan();
		}
		catch(std::exception &except)
		{
			std::cout << except.what();
		}
	std::cout << std::endl;
	}

	{
	std::cout << "4) Creating Span that fits a 10 ints\n";
	Span lst(10);

	std::cout << "5) Filling it with 1 - 10 numbers until it can't take no more\n";
	int i = 1;
	while(1)
	{
		try{
		lst.addNumber(i);
		}
		catch(std::exception &except)
		{
			std::cout << except.what();
			break ;
		}
		i++;
	}
	std::cout << "6) Testing shortestSpan\n";
	try{
		std::cout << lst.shortestSpan();
		}
		catch(std::exception &except)
		{
			std::cout << except.what();
		}
	std::cout << std::endl;

	std::cout << "7) Testing longestSpan\n";

	try{
		std::cout << lst.longestSpan();
		}
		catch(std::exception &except)
		{
			std::cout << except.what();
		}
	std::cout << std::endl;
	}

	{
	std::cout << "8) Subject suggested tests\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}

	{
	std::cout << "9) Copy | assignment testing\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	Span sp1(sp);
	Span sp2;
	sp2 = sp;

	std::cout << "- Original SP:\n";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "- Copied SP:\n";
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	std::cout << "- =ed SP:\n";
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return 0;
	}
}
