#pragma once

#include <iostream>

class BitcoinExchange
{
	public:
		BitcoinExchange() = delete;
		BitcoinExchange(const BitcoinExchange& other) = delete;
		~BitcoinExchange() = delete;
		BitcoinExchange& operator=(const BitcoinExchange& other) = delete;
};