#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

    std::cout << "Integer array:" << std::endl;
    iter(intArray, 5, printElement<int>);

    std::cout << "\nCharacter array:" << std::endl;
    iter(charArray, 5, printElement<char>);

    std::cout << "\nFloat array:" << std::endl;
    iter(floatArray, 5, printElement<float>);

    return 0;
}
