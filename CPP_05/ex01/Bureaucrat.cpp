#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

Bureaucrat::Bureaucrat()
{
	std::cout << "🏗️   Bureaucrat Default Constructor Called\n";
	this->grade = 75;
	this->name = "Unnamed";
}

Bureaucrat::Bureaucrat(Bureaucrat &original)
{
	std::cout << "🏗️   Bureaucrat Copy Constructor Called\n";
	this->name = original.name;
	this->grade = original.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &original)
{
	std::cout << "🏗️   Bureaucrat Assignment Constructor Called\n";
	this->name = original.getName();
	this->grade = original.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	try{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooLowException &except)
    {
        std::cout << "Setting " << name << "'s grade to 75\n";
        this->setGrade(75);
    }
    catch(Bureaucrat::GradeTooHighException &except)
    {
        std::cout << "Setting " << name << "'s grade to 75\n";
        this->setGrade(75);
    }
	std::cout << "🚼  Special Constructor Called --> " << 
	name << " grade " << this->getGrade() << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "💥 Bureaucrat " << this->getName() << " destroyed\n";
}

std::string Bureaucrat::getName()
{
	return this->name;
}

void Bureaucrat::setName(std::string name)
{
	std::cout << getName() << ", your new name is " << name 
		<< "." << std::endl;	
	this->name = name;
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

int Bureaucrat::getGrade()
{
	return this->grade;
}

void Bureaucrat::setGrade(int new_grade)
{
	if(new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = new_grade;
}

void Bureaucrat::decreaseGrade(int new_grade)
{
		std::cout << "Trying to decrement " << this->getName() << "'s grade by "
			<< new_grade << ":" << std::endl;
		this->setGrade(this->grade + new_grade);
}

void Bureaucrat::incrementGrade(int new_grade)
{
		std::cout << "Trying to increment " << this->getName() << "'s grade by "
			<< new_grade << ":" << std::endl;
		this->setGrade(this->grade - new_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grades cannot be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grades cannott be lower than 150");
}

std::ostream &operator <<(std::ostream &out, Bureaucrat *bureaucrat)
{
	out << bureaucrat ->getName() << ", bureaucrat " 
		<< bureaucrat->getGrade() << std::endl;
	return out;
}
