#include "ScalarConverter.hpp"

static void	toChar(double trueValue) {
	std::cout << "Char: ";
	if (std::isnan(trueValue) || std::isinf(trueValue)
		|| trueValue < 0 || trueValue > 127)
	{
		std::cout << "Impossible\n";
		return;
	}
	char c = static_cast<char>(trueValue);
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable\n";
}

void	ScalarConverter::convert(const std::string& input) {
	bool	convertable = false;
	long double	trueValue = 0.0;

	//Special case: Single char -> use its ascii value
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		convertable = true;
		trueValue = static_cast<long double>(input[0]);
	}
	else //Check if it's a numeric string
	{
		const char*	str = input.c_str();
		char*	endptr = nullptr;
		trueValue = strtold(str, &endptr); //more checks overflow
		if (endptr != str)
		{
			if (*endptr == 'f' || *endptr == 'F')
				endptr++;
			while (*endptr && std::isspace(*endptr))
				endptr++;
			if (*endptr == '\0')
				convertable = true;
		}
	}
	if (convertable == false)
	{
		std::cout << "ALL IMPOSSIBLE\n";
		return;
	}
	toChar(trueValue);
	// toInt(trueValue);
	// toFloat(trueValue);
	// toDouble(trueValue);
	return;
}