#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Pls provide one file\n";
		return 1;
	}
	try
	{
		BitcoinExchange	trader;
		trader.loadData("data.csv");
		trader.parseInputFile(av[1]);

		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}