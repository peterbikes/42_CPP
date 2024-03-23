#include "easyFind.hpp"
#include <vector>

int main()
{
	{
	std::cout << "1) creating int vector:\n"; 
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);


	std::cout << "Array contains: ";
 	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Searching for 13:\n";
	try{
		easyFind(vec, 13);
	}
	catch (std::exception &exce)
	{
		std::cout << exce.what();
	}
	}

	{
	std::cout << "\n2) creating char vector:\n"; 
	std::vector<int> vec;

	vec.push_back(60);
	vec.push_back(70);
	vec.push_back(80);
	vec.push_back(90);
	vec.push_back(100);


	std::cout << "Array contains: ";
 	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Searching for 80:\n";
	try{
		easyFind(vec, 100);
	}
	catch (std::exception &exce)
	{
		std::cout << exce.what();
	}
	}

}
