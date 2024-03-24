#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	public:
	// canonical orthodox
		RPN();
		~RPN();
		RPN(const RPN& original);
		RPN& operator=(const RPN& original);

	// operations
		void compute(std::string rpn);

	private:
		std::stack<int> stack_A;
};

#endif // RPN_HPP
