#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T>
void 	print_array(T t)
{
	std::cout <<  t << std::endl;
}

template <typename T, typename U>
void	iter(T* array, int len, void (*func)(U))
{
	int	i = -1;

	while (++i < len)
		func(array[i]);
}

#endif // ITER_HPP
