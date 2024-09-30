#include "Span.hpp"

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int N) : _maxSize(N), _numbers() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Span is already full!");
    }
    _numbers.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_numbers.size() + std::distance(begin, end) > _maxSize) {
        throw std::runtime_error("Span cannot accommodate the range of numbers!");
    }
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span!");
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span!");
    }
    int minElem = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElem = *std::max_element(_numbers.begin(), _numbers.end());
    return maxElem - minElem;
}
