#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;

	public:
		// canonical orthodox
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &original);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &original);

		// special constructor, target defined
		ShrubberyCreationForm(std::string target);
		void execute(const Bureaucrat& executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
