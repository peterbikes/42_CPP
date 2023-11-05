#include "./includes/animals.hpp"

int main()
{
	AbstractAnimal* zoo[10];

	for(int i = 0; i < 5; i++)
		zoo[i] = new Cat();

	for(int i = 5; i < 10; i++)
		zoo[i] = new Dog();

	for(int i = 0; i < 10; i++)
		delete zoo[i];

	std::cout << "\n\n<-- subject suggested main -->\n\n" << std::endl;


	// subject suggested main

	const AbstractAnimal* j = new Dog();
	const AbstractAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	// UNCOMMENT BELOW TO EXPERIENCE TRUE ABSTRACTION (CODE WILL NOT COMPLILE)
	// AbstractAnimal Carlos;


	return 0;

}
