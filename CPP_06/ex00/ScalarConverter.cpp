#include "ScalarConverter.hpp"

enum stringIdentity
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	INVALID_TYPE
};

std::string		trimString(const std::string& input);
stringIdentity	determineType(std::string& input);
bool	isValidInt(std::string& str);
bool	isValidDouble(std::string& str);
bool	isValidFloat(std::string& str);
bool	isWholeNum(double num);
void	toChar(double trueVal);
void	toInt(double trueVal);
void	toFloat(double trueVal);
void	toDouble(double trueVal);

void	ScalarConverter::convert(const std::string& input) {
	std::string cleanStr = trimString(input);
	stringIdentity	trueType = determineType(cleanStr);
	double	trueValue;
	try
	{
		switch (trueType)
		{
			case CHAR_TYPE:
			{
				trueValue = static_cast<double>(cleanStr[0]);
				break;
			}
			case INT_TYPE:
			{
				trueValue = static_cast<double>(std::stoi(cleanStr));
				break;
			}
			case FLOAT_TYPE:
			{
				trueValue = static_cast<double>(std::stof(cleanStr));
				break;
			}
			case DOUBLE_TYPE:
			{
				trueValue = static_cast<double>(std::stod(cleanStr));
				break;
			}
			default: //Strings that are not one of the 4 data types
			{
				std::cout << "char: Impossible\n";
				std::cout << "int: Impossible\n";
				std::cout << "float: Impossible\n";
				std::cout << "double: Impossible\n";
				return;
			}
		}
	}
	catch(const std::exception& e) //No conversion or out of range
	{
		std::cout << "Conversion impossible\n";
		return;
	}
	toChar(trueValue);
	toInt(trueValue);
	toFloat(trueValue);
	toDouble(trueValue);
	return;
}

std::string trimString(const std::string& input) {
	size_t start = input.find_first_not_of(" \n\t\r\f\v");
	if (start == std::string::npos)
		return "";
	size_t	end = input.find_last_not_of(" \n\t\r\f\v");
	return input.substr(start, end - start + 1);
}

stringIdentity	determineType(std::string& input) {

	if (input.length() == 1 && !std::isdigit(input[0]) && std::isprint(input[0]))
		return CHAR_TYPE;
	if (isValidInt(input))
		return INT_TYPE;
	if (input.back() == 'f' && isValidFloat(input))
		return FLOAT_TYPE;
	if (isValidDouble(input))
		return DOUBLE_TYPE;
	return INVALID_TYPE;
}

bool	isValidInt(std::string& str) {
	size_t	startNum = 0;
	if (str.front() == '+' || str.front() == '-')
		startNum++;
	for (size_t i = startNum; i < str.length(); i++)
	{
		if (!std::isdigit(str.at(i)))
			return false;
	}
	return true;
}
 
bool	isValidDouble(std::string& str) {
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
		return true;
	size_t	startNum = 0;
	if (str.front() == '+' || str.front() == '-')
		startNum++;
	size_t	decimalCount = 0;
	size_t	decimalPos = 0;
	for (size_t i = startNum; i < str.length(); i++)
	{
		if (str.at(i) == '.') {
			decimalCount++;
			decimalPos = i;
		}
		if (!std::isdigit(str.at(i)) && str.at(i) != '.')
			return false;
	}
	if (decimalCount != 1 || decimalPos == str.length() - 1) //what abt `.25`?
		return false;
	return true;
}

bool	isValidFloat(std::string& str) {
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
		return true;
	std::string noTrailingF = str.substr(0, str.length() - 1);
	if (isValidDouble(noTrailingF))
		return true;
	return false;
}

bool	isWholeNum(double num) {
	double intpart, fractpart;
	fractpart = modf(num, &intpart);
	if (fractpart == 0.0)
		return true;
	else
		return false;
}

void	toChar(double trueVal) {
	std::cout << "char: ";
	if (std::isnan(trueVal) || std::isinf(trueVal) || !isWholeNum(trueVal)
		|| trueVal < 0 || trueVal > 127)
	{
		std::cout << "Impossible\n";
		return;
	}
	char c = static_cast<char>(trueVal);
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable\n";
}

void	toInt(double trueVal) {
	std::cout << "int: ";
	if (std::isnan(trueVal) || std::isinf(trueVal) || !isWholeNum(trueVal)
		|| trueVal < INT_MIN || trueVal > INT_MAX)
	{
		std::cout << "Impossible\n";
		return;
	}
	int	i = static_cast<int>(trueVal);
	std::cout << i << std::endl;
}

void	toFloat(double trueVal) {
	std::cout << "float: ";
	if (std::isnan(trueVal) || std::isinf(trueVal))
	{
		std::cout << trueVal << "f\n";
		return;
	}
	if (trueVal < -FLT_MAX || trueVal > FLT_MAX)
	{
		std::cout << "Impossible\n";
		return;
	}

	float f = static_cast<float>(trueVal);

	std::ostringstream oss;
	oss << std::setprecision(7) << f;
	std::string formatted = oss.str();

	if (formatted.find('.') != std::string::npos)
	{
		while (formatted.length() > 1 && formatted.back() == '0')
			formatted.pop_back();
		if (formatted.back() == '.')
			formatted.push_back('0');
	}
	else
		formatted.append(".0");

	std::cout << formatted << "f\n";
}

void	toDouble(double trueVal) {
	std::cout << "double: ";
	if (std::isnan(trueVal) || std::isinf(trueVal))
	{
		std::cout << trueVal << std::endl;
		return;
	}
	if (isWholeNum(trueVal))
		std::cout << trueVal << ".0\n";
	else {
	std::ostringstream oss;
	oss << std::setprecision(15) << trueVal;
	std::string formatted = oss.str();

	if (formatted.find('.') != std::string::npos)
	{
		while (formatted.length() > 1 && formatted.back() == '0')
			formatted.pop_back();
		if (formatted.back() == '.')
			formatted.push_back('0');
	}
	else
		formatted.append(".0");

	std::cout << formatted << "\n"; }
}
