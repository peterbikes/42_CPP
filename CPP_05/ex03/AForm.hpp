#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm 
{
	public:
	// canonical orthodox
	AForm();
	virtual ~AForm();
	AForm(AForm &original);
	AForm &operator=(AForm const &original); // uses copy, as variables are private

	// specific constructor
	AForm(std::string const &name, int signGrade, int executeGrade);

	// Abstract class (=0)
    virtual void  execute(Bureaucrat const & executor) const = 0;

	std::string const getName() const;
	bool getIsSigned() const;
	int getSigningGrade() const;
	int getExecutingGrade() const;
	void beSigned(Bureaucrat &bureaucrat);
	
	// exceptions
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char *what () const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char *what () const throw();
	};

	private:
		std::string const name;
		bool		isFormSigned;
		int const	signingGrade;
		int const	executingGrade;
};

std::ostream &operator<<(std::ostream &out, AForm *form);

#endif // AFORM_HPP
