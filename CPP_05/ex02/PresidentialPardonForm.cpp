#include "PresidentialPardonForm.hpp" 
#include <cstdlib>
#include <iostream>

// orthodox canonical
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("undefined_target")
{
	std::cout << "🤴 PresidentialPardonForm Created;\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "🔥 PresidentialPardonForm Destroyed;\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& original)
	: AForm(original.getName(), original.getSigningGrade(), original.getExecutingGrade()), target(original.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
	const_cast<std::string&>(this->target) = original.target;
	return (*this);
}

// special constructor, with target:
PresidentialPardonForm::PresidentialPardonForm(std::string target)    
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{    
    std::cout << "🤴 PresidentialPardonForm Created - target: " << target << std::endl;    
} 

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecutingGrade())
		throw (AForm::GradeTooLowException());
	else if (this->getIsSigned())
		std::cout << this->target
				  << " has been pardoned by Zaphod Beeblebrox.\n";
}
