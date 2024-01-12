#ifndef ROBOTOMYREQUESTFORM_HPP 
#define ROBOTOMYREQUESTFORM_HPP 

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;

	public:
		// canonical orthodox
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm &original);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &original);

		// special constructor, target defined
		RobotomyRequestForm(std::string target);

		void execute(const Bureaucrat& executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP 
