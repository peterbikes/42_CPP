#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

class WrongCat : public WrongAnimal 
{
    public:
    // othodox canonical;
        WrongCat();
		~WrongCat();
		WrongCat(WrongCat &original);
		WrongCat& operator=(WrongCat &original);
    //optional constructor
        WrongCat(std::string type);
    // req functions;
        void makeSound() const;
    protected:
        std::string type;
};

#endif
