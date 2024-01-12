#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

// orthodox canonical
AForm::AForm() : name("XYZ"), isFormSigned(false), signingGrade(75), executingGrade(75)
{
}
 
AForm::~AForm()
{
}
 
AForm::AForm(AForm &original) : name(original.getName()), isFormSigned(false), signingGrade(original.getSigningGrade()), executingGrade(original.getExecutingGrade())
{
 	*this = original;
}
 
 // --- > not recommended where values are private, workaround with a const_cast used to override the "constness"
AForm& AForm::operator=(const AForm& original)
{
 	const_cast<std::string&>(this->name) = original.name;
 	const_cast<int&>(this->signingGrade) = original.signingGrade;
 	const_cast<int&>(this->executingGrade) = original.executingGrade;
 	this->isFormSigned = original.isFormSigned;
	return (*this);
}

// custom form constructor ---> const_cast used again, not recommended but necessary here 
AForm::AForm(std::string const &name, int signingGrade, int executingGrade) : name(name), isFormSigned(false), signingGrade(signingGrade), executingGrade(executingGrade)
{
	try{
		if (this->signingGrade < 1 || this->executingGrade < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		if (this->signingGrade > 150 || this->executingGrade > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
	}
	catch(Bureaucrat::GradeTooLowException &except)
	{
		std::cout << "Invalid Grades given, setting both to 75\n" << std::endl;
		const_cast<int&>(this->signingGrade) = 75;
		const_cast<int&>(this->executingGrade) = 75;
	}
	catch(Bureaucrat::GradeTooHighException &except)
	{
		std::cout << "Invalid Grades given, setting both to 75\n" << std::endl;
		const_cast<int&>(this->executingGrade) = 75;
		const_cast<int&>(this->signingGrade) = 75;
	}
}

// Abstract Class

void AForm::execute(Bureaucrat const & executor) const{
	(void)executor;
}

// getters and setters
std::string const AForm::getName() const{return (this->name);}
bool AForm::getIsSigned() const{return (this->isFormSigned);}
int AForm::getSigningGrade() const{return (this->signingGrade);}
int AForm::getExecutingGrade() const{return (this->executingGrade);}

// signing

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSigningGrade())
	{
		std::cout << bureaucrat.getName() << " can't sign this: ";
        throw (AForm::GradeTooLowException());
	}
	if(getIsSigned())
		std::cout << bureaucrat.getName() << " can't sign this, it's already signed\n";
	else
	{	
		std::cout << bureaucrat.getName() << " signed form " << this->getName() << std::endl;
    	this->isFormSigned = true;				
	}
}

// exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("ERROR: Grade is too low!\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("ERROR: Grade is too high!\n");
}

std::ostream &operator<<(std::ostream &out, AForm *form)
{
	std::string signature = "No";
	if(form->getIsSigned())
		signature = "Yes";
	out << "Form      : " << form->getName() << std::endl <<
		   "Signed    : " << signature << std::endl <<
		   "Sign Grade: " << form->getSigningGrade() << std::endl <<
		   "Exec Grade: " << form->getExecutingGrade() << std::endl;
	return (out);
}
