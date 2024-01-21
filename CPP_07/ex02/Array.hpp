#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <exception>

template <typename T>
class Array 
{
	public:
	// canonical orthodox
	Array();
	~Array();
	Array(Array &original);
	Array &operator=(Array &original);

	// cstm constr;
	Array(unsigned int n);

	// [] overload;
	T &operator[](unsigned int i);

	//functions;
	unsigned int	size();
	T*  getArray();
	

	private:
	T* array;
	unsigned int n;
};

// orthodox canonical
// constructors | destructor
template <typename T>
Array<T>::Array() : array(), n(0){}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), n(n)
{
	unsigned int i = 0;
	while (i < n) 
	{
    	this->array[i] = T();
    	i++;
	}
}

template <typename T>
Array<T>::~Array()
{
	if (this->array)
		delete [] this->array;
}

// copy and assignment
template <typename T>
Array<T>::Array(Array<T>& original) : array(new T[original.n]), n(original.n)
{
	unsigned int i = 0;
	while (i < original.n) 
	{
    	this->array[i] = original.array[i];
    	i++;
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(Array<T>& original)
{
	unsigned int i = 0;
	while (i < original.n) 
	{
    	this->array[i] = original.array[i];
    	i++;
	}
}

// subject functions

// [] op overloading

template <typename T>
T&		Array<T>::operator[](unsigned int i)
{
    if (i >= this->size())
       throw std::out_of_range("Out of bounds position!\n");
    
	return array[i];
}

template <typename T>
unsigned int	Array<T>::size()
{
	return this->n;
}

// returns the array so it can be used for printing;
template <typename T> 
T*  Array<T>::getArray()
{
    return array;
}


#endif // ARRAY_HPP

