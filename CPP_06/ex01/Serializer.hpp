#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct	s_Data
{
	int 			i;
	char 			c;

}	Data;

class Serializer
{
	private:
	// orthodox canonical
		Serializer();
		~Serializer();
		Serializer(Serializer &original);
		Serializer& operator=(Serializer &original);

	public:
		// takes ptr and converts it to uintptr_t ;
		static uintptr_t 	serialize(Data *ptr);
		// takes uintptr_t and converts it to ptr to Data ;
		static Data* 		deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
