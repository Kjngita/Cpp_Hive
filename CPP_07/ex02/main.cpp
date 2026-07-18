#include "Array.hpp"

int main()
{
	// Array<int> test1;
	// Array<int> test2(12);

	// std::cout << test1.size() << std::endl;
	// std::cout << test2.size() << std::endl;

	// test1 = test2;
	// std::cout << test1.size() << std::endl;

	// std::cout << test2[3] << std::endl;
	
	#define MAX_VAL 5
	std::cout << std::endl << "Array<std::string> TESTS: " << std::endl;
    Array<std::string> empty;
    std::cout << "empty string len: " << empty.size() << std::endl;
    Array<std::string> str(MAX_VAL);
    std::cout << "string len: " << str.size() << std::endl << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        str[i] = "test string " + std::to_string(i);
        std::cout << str[i] << std::endl;
    }

    std::cout << std::endl << "COPY AND ASSIGNMENT TESTS: " << std::endl;
    Array<std::string> assignment = str;
    Array<std::string> copy(assignment);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (assignment[i] != str[i] || copy[i] != assignment[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        else
            std::cout << "ok"  << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        str[i] = "modified string" + std::to_string(i);
        std::cout << str[i] << std::endl;
        std::cout << assignment[i] << std::endl;
        std::cout << copy[i] << std::endl;
    }
    std::cout << std::endl << "INDEX OUT OF BOUNDS TESTS: " << std::endl;
    try
    {
        str[-1] = "test -1";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        str[MAX_VAL] = "test max";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\nCONST ARRAY TEST\n";
    try{
	const Array<int> constArray(5);
	for (unsigned int i = 0; i < constArray.size(); i++)
		std::cout << constArray[i] << '\n';
    std::cout << constArray[-1] << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	return 0;
}