#ifndef PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact	entries[8];
		PhoneBook();
		~PhoneBook();
		Contact	addContact();
};

#endif