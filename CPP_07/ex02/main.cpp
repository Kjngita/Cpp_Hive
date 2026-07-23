#include "Array.hpp"

int main()
{
	std::cout << "   === INT ARRAYS ===\n\n";

	std::cout << "Test int array. Length = ";
	Array<int> intArr(7);
	std::cout << intArr.size() << std::endl;
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	
	std::cout << "\n[ Copy constructor ]\n";
	std::cout << "\tarrCopy: \n\t";
	Array<int> arrCopy(intArr);
	for (unsigned int i = 0; i < arrCopy.size(); i++)
		std::cout << " " << arrCopy[i] ;
	arrCopy[0] = 987;
	std::cout << "\n\tModified arrCopy: \n\t";
	for (unsigned int i = 0; i < arrCopy.size(); i++)
		std::cout << " " << arrCopy[i];
	
	std::cout << "\n[ Copy assignment ]\n";
	Array<int> zero;
	std::cout << "\tEmpty int array. Length = " << zero.size();
	zero = arrCopy;
	std::cout << "\n\tModified empty array: \n\t";
	for (unsigned int i = 0; i < zero.size(); i++)
	{
		if (i == 3)
			zero[i] = 123;
		std::cout << " " << zero[i];
	}

	std::cout << "\nOriginal test int array unharmed: \n";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << " " << intArr[i];

//----------------------------------------------------------------
	std::cout << "\n\n   === STR ARRAYS ===\n\n";

	std::cout << "Normal array = { ";
	Array<std::string> strArr(3);
	for (unsigned int i = 0; i < strArr.size(); i++)
	{
		strArr[i] = "String " + std::to_string(i+1);
		if (i != strArr.size() - 1)
			std::cout << strArr[i] << ", ";
		else
			std::cout << strArr[i] << " }\n";
	}
	try
	{
		std::cout << "[ Out of bound - normal array ]\n";
		std::cout << "\tIndex [-2]\t-> ";
		std::cout << strArr[-2];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "Const array = { ";
	const Array<std::string> constStrArr(3);
	for (unsigned int i = 0; i < constStrArr.size(); i++)
	{
		constStrArr[i] = "Line " + std::to_string(i+1);
		if (i != constStrArr.size() - 1)
			std::cout << constStrArr[i] << ", ";
		else
			std::cout << constStrArr[i] << " }\n";
	}
	try
	{
		std::cout << "[ Out of bound - const array ]\n";
		std::cout << "\tIndex [10]\t-> ";
		std::cout << constStrArr[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}