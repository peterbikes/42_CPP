#include "./includes/animals.hpp"

int main()
{
	Animal* zoo[10];

	for(int i = 0; i < 5; i++)
		zoo[i] = new Cat();

	for(int i = 5; i < 10; i++)
		zoo[i] = new Dog();

	for(int i = 0; i < 10; i++)
		delete zoo[i];

	std::cout << "\n\n<-- subject suggested main -->\n\n" << std::endl;

	// subject suggested main

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n\n<-- Deep Copy Check -->\n\n" << std::endl;

	Cat Andrew;
	Dog Philip;

	Cat Andrew_assigned;
	Dog Philip_assigned;

	Andrew_assigned = Andrew;
	Philip_assigned = Philip;

	Cat Andrew_copy_construct(Andrew);
	Dog Philip_copy_construct(Philip);

	std::cout << "\n\n<-- Deep Copy Check -->\n\n" << std::endl;

	std::cout << "Andrew's original address: ";
	Andrew.brainAddress();
	std::cout << "Philip's original address: ";
	Philip.brainAddress();

	std::cout << "Andrew's copied address: ";
	Andrew_assigned.brainAddress();
	std::cout << "Philip's copied address: ";
	Philip_assigned.brainAddress();

	std::cout << "Andrew's copy constructed address: ";
	Andrew_copy_construct.brainAddress();
	std::cout << "Philip's copy constructed address: ";
	Philip_copy_construct.brainAddress();

	std::cout << "\n\n";

}
