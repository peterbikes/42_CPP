#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <exception>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Span 
{
	public:
	// canonical orthodox
		Span();
		~Span();
		Span(const Span &original);
		Span& operator=(Span &original);

	//special constructor
		Span(unsigned int N);

	// subj functions
		void	addNumber		(int i);
		int		shortestSpan	();
		int		longestSpan		();

	// extra
		void	addHundredRandNumbers();
	
	private:
		std::vector<int>	vec;
		unsigned int		N;

};

#endif // SPAN_HPP
