#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::setIndex(int index)
{
	_index = index;
}

int	Contact::getIndex()
{
	return(_index);
}

void Contact::setParam(std::string str, int	param)
{
	if (param == 'F')
		_firstname = str;
	else if (param == 'L')
		_lastname = str;
	else if (param == 'N')
		_nickname = str;
	else if (param == 'P')
		_phonenum = str;
	else if (param == 'S')
		_secret = str;
	else
		return ;
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
