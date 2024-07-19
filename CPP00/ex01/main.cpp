#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main() {

    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        phoneBook.displayMenu();
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phoneBook.insertContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.findContact();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Unknown command." << std::endl;
        }
    }
    return 0;
}
