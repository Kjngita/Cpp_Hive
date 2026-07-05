#pragma once

#include <iostream>

//a struct is public by default
struct Data
{
	std::string	_str;

	Data();
	Data(const Data& other);
	~Data();
	Data& operator=(const Data& other) = delete;

	void	setStr(std::string words);
	std::string getStr() const;
};

std::ostream& operator<<(std::ostream& output, const Data& d);