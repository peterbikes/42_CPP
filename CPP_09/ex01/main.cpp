#include "RPN.hpp"

bool validate_arg(std::string rpn)
{
    std::string validChars = "+-*/0123456789 ";

    for (std::string::iterator it = rpn.begin(); it != rpn.end(); ++it)
    {
        if (validChars.find(*it) > validChars.length())
        {
            std::cout << "Invalid character: '" << (*it) << "'\n";
			std::cout << "Valid chars are: <space>" << validChars << std::endl;
            return false;
        }
    }
    return true;
}

int main(int ac, char **av)	
{
	if(ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl
			<< "Run me like: $./RPN <expression>\n";
			return 0;
	}
	if(!validate_arg(av[1]))
		return 0;
	RPN rpn;
	rpn.compute(av[1]);
}
