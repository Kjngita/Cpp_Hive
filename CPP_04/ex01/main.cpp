#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int	quantity = 10;
	Animal* array[quantity];
	int	num = 1;
	for (int i = 0; i < quantity; i++)
	{
		std::cout << num << ". ";
		if (i % 2 == 0)
		{
			array[i] = new Dog();
			// array[i]->makeSound();
		}
		else
		{
			array[i] = new Cat();
			// array[i]->makeSound();
			if (i == 5)
				array[i]->setThoughts();
		}
		std::cout << std::endl;
		num++;
	}
	num = 1;
	for (int i = 0; i < quantity; i++)
	{
		std::cout << num << ". ";
		array[i]->makeSound();
		std::cout << array[i]->getThoughts() << std::endl;
		num++;
	}
	std::cout << "DEEP COPY?\n";
	Animal test(*array[5]);
	std::cout << "Original thought: " << array[5]->getThoughts();
	std::cout << "Copy thought: " << test.getThoughts();
	std::cout << std::endl;

	for (int i = 0; i < quantity; i++)
		delete array[i];
	return 0;
}