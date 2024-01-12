#include "ShrubberyCreationForm.hpp" 
#include <fstream>
#include <cstdlib>
#include <iostream>

// orthodox canonical
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("undefined_target")
{
	std::cout << "🌴 ShrubberyCreationForm Created;\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "🔥 ShrubberyCreationForm Destroyed;\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& original)
	: AForm(original.getName(), original.getSigningGrade(), original.getExecutingGrade()), target(original.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
	const_cast<std::string&>(this->target) = original.target;
	return (*this);
}

// special constructor, with target:
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)    
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{    
    std::cout << "🌴 ShrubberyCreationForm Created - target: " << target << std::endl;    
} 

// execute

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecutingGrade())
		throw (AForm::GradeTooLowException());
	else if (this->getIsSigned())
	{
		std::string file = this->target + "_shrubbery";
		std::fstream fs;

		fs.open(file.c_str(), std::fstream::out | std::fstream::trunc);
		if (fs.is_open())
		{
			fs << "              * *\n"
				  "           *    *  *\n"
				  "      *  *    *     *  *\n"
				  "    *    *  *    *\n"
				  "* *   *    *    *    *   *\n"
				  "*     *  *    * * .#  *   *\n"
				  "*   *     * #.  .# *   *\n"
				  " *     #.  #: # * *    *\n"
				  "  *   * * #. ##       *\n"
				  "   *       ###\n"
                  "            ##\n"
                  "              ##.\n"
                  "              .##:\n"
                  "              :###\n"
                  "              ;###\n"
                  "            ,####.\n";
			fs.close();
		}
	}
}
