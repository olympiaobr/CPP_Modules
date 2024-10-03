#include <iostream>
#include <cstdlib>
#include <ctime>
#include "U.hpp"

#define NUM_TESTS 10

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator once

    std::cout << "Generating " << NUM_TESTS << " random objects:\n" << std::endl;

    Base* objects[NUM_TESTS];

    for (int i = 0; i < NUM_TESTS; ++i) {
        objects[i] = generate();  // Generate a random object
        std::cout << "Object " << i + 1 << " (pointer): ";
        identify(objects[i]);      // Identify using pointer
        std::cout << "Object " << i + 1 << " (reference): ";
        identify(*objects[i]);     // Identify using reference
        std::cout << std::endl;
    }

    for (int i = 0; i < NUM_TESTS; ++i) {
        delete objects[i];
    }

    std::cout << "\nTesting null pointer identification:\n";
    Base* nullPtr = NULL;
    identify(nullPtr);

    return 0;
}
