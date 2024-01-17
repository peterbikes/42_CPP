#include "Serializer.hpp"
#include <iostream>
#include <string>

// orthodox canonical

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer &original)
{
	(void)original;
	//return (*original);
}

Serializer &Serializer::operator=(Serializer &original)
{
	(void)original;
	return *this;
}

Serializer::~Serializer()
{
}

// req functions
/* reinterpret_cast used for casting pointers to other 
 pointer or integral types; */

uintptr_t 	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}