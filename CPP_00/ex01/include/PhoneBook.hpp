#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(int count);
		void addContact(void);
		void searchContact(void);

	private:
		int count;
		Contact contacts[7];
};

#endif
