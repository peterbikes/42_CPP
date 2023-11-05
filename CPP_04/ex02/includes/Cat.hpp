#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"

class Cat : public AbstractAnimal 
{
    public:
    // othodox canonical;
        Cat();
		~Cat();
		Cat(Cat &original);
		Cat& operator=(Cat &original);
    //optional constructor
        Cat(std::string type);
    // req functions;
        void makeSound() const;
    protected:
        std::string type;
    private:
        Brain* brain;
};

#endif
