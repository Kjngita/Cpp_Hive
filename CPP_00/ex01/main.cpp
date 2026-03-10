#include "Contact.hpp"
#include "Phonebook.hpp"
#include <csignal>
#include <cstring>

sig_atomic_t	g_running = 1;

void signalHandler(int)
{
    g_running = 0;
}

int main()
{
	struct sigaction sig_act;
	
	std::memset(&sig_act, 0, sizeof(sig_act));
	sig_act.sa_handler = signalHandler;

	sigaction(SIGINT, &sig_act, NULL);
	sigaction(SIGQUIT, &sig_act, NULL);
	sigaction(SIGTERM, &sig_act, NULL);

	PhoneBook	book;
	
	while (g_running)
	{
		std::cout << "- - - - - - - -  - - - - - - - - -\n";
		std::cout << "Enter command: ADD / SEARCH / EXIT\n";
		std::cout << "> ";
		std::string cmd;
		std::getline(std::cin, cmd);
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
		else if (cmd == "EXIT" || std::cin.eof())
			break;
		else
			continue;
	}
	return (0);
}