#include "Form.hpp"
#include <cstdlib>
#include <iostream>

// orthodox canonical
Form::Form() : name("XYZ"), isFormSigned(false), signingGrade(75), executingGrade(75)
{
	std::cout << "Reg XYZ form created, not signed, sign and exec grade 75\n";
}

Form::~Form()
{
	std::cout << "🗑️  Form " << this->name << " destroyed!" << std::endl;
}

Form::Form(Form &original) : name(original.getName()), isFormSigned(false), signingGrade(original.getSigningGrade()), executingGrade(original.getExecutingGrade())
{
	*this = original;
}

// --- > not recommended where values are private, workaround with a const_cast used to override the "constness"
Form& Form::operator=(const Form& original)
{
	const_cast<std::string&>(this->name) = original.name;
	const_cast<int&>(this->signingGrade) = original.signingGrade;
	const_cast<int&>(this->executingGrade) = original.executingGrade;
	this->isFormSigned = original.isFormSigned;
	return (*this);
}

// custom form constructor ---> const_cast used again, not recommended but necessary here 
Form::Form(std::string const &name, int signingGrade, int executingGrade) : name(name), isFormSigned(false), signingGrade(signingGrade), executingGrade(executingGrade)
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
	std::cout << "NEW FORM CREATED:\n" << this << std::endl;
}

// getters and setters
std::string const Form::getName() const{return (this->name);}
bool Form::getIsSigned() {return (this->isFormSigned);}
int Form::getSigningGrade() const{return (this->signingGrade);}
int Form::getExecutingGrade() const{return (this->executingGrade);}


// WTF

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSigningGrade())
	{
		std::cout << bureaucrat.getName() << " can't sign this: ";
        throw (Form::GradeTooLowException());
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
const char *Form::GradeTooHighException::what() const throw()
{
	return ("ERROR: Grade is too low!\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("ERROR: Grade is too high!\n");
}

std::ostream &operator<<(std::ostream &out, Form *form)
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
