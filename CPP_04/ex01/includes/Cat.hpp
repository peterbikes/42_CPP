#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"

class Cat : public Animal 
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
        void brainAddress ();
    protected:
        std::string type;
    private:
        Brain* brain;
};

#endif
