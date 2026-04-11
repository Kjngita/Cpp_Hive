#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "- - - - - - - - - - -\n";
	Animal	subj;
	const Animal* test = &subj;
	std::cout << test->getType() << std::endl;
	test->makeSound();
	test = i;
	std::cout << test->getType() << std::endl;
	test->makeSound();
	// test = NULL;
	// test->makeSound();

	delete test;
	delete meta;
	delete j;
	// delete i;

	std::cout << "- - - - - - - - - - -\n";
	const WrongAnimal* alien = new WrongAnimal();
	const WrongAnimal* kitty = new WrongCat();
	std::cout << kitty->getType() << " " << std::endl;
	kitty->makeSound();
	alien->makeSound();

	delete alien;
	delete kitty;

	return 0;
}