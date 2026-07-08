#include "iter.hpp"
#include <iostream>

//normal function
template <typename T>
void	printElement(const T& elem) {
	std::cout << elem << " ";
}

//functor
template <typename T>
struct	IntMod {
	private:
		T	add_this;
	public:
		IntMod(T n) : add_this(n) {}
		void	operator() (T& num) {
			num += add_this;
		}
};

class	StrScream {
	public:
		void	operator()(std::string& str) {
			for (unsigned int i = 0; i < str.length(); i++)
				str.at(i) = toupper(str.at(i));
		}
};

int main()
{
	std::cout << "   === Int array ===\n";
	int arr[] = { 3, 7, 56, 344, 75 , 123456789};
	int arrLen = sizeof(arr)/sizeof(arr[0]);
	std::cout << "[OG array]\t";
	iter(arr, arrLen, printElement<int>);
	std::cout << std::endl;
	
	IntMod<int>	add10(10);
	iter(arr, arrLen, add10);
	std::cout << "[+ array]\t";
	iter(arr, arrLen, printElement<int>);
	std::cout << std::endl;

//-----------------------------------------------------
	std::cout << "\n   === Double array ===\n";
	double nums[] = { 1.1, 2.2, 3.3 };
	int numsLen = sizeof(nums)/sizeof(nums[0]);
	std::cout << "[OG array]\t";
	iter(nums, numsLen, printElement<double>);
	std::cout << std::endl;

	IntMod<double>	minus5(-5);
	iter(nums, numsLen, minus5);
	std::cout << "[- array]\t";
	iter(nums, numsLen, printElement<double>);
	std::cout << std::endl;

//-----------------------------------------------------
	std::cout << "\n   === Str array ===\n";
	std::string strs[] = { "this", "is", "sparta", "!!!" };
	int strsLen = sizeof(strs)/sizeof(strs[0]);
	std::cout << "[Old]\t";
	iter(strs, strsLen, printElement<std::string>);
	std::cout << std::endl;
	iter(strs, strsLen, StrScream());
	std::cout << "[New]\t";
	iter(strs, strsLen, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}