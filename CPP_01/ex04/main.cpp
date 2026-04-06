#include <iostream>
#include <fstream>
#include <string>

std::string	modify_text(std::string line, std::string target, std::string replacement)
{
	std::string	ret = line;
	std::string::size_type	found = ret.find(target);
	while (found != std::string::npos)
	{
		ret.erase(found, target.length());
		ret.insert(found, replacement);
		found = ret.find(target);
	}
	return (ret);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Incorrect input. Please enter: <filename> str1 str2\n";
		return 1;
	}
	std::string	argv2 = av[2];
	std::string	argv3 = av[3];
	if (argv2 == argv3)
	{
		std::cout << "Original string and replacement string cannot be identical\n";
		return 1;
	}
	std::ifstream	source(av[1]);
	if (source.is_open())
	{
		std::string	name = av[1];
		name = name.append(".replace");
		std::ofstream	output(name.c_str());
		std::string text;
		while (getline(source, text))
		{
			text = modify_text(text, argv2, argv3);
			output << text << std::endl;
		}
	}
	else
	{
		std::cout << "Can't open file\n";
		return 1;
	}
	return 0;
}