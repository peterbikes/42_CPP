#include <iostream>

//ptr work just like in C -> A pointer is a variable that holds the memory address of another variable.

// references are a little diferent -> A reference is an alias or another name for an existing variable.

int main ()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;

	std::cout << "First part:\n"	
	<< "Memory address of string: " << &str	
	<< "\nMemory address of string pointer: "<< str_ptr
	<< "\nMemory address of string ref: " << &str_ref << std::endl;

	std::cout << "\nSecond part:\n"	
	<< "Value of string: " << str	
	<< "\nValue pointed by string pointer: "<< *str_ptr
	<< "\nValue pointed by string ref: " << str_ref << std::endl;

}

/*When to use Pointers or References:

Use pointers when you need the flexibility of pointing to different variables or dynamically allocated memory.

Use references when you want a simpler syntax for accessing variables and when you want to pass variables to functions by reference to modify their values directly.*/
