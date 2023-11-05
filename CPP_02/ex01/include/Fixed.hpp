#ifndef FIXED_HPP 
#define FIXED_HPP

#include <ostream>

class Fixed
{
		static const int _bits = 8;
	public:
		int	_fixed_point;
		// constructor
		Fixed();
		// destructor
		~Fixed();
		// copy constructor -> initialized objects from variables of other object;
		Fixed(Fixed const &original);
		// op overload -> user defined operator behaviour;
		Fixed& operator=(Fixed const &original);
		// subj functions && subj constructors;
		Fixed(const int);	
		Fixed(const float);

		float toFloat() const;
		int toInt() const;
};

// op insertion -> has to be outside of object, because the order of the arguments is different than all the others
std::ostream &operator<<(std::ostream &stream, const Fixed &number);

#endif

/*
FIXED POINT REP OF A NUMBER INSTRCUTIONS:

 a) Multiply the floating-point number by 2^how-many-bits-you-got;
 
 b) Round to the nearest integer if needed;

 c) Split the binary representation into 4 bits for the integer part and 4 bits for the fractional part. The integer part is the leftmost 4 bits, and the fractional part is the rightmost 4 bits.
*/
