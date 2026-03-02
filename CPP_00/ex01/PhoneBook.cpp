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

void	PhoneBook::showEntries()
{
	std::cout << "BEST PHONEBOOK IN TOWN\n";
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
		std::cout << "Index not within range\n";
		return ;
	}
	if (_entries[j - 1].FirstName.empty())
		std::cout << "No contact found for this index" << std::endl;
	else
	{
		std::string	output;

		std::cout << _entries[j - 1].FirstName << std::endl;
		std::cout << _entries[j - 1].LastName << std::endl;
		std::cout << _entries[j - 1].Nickname << std::endl;
		output = _entries[j - 1].getNumber();
		std::cout << output << std::endl;
		output.clear();
		output = _entries[j - 1].getSecret();
		std::cout << output << std::endl;
	}
	return ;
}