#ifndef FIXED_HPP 
#define FIXED_HPP

#include <ostream>

class Fixed
{
		int				 	_fixed_point;
		static const int	_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &original);
		Fixed(const int);	
		Fixed(const float);
		Fixed& operator=(Fixed const &original);
		// setter && getter
		void setRawBits(int const fixed_point);
		int getRawBits() const;
		// toFloat and toInt functions;
		float toFloat() const;
		int toInt() const;
		// 6 comparison operators;
		bool operator>(Fixed const &right_side);
		bool operator<(Fixed const &right_side);
		bool operator>=(Fixed const &right_side);
		bool operator<=(Fixed const &right_side);
		bool operator==(Fixed const &right_side);
		bool operator!=(Fixed const &right_side);
		// 4 arithmetic operators;
		Fixed operator+(Fixed const &right_side);
		Fixed operator-(Fixed const &right_side);
		Fixed operator*(Fixed const &right_side);
		Fixed operator/(Fixed const &right_side);
		// 4 increment/decrement
		Fixed &operator++(void);	
		Fixed operator++(int);	
		Fixed &operator--(void);	
		Fixed operator--(int);	
		// requested functions
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

// op insertion -> has to be outside of object, because the order of the arguments is different than all the others
std::ostream &operator<<(std::ostream &stream, const Fixed &number);

#endif
