#include "Contact.hpp"
#include "Phonebook.hpp"

int main()
{
	PhoneBook	book;
	while (1)
	{
		std::cout << "- - - - - - - -  - - - - - - - - -\n";
		std::cout << "Enter command: ADD / SEARCH / EXIT\n";
		std::cout << "> ";
		std::string cmd;
		std::getline(std::cin, cmd);
		// std::cin >> cmd;
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
		else if (cmd == "EXIT" || cmd.empty())
			break;
		else
			continue;
	}
	return (0);
}