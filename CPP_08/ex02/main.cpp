#include "MutantStack.hpp"

template<typename T>
void print_values(typename T::iterator start, typename T::iterator end)
{
    typename T::iterator it = start;
	while(it != end)
	{
		std::cout << *it << " ";
        ++it;
	}
	std::cout << std::endl;
}

template<typename T, typename value>
bool find_value(typename T::iterator start, typename T::iterator end, value val)
{
    for (typename T::iterator it = start; it != end; ++it)
    {
        if (*it == val)
            return true;
    }
    return false;
}

int main() {

    // copy | assignment
    std::cout << "1) Mutant Stack Creation with 0 to 30 ints;\n\n";
    std::cout << "2) Displaying contents:\n";
    MutantStack<int> Mutant;

    for(int i=0; i<=30; i++)
        Mutant.push(i);

    MutantStack<int> Mutant2(Mutant);
    MutantStack<int> Mutant4(Mutant);
    MutantStack<int> Mutant3;
    Mutant3 = Mutant;

    while (!Mutant.empty()) {
        std::cout << Mutant.top() << " ";
        Mutant.pop();
    }

    std::cout << "\n\n3) Copy Testing;\n";
    while (!Mutant2.empty()) {
        std::cout << Mutant2.top() << " ";
        Mutant2.pop();
    }

    std::cout << "\n\n4) Assignment Testing;\n";
    while (!Mutant3.empty()) {
        std::cout << Mutant3.top() << " ";
        Mutant3.pop();
    }

    std::cout << "\n\n5) Printing but this time using iterators;\n";

        print_values<MutantStack<int> >(Mutant4.begin(), Mutant4.end());

    std::cout << "\n6) Using iterator to check if value is in stack;\n\n";
    std::cout << "---> value in stack (15)\n";

    if(find_value<MutantStack<int> >(Mutant4.begin(), Mutant4.end(), 15))
        std::cout << "Value in Stack\n";
    else
        std::cout << "Value not in Stack\n";

    std::cout << "---> value not in stack (40)\n";

    if(find_value<MutantStack<int> >(Mutant4.begin(), Mutant4.end(), 40))
        std::cout << "Value in Stack\n";
    else
        std::cout << "Value not in Stack\n";

    {
    std::cout << "\n\n7) Subject suggested tests;\n\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
    }

}

