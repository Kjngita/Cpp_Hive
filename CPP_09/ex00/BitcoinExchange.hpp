#pragma once

#include <iostream>
#include <map>
#include <fstream>	//for infile
#include <sstream>	//for validating and modifying date
#include <iomanip>	//for adding 0 in dates

class BitcoinExchange
{
	private:
		std::map<std::string, double>	priceHistory;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other) = delete;
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other) = delete;

		void	loadData(std::string fileName);
		void	parseInputFile(std::string	inputFile);
		double	findPrice(const std::string& date) const;

		bool	isValidFormat(const std::string& line, std::string& date, std::string& standardDate, double& value);
		bool	isValidDate(const std::string& date, std::string& standardDate);
		std::string normalizeDate(const std::string& date);
};