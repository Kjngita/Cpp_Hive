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
		{
			continue;
		}
	}
	inputFile.close();
}

bool	BitcoinExchange::isValidFormat(const std::string& line, std::string& date, double& value) {
	auto divider = line.find(" | ");
	if (divider == std::string::npos) {
		std::cerr << "[Error] Bad input format\n";
		return false;
	}
	
}

double	BitcoinExchange::findPrice(const std::string& date) const {
	auto iter = priceHistory.find(date);

	if (iter != priceHistory.end()) //Exact date match
		return iter->second;
	
	iter = priceHistory.upper_bound(date); //upper_bound points to element that goes after key (which is a more recent date)
	if (iter == priceHistory.begin())
		throw std::runtime_error("No data available for this ancient date " + date);
	--iter; //move back to the previous date before the asking date
	return iter->second;
}