#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadData(std::string fileName) {
	std::ifstream	dataFile(fileName);
	if (!dataFile.is_open())
		throw std::runtime_error("Cannot open data file");
	
	std::string line;
	bool	firstLine = true;
	while (std::getline(dataFile, line))
	{
		if (firstLine) {
			firstLine = false;
			continue;
		}
		if (line.empty())
			continue;

		std::string	date;
		double		price;
		auto comma = line.find(',');
		date = line.substr(0, comma);
		price = std::stod(line.substr(comma+1));

		priceHistory.emplace(date, price);
	}
	dataFile.close();
}


void	BitcoinExchange::parseInputFile(std::string	file) {
	std::ifstream	inputFile(file);
	if (!inputFile.is_open())
		throw std::runtime_error("Cannot open input file");
	
	std::string line;
	bool	firstLine = true;
	while (std::getline(inputFile, line))
	{
		if (firstLine) {
			firstLine = false;
			continue;
		}
		if (line.empty())
			continue;

		std::string date;
		double 		value;
		if (!isValidFormat(line, date, value))
			continue;
		std::string standardDate = normalizeDate(date);
		double price = findPrice(standardDate);
		if (price >= 0)
			std::cout << date << " => " << value << " = " << value * price << std::endl;
	}
	inputFile.close();
}

inline	std::string trimString(const std::string& str) {
	size_t start = str.find_first_not_of(" \n\t\r\f\v");
	if (start == std::string::npos)
		return "";
	size_t	end = str.find_last_not_of(" \n\t\r\f\v");
	return str.substr(start, end - start + 1);
}

bool	BitcoinExchange::isValidFormat(const std::string& line, std::string& date, double& value) {
	auto divider = line.find(" | ");
	if (divider == std::string::npos) {
		std::cerr << "[Error] Bad input format\n";
		return false;
	}
	date = trimString(line.substr(0, divider));
	if (!isValidDate(date)) {
		return false;
	}
	try
	{
		value = std::stod(trimString(line.substr(divider+3)));
		if (value < 0 || value > 1000) {
			std::cerr << "[Error] Input value out of range\n";
			return false;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "[Error] Bad input value\n";
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidDate(const std::string& date) {
	struct tm time = {};
	char* result = strptime(date.c_str(), "%Y-%m-%d", &time);
	return (result != nullptr && *result == '\0');
}

std::string BitcoinExchange::normalizeDate(const std::string& date) {
	int year, month, day;
	char dash1, dash2;
	std::stringstream ss(date);
	
	if (!(ss >> year >> dash1 >> month >> dash2 >> day)) {
		return "";  // Invalid date
	}
	
	// Reformat with leading zeros
	std::stringstream result;
	result << std::setw(4) << std::setfill('0') << year << "-"
		   << std::setw(2) << std::setfill('0') << month << "-"
		   << std::setw(2) << std::setfill('0') << day;
	
	return result.str();
}

double	BitcoinExchange::findPrice(const std::string& date) const {
	auto iter = priceHistory.find(date);
	// std::cout << iter->first;
	if (iter != priceHistory.end()) //Exact date match
		return iter->second;
	
	iter = priceHistory.upper_bound(date); //upper_bound points to element that goes after key (which is a more recent date)
	if (iter == priceHistory.begin()) {
		std::cerr << "[Error] No data available for this ancient date " + date + "\n";
		return -1;
	}
	--iter; //move back to the previous date before the asking date
	return iter->second;
}