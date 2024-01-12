#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form 
{
	public:
	// canonical orthodox
	Form();
	~Form();
	Form(Form &original);
	Form &operator=(Form const &original); // uses copy, as variables are private

	// specific constructor
	Form(std::string const &name, int signGrade, int executeGrade);

	std::string const getName() const;
	bool getIsSigned();
	int getSigningGrade() const;
	int getExecutingGrade() const;
	void beSigned(Bureaucrat &bureaucrat);
	
	// exceptions
	class GradeTooHighException: public std::exception
	{
		public:
			const char *what () const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
		public:
			const char *what () const throw();
	};

	private:
		std::string const name;
		bool		isFormSigned;
		int const	signingGrade;
		int const	executingGrade;
};

std::ostream &operator<<(std::ostream &out, Form *form);

#endif // FORM_HPP
