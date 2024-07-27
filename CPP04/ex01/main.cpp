#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "Animal Array Test" << std::endl;
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
        std::cout << "Created Dog " << i + 1 << std::endl;
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
        std::cout << "Created Cat " << i - numAnimals / 2 + 1 << std::endl;
    }

    // Demonstrating polymorphic behavior
    for (int i = 0; i < numAnimals; ++i) {
        std::cout << "Animal " << i + 1 << " is a " << animals[i]->getType() << " and says: ";
        animals[i]->makeSound();
    }

    std::cout << "Deep Copy Tests" << std::endl;

    Dog originalDog;
    originalDog.changeIdea(0, "Chase the ball");
    Dog copiedDog(originalDog); // Using copy constructor

    std::cout << "Original Dog's first idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog's first idea (should be the same): " << copiedDog.getIdea(0) << std::endl;

    // Modify the original dog's idea to check for deep copy
    originalDog.changeIdea(0, "Sleep on the sofa");
    std::cout << "After modifying, Original Dog's first idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "After modifying, Copied Dog's first idea (should be unchanged): " << copiedDog.getIdea(0) << std::endl;

    // Test deep copy functionality of Cat
    Cat originalCat;
    originalCat.changeIdea(0, "Climb the tree");
    Cat copiedCat(originalCat);

    std::cout << "Original Cat's first idea: " << originalCat.getIdea(0) << std::endl;
    std::cout << "Copied Cat's first idea (should be the same): " << copiedCat.getIdea(0) << std::endl;

    // Modify the original cat's idea to check for deep copy
    originalCat.changeIdea(0, "Chase mice");
    std::cout << "After modifying, Original Cat's first idea: " << originalCat.getIdea(0) << std::endl;
    std::cout << "After modifying, Copied Cat's first idea (should be unchanged): " << copiedCat.getIdea(0) << std::endl;

    // Clean up the dynamically created animals
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
        std::cout << "Deleted Animal " << i + 1 << std::endl;
    }
    return 0;
}
