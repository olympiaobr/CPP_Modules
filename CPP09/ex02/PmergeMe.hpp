#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <ctime>
#include <sys/time.h>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortVector(std::vector<int> &vec);
    void sortDeque(std::deque<int> &deq);

    void printSequence(const std::string &label, const std::vector<int> &sequence);
    void printSequence(const std::string &label, const std::deque<int> &sequence);

    double getElapsedTime(struct timeval start, struct timeval end) const;

private:
    void mergeInsertSortVector(std::vector<int> &vec, int left, int right);
    void mergeInsertSortDeque(std::deque<int> &deq, int left, int right);

    void mergeVector(std::vector<int> &vec, int left, int mid, int right);
    void mergeDeque(std::deque<int> &deq, int left, int mid, int right);
};

#endif
