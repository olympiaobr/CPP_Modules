#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

// Constructor
PmergeMe::PmergeMe() {}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

// Assignment Operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        // No resources to copy
    }
    return *this;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Sorting functions for std::vector
void PmergeMe::sortVector(std::vector<int> &vec) {
    mergeInsertSortVector(vec, 0, vec.size() - 1);
}

// Sorting functions for std::deque
void PmergeMe::sortDeque(std::deque<int> &deq) {
    mergeInsertSortDeque(deq, 0, deq.size() - 1);
}

// Merge-Insert Sort for Vector
void PmergeMe::mergeInsertSortVector(std::vector<int> &vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeInsertSortVector(vec, left, mid);
        mergeInsertSortVector(vec, mid + 1, right);
        mergeVector(vec, left, mid, right);  // Manual merge
    }
}

// Merge-Insert Sort for Deque
void PmergeMe::mergeInsertSortDeque(std::deque<int> &deq, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeInsertSortDeque(deq, left, mid);
        mergeInsertSortDeque(deq, mid + 1, right);
        mergeDeque(deq, left, mid, right);  // Manual merge
    }
}

// Manual merge for vector
void PmergeMe::mergeVector(std::vector<int> &vec, int left, int mid, int right) {
    std::vector<int> leftPart(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> rightPart(vec.begin() + mid + 1, vec.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < (int)leftPart.size() && j < (int)rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            vec[k++] = leftPart[i++];
        } else {
            vec[k++] = rightPart[j++];
        }
    }

    while (i < (int)leftPart.size()) {
        vec[k++] = leftPart[i++];
    }

    while (j < (int)rightPart.size()) {
        vec[k++] = rightPart[j++];
    }
}

// Manual merge for deque
void PmergeMe::mergeDeque(std::deque<int> &deq, int left, int mid, int right) {
    std::deque<int> leftPart(deq.begin() + left, deq.begin() + mid + 1);
    std::deque<int> rightPart(deq.begin() + mid + 1, deq.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < (int)leftPart.size() && j < (int)rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            deq[k++] = leftPart[i++];
        } else {
            deq[k++] = rightPart[j++];
        }
    }

    while (i < (int)leftPart.size()) {
        deq[k++] = leftPart[i++];
    }

    while (j < (int)rightPart.size()) {
        deq[k++] = rightPart[j++];
    }
}

// Utility function to print sequences
void PmergeMe::printSequence(const std::string &label, const std::vector<int> &sequence) {
    std::cout << label;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printSequence(const std::string &label, const std::deque<int> &sequence) {
    std::cout << label;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

double PmergeMe::getElapsedTime(struct timeval start, struct timeval end) const {
    // Calculate elapsed time in microseconds (us)
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}



