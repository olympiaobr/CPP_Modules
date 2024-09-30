#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp_large(10000);
    for (int i = 0; i < 10000; ++i) {
        sp_large.addNumber(std::rand());
    }
    std::cout << "Shortest span: " << sp_large.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp_large.longestSpan() << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < 1000; ++i)
        vec.push_back(i);

    Span sp_range(1000);
    sp_range.addRange(vec.begin(), vec.end());
    std::cout << "Shortest span: " << sp_range.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp_range.longestSpan() << std::endl;

    try {
        sp.addNumber(42);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span sp_empty(5);
        sp_empty.shortestSpan();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

