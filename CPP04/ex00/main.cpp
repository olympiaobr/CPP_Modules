#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();
return 0;
}

/*
int main()
{
    std::cout << "-------------- Normal Animal Tests --------------" << std::endl;
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();

    for (int i = 0; i < 3; ++i) {
        std::cout << animals[i]->getType() << " sounds like: ";
        animals[i]->makeSound();
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i)
	{
        delete animals[i];
    }
    std::cout << "-------------- Testing Array of Pointers --------------" << std::endl;
    const Animal* mixedZoo[5] = {new Dog(), new Cat(), new Animal(), new Dog(), new Cat()};
    for (int i = 0; i < 5; ++i) {
        std::cout << "Zoo animal " << i + 1 << " is a " << mixedZoo[i]->getType() << ": ";
        mixedZoo[i]->makeSound();
    }
    std::cout << std::endl;

    std::cout << "------------------ Wrong Animal Tests -----------------" << std::endl;
    const WrongAnimal* wrongAnimals[3];
    wrongAnimals[0] = new WrongAnimal();
    wrongAnimals[1] = new WrongCat();
    wrongAnimals[2] = new WrongCat();

    for (int i = 0; i < 3; ++i) {

        std::cout << wrongAnimals[i]->getType() << " improperly sounds like: ";
        wrongAnimals[i]->makeSound();
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i)
	{
        delete wrongAnimals[i];
    }
    return 0;
}
*/
