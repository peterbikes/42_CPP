#include "iter.hpp"
#include <iostream>

int main()
{
	int 		array1[5] = {0, 12, 99, -4, 35};
	char 		array2[4] = {'q', 'w', 'e', 'r'};
	std::string array3[3] = {"my", "name", "is"};
	
	std::cout << "1st Array - Ints: \n";
	iter<int, int>(array1, 5, print_array);
	std::cout << std::endl;

	std::cout << "2nd Array - Chars: \n";
	iter<char, char>(array2, 4, print_array);
	std::cout << std::endl;

	std::cout << "3rd Array - Strings: \n";
	iter<std::string, std::string>(array3, 3, print_array);
	std::cout << std::endl;
}
