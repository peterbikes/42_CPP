#include <iostream>
#include "Array.hpp"

template <typename T>
void 	print_array(T t)
{
	std::cout << "'" <<  t << "'";
}

template <typename T>
void	iter(T* array, int len, void (*func)(T))
{
	int	i = -1;

	while (++i < len)
		func(array[i]);
}

int main()
{
	std::cout << "1) Empty arrays testing - Ints\n";
    Array<int> test(10);
    iter(test.getArray(), test.size(), print_array<int>);
	std::cout <<"\nArray size: " << test.size() << std::endl;
	
	std::cout << "\n2) Empty arrays testing - Chars\n";
    Array<char> test2(3);
	iter(test2.getArray(), test2.size(), print_array<char>);
	std::cout <<"\nArray size: " << test2.size() << std::endl;
	
	std::cout << "\n3) Int Filled array;\n";

	unsigned int i = 0;
	while(i < test.size())
	{
		test[i] = i;
		i++; 
	}
	
	iter(test.getArray(), test.size(), print_array<int>);
	std::cout <<"\nArray size: " << test.size() << std::endl;

	std::cout << "\n4) String Filled array | '[]' overloading testing;\n";
	Array<std::string> test3(5);
	test3[0] = "hello";
	test3[1] = "my";
	test3[2] = "name";
	test3[3] = "is";
	test3[4] = "bye";
	iter(test3.getArray(), test3.size(), print_array<std::string>);
	std::cout <<"\nArray size: " << test3.size() << std::endl;	
	

	std::cout << "\n5) Trying to access out of bounds pos:\n";
	try{
		std::cout << test3[8];
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}
