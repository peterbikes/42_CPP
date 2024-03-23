#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
void	easyFind(T& container, int value)
{
	typename T::iterator element;
	
	element = std::find(container.begin(), container.end(), value);
	
	if (element != container.end())
	{
		std::cout << "element found in container\n";
		return ;
	}
	else
		throw std::invalid_argument("element not in container\n");
}

#endif // EASYFIND_HPP
