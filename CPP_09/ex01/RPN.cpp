#include "RPN.hpp"
#include <cstdlib>

// canonical orthodox

RPN::RPN()
{
}

RPN::RPN(const RPN& original)
{
	*this = original;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN& original)
{
	if(this == &original)
		return *this;
	return *this;
}


// operations

void RPN::compute(std::string rpn)
{
	std::string numbers = "0123456789";
	std::string operations = "+-*/";

	std::cout << "Expression-> " << rpn << std::endl;

	for (std::string::iterator it = rpn.begin(); it != rpn.end(); ++it)
    {
		int result = 0;
		int A = 0;
		int B = 0;
		// ERROR CONTROL;
        if ((operations.find(*it) < operations.length()) && this->stack_A.size() < 2)
        {
			std::cout << "Bad RPN Expression:" << (*it) << std::endl;
            std::cout << "Not enough elements in stack to preform all operations" << std::endl;
			return ;
        }

		if ((numbers.find(*it) < numbers.length()))
			this->stack_A.push((*it) - '0');
		
		if ((operations.find(*it) < operations.length()) && this->stack_A.size() >= 2)
        {
			B = this->stack_A.top();
			this->stack_A.pop();
			A = this->stack_A.top();
			this->stack_A.pop();
			switch (*it)
        	{
                case '+':
                    result = A + B;
                    break;
                case '-':
                    result = A - B;
                    break;
                case '*':
                    result = A * B;
                    break;
                case '/':
                    result = A / B;
        	}
			std::cout << "Operation -> " << A << " " <<  (*it) << " " << B << " = ";
			this->stack_A.push(result);
			std::cout << this->stack_A.top() << std::endl;
		}
    }
	if(this->stack_A.size() > 1)
		std::cout << "ERROR: There are still elements in stack and no operations to compute them\n";
	else
		std::cout << "Result    -> " << this->stack_A.top() << std::endl;
}

