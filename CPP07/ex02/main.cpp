#include "Array.hpp"
#include <iostream>

int main() {
    try {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        Array<int> intArray(5);
        std::cout << "Array of size 5 created." << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        // Modifying elements
        intArray[0] = 10;
        intArray[1] = 20;
        std::cout << "Modified intArray[0] = " << intArray[0] << std::endl;
        std::cout << "Modified intArray[1] = " << intArray[1] << std::endl;

        Array<int> copiedArray = intArray;
        std::cout << "Copied array size: " << copiedArray.size() << std::endl;
        for (unsigned int i = 0; i < copiedArray.size(); i++) {
            std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
        }

        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
        }

        // Testing out-of-bounds access
        std::cout << "Accessing out-of-bounds element: " << intArray[10] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
