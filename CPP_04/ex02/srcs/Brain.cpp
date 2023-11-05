#include "../includes/animals.hpp"

// othodox canonical;
Brain::Brain()
{
	std::cout << "🔨🧠 -> brain constructor called" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = "💡";
}

Brain::~Brain()
{
	std::cout << "💥🧠 -> brain destructor called\n";
}

Brain::Brain(Brain &original)
{
	std::cout << "Brain Copy Constructor called\n";
    *this = original;
}

Brain& Brain::operator=(Brain &original)
{
	std::cout << "Brain assignment operator called\n";
    for(int i = 0; i < 100; i++)
        this->ideas[i] = original.ideas[i];
    return *this;
}
