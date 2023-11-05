#include "./includes/animals.hpp"

int main()
{
	// main included in subject
	std::cout << "TESTS FIRST PART\n\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n\nTESTS SECOND PART\n\n";
	const WrongAnimal* second_meta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); //will NOT output the cat sound!
	second_meta->makeSound();

	WrongCat Andrew;
	Andrew.makeSound();

	delete second_meta;
	delete k;

	return 0;
}
