#ifndef FIXED_HPP 
#define FIXED_HPP

class Fixed{
		int	_fixed_point;
		static const int _bits = 8;
	public:
		// constructor
		Fixed();
		// destructor
		~Fixed();
		// copy constructor -> initialized objects from variables of other object;
		Fixed(Fixed &original);
		// copy assignment op overload -> user defined operator behaviour;
		Fixed& operator=(Fixed &original);
		// subj functions;
		int getRawBits() const; // this function can read member variables but cannot modify them. 
		void setRawBits(int const raw);
};

#endif

