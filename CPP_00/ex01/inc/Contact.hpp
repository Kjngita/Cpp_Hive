#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	public:
		int			index;
		std::string	FirstName;
		std::string	LastName;
		Contact();
		~Contact();
		void	setNickname(std::string name);
		void	setNumber(std::string number);
		void	setSecret(std::string secret);
		std::string	getNumber();
		std::string	getNickname();
		std::string	getSecret();
	private:
		std::string	Nickname;
		std::string	Number;
		std::string	Secret;
};

#endif