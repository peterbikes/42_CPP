#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target;

	public:
		// canonical orthodox
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &original);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &original);

		// special constructor, target defined
		PresidentialPardonForm(std::string target);

		void execute(const Bureaucrat& executor) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP
