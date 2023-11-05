#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal 
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
};

#endif
