#include "Contact.hpp"
#include "Phonebook.hpp"

int main()
{
	PhoneBook	book;
	int i = 0;
	while (1)
	{
		std::cout << "> ";
		std::string cmd;
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			if (i >= 8)
				i = i % 8;
			book.entries[i] = book.addContact();
			i++;
			continue;
		}
		else if (cmd == "SEARCH")
		{
			std::cout << "~~Search mode~~\n";
			continue;
		}
		else if (cmd == "EXIT")
			break;
		else
			continue;
	}
	return (0);
}