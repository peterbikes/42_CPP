#include "../include/Harl.hpp"

#define DEBUG "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
#define INFO "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
#define WARNING "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n"
#define ERROR "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n"


Harl::Harl(){}
Harl::~Harl(){}

void Harl::complain(std::string level)
{
	void (Harl::*harl_functions[4])();
	harl_functions[0] = &Harl::debug;
	harl_functions[1] = &Harl::info;
	harl_functions[2] = &Harl::warning;
	harl_functions[3] = &Harl::error;

	std::string levels[4];
	levels[0] = "DEBUG"; 
	levels[1] = "INFO"; 
	levels[2] = "WARNING"; 
	levels[3] = "ERROR";

	for(int i = 0; i < 4; i++)
		if(level == levels[i])
			(this->*harl_functions[i])();
}

void Harl::debug(){
	std::cout << DEBUG;
}

void Harl::info(){
	std::cout << INFO;
}

void Harl::warning(){
	std::cout << WARNING;
}

void Harl::error(){
	std::cout << ERROR;
}
