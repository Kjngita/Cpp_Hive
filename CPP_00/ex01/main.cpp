#include "Contact.hpp"
#include "Phonebook.hpp"

int main()
{
	PhoneBook	book;
	while (1)
	{
		std::cout << "> ";
		std::string cmd;
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			book.addContact();
			continue;
		}
		else if (cmd == "SEARCH")
		{
			book.showEntries();
			book.searchContact();
			continue;
		}
		else if (cmd == "EXIT")
			break;
		else
			continue;
	}
	return (0);
}