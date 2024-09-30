#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::list<int> lst;
        lst.push_back(6);
        lst.push_back(7);
        lst.push_back(8);
        lst.push_back(9);
        lst.push_back(10);

        std::cout << "Finding 3 in vector: " << *easyfind(vec, 3) << std::endl;

        std::cout << "Finding 8 in list: " << *easyfind(lst, 8) << std::endl;

        std::cout << "Finding 11 in vector: " << *easyfind(vec, 11) << std::endl;

    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

