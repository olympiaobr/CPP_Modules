#include "MutantStack.hpp"
#include <iostream>
#include <vector> // Just to demonstrate use of different containers

int main() {
    // Using default container (std::deque)
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Stack contents (forward):" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    std::cout << "Stack contents (reverse):" << std::endl;
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // Using MutantStack with std::vector as underlying container
    MutantStack<int, std::vector<int> > vstack;

    vstack.push(42);
    vstack.push(100);
    std::cout << "Top of vstack (std::vector as container): " << vstack.top() << std::endl;

    return 0;
}

