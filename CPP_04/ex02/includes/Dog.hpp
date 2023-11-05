#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"

class Dog : public AbstractAnimal 
{
    public:
    // othodox canonical;
        Dog();
		~Dog();
		Dog(Dog &original);
		Dog& operator=(Dog &original);
    //optional constructor
        Dog(std::string type);
    // req functions;
        void makeSound() const;
    protected:
        std::string type;
    private:
        Brain* brain;
};

#endif
