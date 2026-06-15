#include "ScalarConverter.hpp"

static bool	convertStr2Double(const std::string& input, double* value) {
	size_t	i;
	*value = std::stod(input, &i);

	if (i != input.length()) //not a pure double value
	{
		if (input.at(i) == 'f' || input.at(i) == 'F')
			i++;
		while (i < input.length() && std::isspace(input[i]))
			i++;
		if (i != input.length())
			return false;
	}
	return true;
}

static void	toChar(double trueVal) {
	std::cout << "char: ";
	if (std::isnan(trueVal) || std::isinf(trueVal)
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

static void	toInt(double trueVal) {
	std::cout << "int: ";
	if (std::isnan(trueVal) || std::isinf(trueVal)
		|| trueVal < INT_MIN || trueVal > INT_MAX)
	{
		std::cout << "Impossible\n";
		return;
	}
	int	i = static_cast<int>(trueVal);
	std::cout << i << std::endl;
}

// static void	toFloat(double trueVal) {

// }

void	ScalarConverter::convert(const std::string& input) {
	bool	convertable = false;
	double	trueValue;

	//Special case: Single char -> use its ascii value
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		trueValue = static_cast<double>(input[0]);
		convertable = true;
	}
	//Check if string can be converted to a double value
	else
	{
		try
		{
			convertable = convertStr2Double(input, &trueValue);
		}
		catch(const std::out_of_range& e)
		{
			convertable = false;
		}
		catch(const std::invalid_argument& e)
		{
			convertable = false;
		}
	}
	if (convertable == false)
	{
		std::cout << "char: Impossible\n";
		std::cout << "int: Impossible\n";
		std::cout << "float: Impossible\n";
		std::cout << "double: Impossible\n";
		return;
	}
	toChar(trueValue);
	toInt(trueValue);
	// toFloat(trueValue);
	// toDouble(trueValue);
	return;
}