#include <iostream>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <iomanip> // Include for std::setprecision
#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided!" << std::endl;
        return 1;
    }

    // Parse input into a vector of integers
    std::vector<int> vec;
    std::deque<int> deq;
    for (int i = 1; i < argc; ++i) {
        int num = atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    // Print the original sequence
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    PmergeMe sorter;
    struct timeval start, end;

    // Sort using std::vector
    gettimeofday(&start, NULL);
    sorter.sortVector(vec);
    gettimeofday(&end, NULL);
    double vectorTime = sorter.getElapsedTime(start, end);

    // Print sorted vector
    std::cout << "After (vector): ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Output the elapsed time for vector sorting with increased precision
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
              << vectorTime << " us" << std::endl;

    // Sort using std::deque
    gettimeofday(&start, NULL);
    sorter.sortDeque(deq);
    gettimeofday(&end, NULL);
    double dequeTime = sorter.getElapsedTime(start, end);

    // Print sorted deque
    std::cout << "After (deque): ";
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;

    // Output the elapsed time for deque sorting with increased precision
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: "
              << dequeTime << " us" << std::endl;

    return 0;
}



