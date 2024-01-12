#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat 
{
	public:
	// canonical orthodox
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(Bureaucrat &original);
	Bureaucrat& operator=(Bureaucrat &original);

	Bureaucrat(std::string name, int grade);
	std::string getName () const;
	int getGrade() const;
	void setGrade(int new_grade);
	void setName(std::string name);
	void incrementGrade(int new_grade);
	void decreaseGrade(int new_grade);

	void signForm(AForm &form);	
	void executeForm(const AForm& form);	

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
	std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat *bureaucrat);

#endif // BUREAUCRAT_HPP
