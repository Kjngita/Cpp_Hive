#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	int i = 1;
	while (av[i])
	{
		std::string line = av[i];
		for (size_t j = 0; j < line.length(); j++)
		{
			line[j] = std::toupper((unsigned char)line[j]);
		}
		std::cout << line;
		i++;
	}
	std::cout << std::endl;
	return 0;
}