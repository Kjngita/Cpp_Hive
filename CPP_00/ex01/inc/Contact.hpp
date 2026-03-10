#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();
		void		setIndex(int index);
		int			getIndex();
		void 		setParam(std::string str, int param);
		std::string	getParam(int param);

	private:
		int			_index;
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenum;
		std::string	_secret;
};

extern __sig_atomic_t	g_running;

#endif