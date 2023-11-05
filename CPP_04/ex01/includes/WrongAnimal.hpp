#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

// the same as animal, but the virtual keyword is missing

class WrongAnimal {
    public:
    // othodox canonical;
        WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal &original);
		WrongAnimal& operator=(WrongAnimal &original);
    //optional constructor
    // req functions;
        void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
    private:
        WrongAnimal(std::string type);
};

#endif
