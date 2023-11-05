#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
    public:
    // othodox canonical;
        Animal();
		virtual ~Animal();
		Animal(Animal &original);
		Animal& operator=(Animal &original);
    //optional constructor
    // req functions;
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
    private:
        Animal(std::string type);
};

#endif
