#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	public:
	// canonical orthodox
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& original);
		PmergeMe& operator=(const PmergeMe& original);

	// operations
		void merge_me_vec(char **av);
		void merge_me_deq(char **av);

	// helpers
		void step_by_step_helper(char **av);
		void print_stacks();
		template<typename T>
		bool is_sorted(const T& container);
		int next_jacob(int jacob);
		void small_sort_vec();
		void small_sort_deq();
	
	private:
		std::vector<int> stack_A;
		std::vector<int> stack_B;
		std::deque<int> stack_C;
		std::deque<int> stack_D;
};

#endif // PMERGEME_HPP

/*
 * from https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort:
 *
 * 1 - Determine if the array is even or odd numbered in length. If odd, remove the last number, designate it as a ‘straggler’ and insert it later into the sorted array.
 * 2 - Arbitrarily divide the sequence to sort into pairs of two values.
 * 3 - Sort the pairs bitwise, so the order is always [less, greater].
 * 4 - Sort the sequence recursively by the value of it’s largest pair.
 * 5 - Create a new sequence ‘S’, by pulling out the [highest] value of each pair and inserting it into ‘S’.
 * 6 - The remaining values form a temporary ‘pend’ array.
 * 7 - Based on the length of ‘pend’, build the optimal insertion sequence using relevant Jacobsthal numbers.
 * 8 - Loop through the elements in ‘pend’, and using the insertion sequence built in the previous step, use binary search to insert each ‘pend’ element into ‘S’.
 * 9 - If a ‘straggler’ was found, do a leftover loop and insertion to complete the list.
 
 * ALSO:
 * https://www.figma.com/file/JW5jFeoD6fbSnu2K2XXfKV/Ford-Johnson-(merge-insertion-sort)-algorithm?type=whiteboard&node-id=0-1
 * On the Average Case of MergeInsertion
 * https://arxiv.org/pdf/1905.09656.pdf
 * https://www.youtube.com/watch?v=wqibJMG42Ik
 * https://link.springer.com/article/10.1007/s00224-020-09987-4
 */

