#include "Phonebook.hpp"

PhoneBook::PhoneBook() {
	_position = 0;
}

PhoneBook::~PhoneBook() {}

static int	input_ok(int i, std::string input)
{
	size_t j;

	if (i == 3) //phone number
	{
		for (j = 0; j < input.length(); j++)
			if (!isdigit(input[j])) //is it ok to use C libraries?
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
							"Phone number: ", "Spill the tea will you?: "};
	if (_position >= 8)
		_position = _position % 8;
	int i = 0;
	while (i < 5)
	{
		std::cout << prompt[i];
		std::cin >> input;
		if (std::cin.eof())
		{
			std::cout << "But wait we're not done\n";
			break ;
		}
		if (!input_ok(i, input))
			continue ;
		if (i == 0)
			_entries[_position].FirstName = input;
		else if (i == 1)
			_entries[_position].LastName = input;
		else if (i == 2)
			_entries[_position].Nickname = input;
		else if (i == 3)
			_entries[_position].setNumber(input);	
		else if (i == 4)
			_entries[_position].setSecret(input);
		i++;
	}
	_entries[_position].index = _position + 1;
	_position++;
	return ;
}

void	displayText(std::string text)
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
		int quantity = 10 - text.length();
		while (quantity > 0)
		{
			std::cout << " ";
			quantity--;
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
	while (i < 8 && !_entries[i].FirstName.empty())
	{
		std::cout << "         " << _entries[i].index;
		std::cout << "|";
		displayText(_entries[i].FirstName);
		std::cout << "|";
		displayText(_entries[i].LastName);
		std::cout << "|";
		displayText(_entries[i].Nickname);
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
	if (_entries[j - 1].FirstName.empty())
		std::cout << "No contact found for this index\n";
	else
	{
		std::string	output;

		std::cout << "First name: " << _entries[j - 1].FirstName << std::endl;
		std::cout << "Last name: " << _entries[j - 1].LastName << std::endl;
		std::cout << "Nickname: " << _entries[j - 1].Nickname << std::endl;
		output = _entries[j - 1].getNumber();
		std::cout << "Number: " << output << std::endl;
		output.clear();
		output = _entries[j - 1].getSecret();
		std::cout << "Secret: " << output << std::endl;
	}
	return ;
}