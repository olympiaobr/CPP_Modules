#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;

    // Handle input
    pmergeMe.handleInput(argv);

    // Organize and sort using vector
    pmergeMe.organizeVector();

    // Organize and sort using list
    pmergeMe.organizeList();

    // Display results
    pmergeMe.showResults();

    return 0;
}




