#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

static std::string trim_spaces(std::string str)
{
	int i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	int j = str.length();
	while (j > i && str[j - 1] == ' ')
		j--;
	std::string chopped = str.substr(i, j - i);
	return (chopped);
}

void Contact::setParam(std::string str, int	param)
{
	if (param == 'F')
		_firstname = trim_spaces(str);
	else if (param == 'L')
		_lastname = trim_spaces(str);
	else if (param == 'N')
		_nickname = trim_spaces(str);
	else if (param == 'P')
		_phonenum = trim_spaces(str);
	else if (param == 'S')
		_secret = trim_spaces(str);
	else
		return ;
}

void	Contact::setIndex(int index)
{
	_index = index;
}

int	Contact::getIndex()
{
	return(_index);
}

std::string	Contact::getParam(int param)
{
	if (param == 'F')
		return (_firstname);
	else if (param == 'L')
		return (_lastname);
	else if (param == 'N')
		return (_nickname);
	else if (param == 'P')
		return (_phonenum);
	else if (param == 'S')
		return (_secret);
	else
		return ("Error getting param");
}
