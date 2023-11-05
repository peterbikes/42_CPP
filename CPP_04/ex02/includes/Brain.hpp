#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
    public:
    // othodox canonical;
        Brain();
		virtual ~Brain();
		Brain(Brain &original);
		Brain& operator=(Brain &original);
    protected:
        std::string ideas[100];
};

#endif
