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
			std::cout << "~~Add mode~~\n";
			book.addContact();
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