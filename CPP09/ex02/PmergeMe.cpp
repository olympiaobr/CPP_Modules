#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

// Default Constructor
PmergeMe::PmergeMe() : _vectorElapsedTime(0), _listElapsedTime(0) {}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Assignment Operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->_unsortedVector = other._unsortedVector;
        this->_unsortedList = other._unsortedList;
        this->_sortedVector = other._sortedVector;
        this->_sortedList = other._sortedList;
        this->_vectorElapsedTime = other._vectorElapsedTime;
        this->_listElapsedTime = other._listElapsedTime;
    }
    return *this;
}

// Convert a string to an integer
int PmergeMe::convertToInt(const std::string &str) {
    std::istringstream iss(str);
    int num;
    iss >> num;

    if (iss.fail() || num < 0) {
        std::cerr << "Error: Invalid input \"" << str << "\"" << std::endl;
        exit(1);
    }
    return num;
}

// Handle input arguments
void PmergeMe::handleInput(char **av) {
    for (int i = 1; av[i]; ++i) {
        std::string str = av[i];
        int num = convertToInt(str);
        this->_unsortedVector.push_back(num);
        this->_unsortedList.push_back(num);
    }
}

// Sorting vector using Ford-Johnson algorithm
void PmergeMe::organizeVector() {
    struct timeval start, end;
    gettimeofday(&start, NULL); // Start timing

    // Apply Ford-Johnson algorithm for sorting
    fordJohnsonSort(this->_unsortedVector, this->_sortedVector);

    gettimeofday(&end, NULL); // End timing
    this->_vectorElapsedTime = computeElapsedTime(start, end); // Store time taken in microseconds
}

// Sorting list using Ford-Johnson algorithm
void PmergeMe::organizeList() {
    struct timeval start, end;
    gettimeofday(&start, NULL); // Start timing

    // Apply Ford-Johnson algorithm for sorting
    fordJohnsonSort(this->_unsortedList, this->_sortedList);

    gettimeofday(&end, NULL); // End timing
    this->_listElapsedTime = computeElapsedTime(start, end); // Store time taken in microseconds
}

// Ford-Johnson sorting algorithm for std::vector
void PmergeMe::fordJohnsonSort(const std::vector<int>& input, std::vector<int>& result) {
    if (input.size() <= 1) {
        result = input;
        return;
    }

    // Step 1: Pair elements and divide them into two groups
    std::vector<int> smaller, larger;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i + 1]) {
            smaller.push_back(input[i]);
            larger.push_back(input[i + 1]);
        } else {
            smaller.push_back(input[i + 1]);
            larger.push_back(input[i]);
        }
    }

    // If odd number of elements, add the last element to the smaller list
    if (input.size() % 2 == 1) {
        smaller.push_back(input.back());
    }

    // Step 2: Recursively sort both groups
    std::vector<int> sortedSmaller, sortedLarger;
    fordJohnsonSort(smaller, sortedSmaller);
    fordJohnsonSort(larger, sortedLarger);

    // Step 3: Merge both sorted halves
    result = sortedSmaller; // Start with the smaller elements
    insertSorted(result, sortedLarger); // Insert the larger elements in their correct positions
}

// Ford-Johnson sorting algorithm for std::list
void PmergeMe::fordJohnsonSort(const std::list<int>& input, std::list<int>& result) {
    if (input.size() <= 1) {
        result = input;
        return;
    }

    // Step 1: Pair elements and divide them into two groups
    std::list<int> smaller, larger;
    std::list<int>::const_iterator it = input.begin();
    while (it != input.end()) {
        int first = *it++;
        if (it != input.end()) {
            int second = *it++;
            if (first < second) {
                smaller.push_back(first);
                larger.push_back(second);
            } else {
                smaller.push_back(second);
                larger.push_back(first);
            }
        } else {
            smaller.push_back(first); // Odd element, goes in smaller list
        }
    }

    // Step 2: Recursively sort both groups
    std::list<int> sortedSmaller, sortedLarger;
    fordJohnsonSort(smaller, sortedSmaller);
    fordJohnsonSort(larger, sortedLarger);

    // Step 3: Merge both sorted halves
    result = sortedSmaller; // Start with the smaller elements
    insertSorted(result, sortedLarger); // Insert the larger elements in their correct positions
}

// Insert elements from sortedLarger into sortedSmaller maintaining order (for vector)
void PmergeMe::insertSorted(std::vector<int>& sortedSmaller, const std::vector<int>& sortedLarger) {
    std::vector<int> result;
    size_t i = 0, j = 0;

    // Merge both sorted sequences
    while (i < sortedSmaller.size() && j < sortedLarger.size()) {
        if (sortedSmaller[i] <= sortedLarger[j]) {
            result.push_back(sortedSmaller[i++]);
        } else {
            result.push_back(sortedLarger[j++]);
        }
    }

    // Add any remaining elements from both sequences
    while (i < sortedSmaller.size()) result.push_back(sortedSmaller[i++]);
    while (j < sortedLarger.size()) result.push_back(sortedLarger[j++]);

    sortedSmaller = result;
}

// Insert elements from sortedLarger into sortedSmaller maintaining order (for list)
void PmergeMe::insertSorted(std::list<int>& sortedSmaller, const std::list<int>& sortedLarger) {
    std::list<int>::iterator it1 = sortedSmaller.begin();
    std::list<int>::const_iterator it2 = sortedLarger.begin();

    // Merge both sorted sequences
    while (it2 != sortedLarger.end()) {
        while (it1 != sortedSmaller.end() && *it1 <= *it2) ++it1;
        sortedSmaller.insert(it1, *it2);
        ++it2;
    }
}

// Calculate elapsed time in microseconds
double PmergeMe::computeElapsedTime(struct timeval &start, struct timeval &end) {
    return ((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec));
}

// Print results
void PmergeMe::showResults() {
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = _unsortedVector.begin(); it != _unsortedVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "After: ";
    for (std::vector<int>::iterator it = _sortedVector.begin(); it != _sortedVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _unsortedVector.size() << " elements with std::vector: "
              << std::fixed << std::setprecision(5) << _vectorElapsedTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _unsortedList.size() << " elements with std::list: "
              << std::fixed << std::setprecision(5) << _listElapsedTime << " us" << std::endl;
}
