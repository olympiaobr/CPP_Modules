#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe {
public:
    PmergeMe();  // Default Constructor
    PmergeMe(const PmergeMe &other);  // Copy Constructor
    ~PmergeMe();  // Destructor
    PmergeMe &operator=(const PmergeMe &other);  // Assignment Operator

    void handleInput(char **av);  // Function to process input arguments
    void organizeVector();  // Function to organize and sort using std::vector
    void organizeList();  // Function to organize and sort using std::list
    void showResults();  // Function to display the sorted results and timing

private:
    std::vector<int> _unsortedVector;  // Holds unsorted input for std::vector
    std::list<int> _unsortedList;  // Holds unsorted input for std::list
    std::vector<int> _sortedVector;  // Holds sorted output for std::vector
    std::list<int> _sortedList;  // Holds sorted output for std::list
    double _vectorElapsedTime;  // Stores time taken to sort std::vector
    double _listElapsedTime;  // Stores time taken to sort std::list

    int convertToInt(const std::string &str);  // Converts string to integer
    double computeElapsedTime(struct timeval &start, struct timeval &end);  // Computes elapsed time in microseconds

    // Ford-Johnson Sorting Algorithm
    void fordJohnsonSort(const std::vector<int>& input, std::vector<int>& result);
    void fordJohnsonSort(const std::list<int>& input, std::list<int>& result);

    // Helper function for binary search in vector (to be used in the merge step)
    std::vector<int>::iterator binarySearch(std::vector<int>& sortedSmaller, int element);

    // Helper function for inserting elements into sorted containers
    void insertSorted(std::vector<int>& sortedSmaller, const std::vector<int>& sortedLarger);
    void insertSorted(std::list<int>& sortedSmaller, const std::list<int>& sortedLarger);
};

#endif



