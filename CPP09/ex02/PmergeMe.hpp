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
    // Constructors and Destructor
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();

    // Assignment Operator
    PmergeMe &operator=(const PmergeMe &other);

    // Member Functions
    void handleInput(char **av);
    void organizeVector();
    void organizeList();
    void showResults();

private:
    // Member Variables
    std::vector<int> _unsortedVector;
    std::list<int> _unsortedList;
    std::vector<int> _sortedVector;
    std::list<int> _sortedList;
    double _vectorElapsedTime;
    double _listElapsedTime;

    // Utility Functions
    int convertToInt(const std::string &str);
    double computeElapsedTime(struct timeval &start, struct timeval &end);

    // Ford-Johnson Sorting Functions
    void fordJohnsonSort(const std::vector<int>& input, std::vector<int>& result);
    void fordJohnsonSort(const std::list<int>& input, std::list<int>& result);

    // Insertion Functions
    void insertSorted(std::vector<int>& sortedSmaller, const std::vector<int>& sortedLarger);
    void insertSorted(std::list<int>& sortedSmaller, const std::list<int>& sortedLarger);
};

#endif


