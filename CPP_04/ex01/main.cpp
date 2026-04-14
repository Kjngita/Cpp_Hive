#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int	quantity = 5;
	Animal* array[quantity];
	int	num = 1;
	for (int i = 0; i < quantity; i++)
	{
		std::cout << num << ". ";
		if (i % 2 == 0)
		{
			array[i] = new Dog();
		}
		else
		{
			array[i] = new Cat();
		}
		num++;
	}
	num = 1;
	for (int i = 0; i < quantity; i++)
	{
		std::cout << num << ". ";
		array[i]->makeSound();
		num++;
	}
	for (int i = 0; i < quantity; i++)
		delete array[i];
	std::cout << std::endl;


	std::cout << "= = = = = DEEP COPY? = = = = =\n";
	/*Copy constructor*/
	Dog* pup = new Dog();
	Dog dawg(*pup);
	dawg.setThoughts("Gimme toys", 0);
	std::cout << "Pup: " << pup->getThoughts(0) << std::endl;
	std::cout << "Dawg: " << dawg.getThoughts(0) << std::endl;
	delete pup;
	std::cout << std::endl;

	/*Copy assignment*/
	Cat c;
	c.setThoughts("Brilliant idea", 0);
	c.setThoughts("auth", 1);
	Cat d;
	d = c;
	d.setThoughts("dupe", 1);
	std::cout << "Orig " << c.getType() << ": " << c.getThoughts(0)
			<< " | " << c.getThoughts(1) << std::endl;
	std::cout << "Copy " << d.getType() << ": " << d.getThoughts(0)
			<< " | " << d.getThoughts(1) << std::endl;
	
	return 0;
}