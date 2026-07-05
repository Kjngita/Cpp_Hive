#include "Data.hpp"

Data::Data() : _str("Come on Barbie let's go party") {}

Data::Data(const Data& other) : _str(other._str) {}

Data::~Data() {}

void	Data::setStr(std::string words) {
	_str = words;
}

std::string	Data::getStr() const { return _str; }

std::ostream& operator<<(std::ostream& output, const Data& d) {
	output << d.getStr();
	return output;
}