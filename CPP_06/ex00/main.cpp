#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

// inff and -inff : 3.5e+38
// inf and - inf : 3.5e+38

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number or arguments!\nUse like: $./convert <to_convert>\n";
        return (0);
    }
    ScalarConverter::convert(av[1]);
}
