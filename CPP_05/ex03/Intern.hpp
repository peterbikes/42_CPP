#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp" 
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern 
{
	public:
	// canonical orthodox
	Intern();
	~Intern();
	Intern(Intern &original);
	Intern& operator=(Intern &original);

	AForm *makeForm(std::string form_type, std::string target);
};

#endif // INTERN_HPP
