#include "PmergeMe.hpp"

// https://www.calculatorsoup.com/calculators/statistics/number-generator.php

int main(int ac, char **av)	
{
    std::cout.precision(2);
	if(ac < 2)
	{
		std::cout << "Wrong number of arguments" << std::endl
			<< "Run me like: $./PmergeMe #1 #2 #3...\n";
			return 0;
	}

	PmergeMe merge;

    {
    // Using std::vector :
 
    clock_t startTime = clock();
    merge.merge_me_vec(av);
    clock_t endTime = clock();

    double duration = double(endTime - startTime) / double(CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << ac - 1 << 
    " elements with std::vector: " << std::fixed << duration << " us" << std::endl;
    }
    
    {
    // Using std::deque :
 
    clock_t startTime = clock();
    merge.merge_me_deq(av);
    clock_t endTime = clock();

    double duration = double(endTime - startTime) / double(CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << ac - 1 << 
    " elements with std::deque : " << std::fixed << duration << " us" << std::endl;
    }

    return 0;	
}

