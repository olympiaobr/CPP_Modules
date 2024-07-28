#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "Testing the behavior of Dog and Cat derived from Animal." << std::endl;

    //Animal test;

    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    std::cout << "\nDemonstrating polymorphic behavior:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Animal " << i + 1 << " is a " << animals[i]->getType() << " and says: ";
        animals[i]->makeSound();
    }
    std::cout << "\nTesting deep copy functionality for Dog and Cat:" << std::endl;
    Dog originalDog;
    originalDog.changeIdea(0, "Chase the squirrel");
    Dog copiedDog(originalDog);

    Cat originalCat;
    originalCat.changeIdea(0, "Sleep on the keyboard");
    Cat copiedCat(originalCat);

    std::cout << "Original Dog's first idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog's first idea: " << copiedDog.getIdea(0) << std::endl;
    originalDog.changeIdea(0, "Guard the house");
    std::cout << "After modifying, Original Dog's first idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "After modifying, Copied Dog's first idea (should be unchanged): " << copiedDog.getIdea(0) << std::endl;

    std::cout << "Original Cat's first idea: " << originalCat.getIdea(0) << std::endl;
    std::cout << "Copied Cat's first idea: " << copiedCat.getIdea(0) << std::endl;
    originalCat.changeIdea(0, "Chase the laser pointer");
    std::cout << "After modifying, Original Cat's first idea: " << originalCat.getIdea(0) << std::endl;
    std::cout << "After modifying, Copied Cat's first idea (should be unchanged): " << copiedCat.getIdea(0) << std::endl;

    std::cout << "\nCleaning up:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete animals[i];
        std::cout << "Deleted Animal " << i + 1 << std::endl;
    }
    return 0;
}
