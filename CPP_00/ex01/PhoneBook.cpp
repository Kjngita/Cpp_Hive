#include "Phonebook.hpp"

PhoneBook::PhoneBook() {
	_position = 0;
}

PhoneBook::~PhoneBook() {}

static int	input_ok(int i, std::string input)
{
	size_t j;

	if (i == 3)
	{
		for (j = 0; j < input.length(); j++)
			if (!isdigit(input[j]))
				return (0);
		return (1);
	}
	else
	{
		for (j = 0; j < input.length(); j++)
			if (!isalnum(input[j]))
				return (0);
		return (1);
	}
}

void	PhoneBook::addContact()
{
	std::string input;
	std::string	prompt[5] = {"First name: ", "Last name: ", "Nickname: ", 
							"Phone number: ", "Spoil the secret: "};
	if (_position >= 8)
		_position = _position % 8;
	int i = 0;
	while (i < 5)
	{
		std::cout << prompt[i];
		if (std::cin.eof())
		{
			std::cout << "But wait we're not done\n";
			break ;
		}
		std::cin >> input;
		if (!input_ok(i, input))
			continue ;
		if (i == 0)
			_entries[_position].setParam(input, 'F');
		else if (i == 1)
			_entries[_position].setParam(input, 'L');
		else if (i == 2)
			_entries[_position].setParam(input, 'N');
		else if (i == 3)
			_entries[_position].setParam(input, 'P');	
		else if (i == 4)
			_entries[_position].setParam(input, 'S');
		i++;
	}
	_entries[_position].setIndex(_position + 1);
	_position++;
	return ;
}

static void	displayText(std::string text)
{
	if (text.length() > 10)
	{
		std::string	shortened;
		shortened.append(text, 0, 9);
		shortened.append(1, '.');
		std::cout << shortened;
		return ;
	}
	else if (text.length() < 10)
	{
		int fillers = 10 - text.length();
		while (fillers > 0)
		{
			std::cout << " ";
			fillers--;
		}
	}
	std::cout << text;
}

void	PhoneBook::showEntries()
{
	std::string text[4] = {"INDEX", "FIRST NAME", "LAST NAME", "NICKNAME"};
	int i = 0;
	while (i < 4)
	{
		displayText(text[i]);
		if (i < 3)
			std::cout << "|";
		i++;
	}
	std::cout << std::endl;
	i = 0;
	while (i < 8 && !_entries[i].getParam('F').empty())
	{
		std::cout << "         " << _entries[i].getIndex();
		std::cout << "|";
		displayText(_entries[i].getParam('F'));
		std::cout << "|";
		displayText(_entries[i].getParam('L'));
		std::cout << "|";
		displayText(_entries[i].getParam('N'));
		std::cout << std::endl;
		i++;
	}
}

void	PhoneBook::searchContact()
{
	std::cout << "Index of the person you'd like to stalk: ";
	int j;
	if (!(std::cin >> j))
	{
		std::cout << "Need a number (1 - 8) here\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return ;
	}
	if (j < 1 || j > 8)
	{
		std::cout << "Index not within range (1 - 8)\n";
		return ;
	}
	int	i = j - 1;
	if (_entries[i].getParam('F').empty())
		std::cout << "No contact found for this index\n";
	else
	{
		std::cout << "First name: " << _entries[i].getParam('F') << std::endl;
		std::cout << "Last name: " << _entries[i].getParam('L') << std::endl;
		std::cout << "Nickname: " << _entries[i].getParam('N') << std::endl;
		std::cout << "Number: " << _entries[i].getParam('P') << std::endl;
		std::cout << "Secret: " << _entries[i].getParam('S') << std::endl;
	}
	return ;
}