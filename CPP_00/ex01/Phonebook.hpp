#ifndef PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		int		entries[8];
		PhoneBook();
		~PhoneBook();
		void	addContact();
};

#endif