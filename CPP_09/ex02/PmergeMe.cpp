#include "PmergeMe.hpp"
#include <cstdlib>

// canonical orthodox

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& original)
{
	*this = original;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe& original)
{
	if(this == &original)
		return *this;
	return *this;
}

// helpers

void PmergeMe::print_stacks()
{
	//std::cout << "\nSTACK A: ";

	for (size_t i = 0; i < stack_A.size(); ++i) 
	{
        std::cout << stack_A[i] << " ";
	}

	/* std::cout << "\nSTACK B: ";
	
	for (size_t i = 0; i < stack_B.size(); ++i) 
	{
        std::cout << stack_B[i] << " | ";
	}
	if(this->stack_B.size() > this->stack_A.size())
		std::cout << " -> (stragler)" << std::endl; 
	std::cout << std::endl; */
}

template<typename T>
bool PmergeMe::is_sorted(const T& container)
{
    for (typename T::size_type i = 1; i < container.size(); ++i)
    {
        if (container[i] < container[i - 1])
        {
            return false;
        }
    }
    return true;
}

void PmergeMe::small_sort_vec()
{
    int n = this->stack_A.size();
    while (!is_sorted(this->stack_A)) 
	{
        for (int i = 1; i < n; ++i) {
            if (this->stack_A[i - 1] > this->stack_A[i])
                std::swap(this->stack_A[i - 1], this->stack_A[i]);
        }
        --n;
    }
}

void PmergeMe::small_sort_deq()
{
    int n = this->stack_C.size();
    while (!is_sorted(this->stack_C)) 
	{
        for (int i = 1; i < n; ++i) {
            if (this->stack_C[i - 1] > this->stack_C[i])
                std::swap(this->stack_C[i - 1], this->stack_C[i]);
        }
        --n;
    }
}

int PmergeMe::next_jacob(int jacob) 
{
    if (jacob == 0) {
        return 1;
    }
    if (jacob == 1) {
        return 3;
    }
    int prev = 1;
    int i = 3;
    int swap = 0;
    while (i <= jacob) {
        swap = i;
        i = i + (2 * prev);
        prev = swap;
    }
    return i;
}

void PmergeMe::step_by_step_helper(char **av)
{

	std::cout << "< -- PART I: Stack Division -- >\n\n";
	std::cout << "Arguments passed:\n";
	for(int i = 1; av[i]; i++)
	{
		std::cout << av[i] << " - ";
		for(int k = 0; av[i][k]; k++)
			if(!isdigit(av[i][k]))
			{
				std::cout << "This argument is not valid: " 
				<< "'" << av[i][k] << "'" << std::endl;
				return ;
			}
		
		if(i % 2 != 0)
			this->stack_B.push_back(std::atoi(av[i]));
		else
			this->stack_A.push_back(std::atoi(av[i]));
	}

	std::cout << std::endl;
	std::cout << "STACK A has " << this->stack_A.size() << " elements." << std::endl;
	std::cout << "STACK B has " << this->stack_B.size() << " elements." << std::endl;

	std::cout << "\n< -- PART II: Pair Comparison-- >\n\n";

    std::cout << "Pairs:" << std::endl;

	this->print_stacks();

	std::cout << "\n\n< -- PART III: Pair Swapping -- >\n\n";

	for (size_t i = 0; i < stack_A.size(); ++i) 
	{
		int swap = stack_A[i];
		if(stack_A[i] < stack_B[i])
		{
			stack_A[i] = stack_B[i];
			stack_B[i] = swap;
			i = 0;
		}
	}

	this->print_stacks();


	std::cout << "\n\n< -- PART IV: Recursive organization -- >\n\n";

	for (size_t i = stack_A.size() - 1; i > 0; --i) 
	{
		int swap_a = stack_A[i];
		int swap_b = stack_B[i];
		if(stack_A[i - 1] > stack_A[i])
		{

			stack_A[i] = stack_A[i - 1];
            stack_A[i - 1] = swap_a;
			stack_B[i] = stack_B[i - 1];
            stack_B[i - 1] = swap_b;
			i = stack_A.size();
		}
	}

		this->print_stacks();

	std::cout << "\n\n< -- PART IV: Final Sort -- >\n\n";

	unsigned long jacob = 1;

	std::cout << "Before pushing first element" << std::endl;
	this->print_stacks();

	int element = stack_B.front(); // Get the first element of stack B
    stack_B.erase(stack_B.begin()); // Remove the first element from stack B
    stack_A.insert(stack_A.begin(), element); // Insert the element at the beginning of stack A

	std::cout << "After pushing first element" << std::endl;

	this->print_stacks();
	std::cout << std::endl;

	long int control;
	while (!is_sorted(this->stack_A) || !this->stack_B.empty()) 
	{
    std::cout << "Current Jacob:" << jacob << std::endl;
    if (stack_B.size() > jacob) {
        control = jacob;
    } else {
        control = stack_B.size() - 1;
    }
    while (control >= 0) {
        int element = this->stack_B[control];
        stack_A.insert(stack_A.begin(), element);
        stack_B.erase(stack_B.begin() + control); // Remove the element from stack_B
		small_sort_vec();
        control--;
    }
    this->print_stacks();
    jacob = next_jacob(jacob);
	}
}

	// operations

void PmergeMe::merge_me_vec(char **av)
{

	// Stack Division

	for(int i = 1; av[i]; i++)
	{
		for(int k = 0; av[i][k]; k++)
			if(!isdigit(av[i][k]))
			{
				std::cout << "This argument is not valid: " 
				<< "'" << av[i][k] << "'" << std::endl;
				return ;
			}
		if(i % 2 != 0)
			this->stack_B.push_back(std::atoi(av[i]));
		else
			this->stack_A.push_back(std::atoi(av[i]));
	}

	// Pair Swapping

	for (size_t i = 0; i < stack_A.size(); ++i) 
	{
		int swap = stack_A[i];
		if(stack_A[i] < stack_B[i])
		{
			stack_A[i] = stack_B[i];
			stack_B[i] = swap;
			i = 0;
		}
	}

	// Recursive organization

	for (size_t i = stack_A.size() - 1; i > 0; --i) 
	{
		int swap_a = stack_A[i];
		int swap_b = stack_B[i];
		if(stack_A[i - 1] > stack_A[i])
		{

			stack_A[i] = stack_A[i - 1];
            stack_A[i - 1] = swap_a;
			stack_B[i] = stack_B[i - 1];
            stack_B[i - 1] = swap_b;
			i = stack_A.size();
		}
	}

	// Final Sort

	unsigned long jacob = 1;
	long int control;
	int element = stack_B.front();

    stack_B.erase(stack_B.begin());
    stack_A.insert(stack_A.begin(), element);

	while (!is_sorted(this->stack_A) || !this->stack_B.empty()) 
	{
    if (stack_B.size() > jacob)
        control = jacob;
    else
        control = stack_B.size() - 1;
    while (control >= 0) 
	{
        int element = this->stack_B[control];
        stack_A.insert(stack_A.begin(), element);
        stack_B.erase(stack_B.begin() + control); // Remove the element from stack_B
		small_sort_vec();
        control--;
    }
    jacob = next_jacob(jacob);
	}
	int i = 0;
	std::cout << "Before: ";
	while(av[++i])
		std::cout << av[i] << " ";

	std::cout << std::endl;
	std::cout << "After : ";
	this->print_stacks();
	std::cout << std::endl;
}

void PmergeMe::merge_me_deq(char **av)
{

	// Stack Division

	for(int i = 1; av[i]; i++)
	{
		for(int k = 0; av[i][k]; k++)
			if(!isdigit(av[i][k]))
			{
				std::cout << "This argument is not valid: " 
				<< "'" << av[i][k] << "'" << std::endl;
				return ;
			}
		if(i % 2 != 0)
			this->stack_D.push_back(std::atoi(av[i]));
		else
			this->stack_C.push_back(std::atoi(av[i]));
	}

	// Pair Swapping

	for (size_t i = 0; i < stack_C.size(); ++i) 
	{
		int swap = stack_C[i];
		if(stack_C[i] < stack_D[i])
		{
			stack_C[i] = stack_D[i];
			stack_D[i] = swap;
			i = 0;
		}
	}

	// Recursive organization

	for (size_t i = stack_C.size() - 1; i > 0; --i) 
	{
		int swap_a = stack_C[i];
		int swap_b = stack_D[i];
		if(stack_C[i - 1] > stack_C[i])
		{

			stack_C[i] = stack_C[i - 1];
            stack_C[i - 1] = swap_a;
			stack_D[i] = stack_D[i - 1];
            stack_D[i - 1] = swap_b;
			i = stack_C.size();
		}
	}

	// Final Sort

	unsigned long jacob = 1;
	long int control;
	int element = stack_D.front();

    stack_D.erase(stack_D.begin());
    stack_C.insert(stack_C.begin(), element);

	while (!this->stack_D.empty()) 
	{
    if (stack_D.size() > jacob)
        control = jacob;
    else
        control = stack_D.size() - 1;
    while (control >= 0) 
	{
        int element = this->stack_D[control];
        stack_C.insert(stack_C.begin(), element);
        stack_D.erase(stack_D.begin() + control); // Remove the element from stack_D
		small_sort_deq();
        control--;
    }
    jacob = next_jacob(jacob);
	}
}

