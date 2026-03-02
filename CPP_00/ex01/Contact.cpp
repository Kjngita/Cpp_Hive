#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setNumber(std::string number)
{
	Number = number;
}

void Contact::setSecret(std::string secret)
{
	Secret = secret;
}

std::string	Contact::getNumber()
{
	return (Number);
}

std::string	Contact::getSecret()
{
	return (Secret);
}