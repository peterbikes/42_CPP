#ifndef ABSTRACTANIMAL_HPP
#define ABSTRACTANIMAL_HPP

// https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

/* Sometimes implementation of all functions cannot be provided in a base class because we don’t know the implementation. Such a class is called an abstract class.For example, let Shape be a base class. We cannot provide the implementation of function draw() in Shape, but we know every derived class must have an implementation of draw(). Similarly, an AbstractAnimal class doesn’t have the implementation of move() (assuming that all animals move), but all animals must know how to move. We cannot create objects of abstract classes. */


#include <string>

class AbstractAnimal {
    public:
    // othodox canonical;
        AbstractAnimal();
		virtual ~AbstractAnimal();
		AbstractAnimal(AbstractAnimal &original);
		AbstractAnimal& operator=(AbstractAnimal &original);
    //optional constructor
        virtual void makeSound() const = 0;
    // req functions;
        std::string getType() const;
    protected:
        std::string type;
    private:
        AbstractAnimal(std::string type);
};

#endif
