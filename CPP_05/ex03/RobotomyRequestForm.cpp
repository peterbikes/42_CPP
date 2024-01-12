#include "RobotomyRequestForm.hpp" 
#include <cstdlib>
#include <iostream>

// orthodox canonical
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("undefined_target")
{
	std::cout << "🤖 RobotomyRequestForm Created;\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "🔥 RobotomyRequestForm Destroyed;\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& original)
	: AForm(original.getName(), original.getSigningGrade(), original.getExecutingGrade()), target(original.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
	const_cast<std::string&>(this->target) = original.target;
	return (*this);
}

// special constructor, with target:
RobotomyRequestForm::RobotomyRequestForm(std::string target)    
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{    
    std::cout << "🤖 RobotomyRequestForm Created - target: " << target << std::endl;    
} 

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecutingGrade())
		throw (AForm::GradeTooLowException());
	else if (this->getIsSigned())
	{
		std::cout << "🪛 * making drilling noises *\n";
		int success = rand() % 2;
		if (success == 1)
			std::cout << "✅ " << this->target << " had been robotomized\n";
		else
			std::cout << "❌ " << this->target << "'s robotomy failed\n";
	}
}
