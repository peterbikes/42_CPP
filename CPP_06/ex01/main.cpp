#include "Serializer.hpp"
#include <cstdlib>

int main ()
{
	system("clear");
	Data data = {23, 'a'};
	uintptr_t	raw = Serializer::serialize(&data);

	std::cout << "<--- Data structure created --->\n\n";
	std::cout << "Data members: int: " << data.i  << "; char: " << data.c << std::endl;

	std::cout << "\n1) Serialized:" << std::endl;
	std::cout << "Raw  (uintptr_t)   : " << raw << std::endl;
	std::cout << "Data Adress (raw)  : " << &raw << std::endl;

	std::cout << "\n<--- Creating other data ptr and accessing info on raw --->\n\n";

	Data *other = Serializer::deserialize(raw);

	std::cout << "2) DeSerialized:" << std::endl;
	std::cout << "Data Adress (&data): " << &data << std::endl;
	std::cout << "Data Adress (other): " << other << std::endl;
	std::cout << "Data members       : int: " << other->i  << "; char: " << other->c << std::endl;

}
