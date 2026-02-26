#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setNickname(std::string name)
{
	Nickname = name;
}
void Contact::setNumber(std::string number)
{
	Number = number;
}
void Contact::setSecret(std::string secret)
{
	Secret = secret;
}