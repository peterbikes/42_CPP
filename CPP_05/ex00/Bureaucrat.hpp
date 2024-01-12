#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat 
{
	public:
	// canonical orthodox
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(Bureaucrat &original);
	Bureaucrat& operator=(Bureaucrat &original);

	Bureaucrat(std::string name, int grade);
	std::string getName();
	int getGrade();
	void setGrade(int new_grade);
	void setName(std::string name);
	void incrementGrade(int new_grade);
	void decreaseGrade(int new_grade);
	
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
	std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat *bureaucrat);

#endif // BUREAUCRAT_HPP
