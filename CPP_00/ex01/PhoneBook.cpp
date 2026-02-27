#include "Phonebook.hpp"

PhoneBook::PhoneBook() {}

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

Contact	PhoneBook::addContact()
{
	Contact new_entry;
	std::string input;
	std::string	prompt[5] = {"First name: ", "Last name: ", "Nickname: ", 
							"Phone number: ", "Spill the tea will you?: "};
	int	i = 0;
	while (i < 5)
	{
		std::cout << prompt[i];
		std::cin >> input;
		if (!input_ok(i, input))
			continue ;
		if (i == 0)
			new_entry.FirstName = input;
		else if (i == 1)
			new_entry.LastName = input;
		else if (i == 2)
			new_entry.setNickname(input);
		else if (i == 3)
			new_entry.setNumber(input);		
		else if (i == 4)
			new_entry.setSecret(input);
		i++;
	}
	return (new_entry);
}

