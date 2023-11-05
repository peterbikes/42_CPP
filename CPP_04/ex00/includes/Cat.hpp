#ifndef CAT_HPP
#define CAT_HPP

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
};

#endif
