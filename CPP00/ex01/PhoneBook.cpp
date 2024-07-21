#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : nextIndex(0), contactCount(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::displayMenu() const
{
    std::system("clear");
    std::cout << "======= Phonebook menu =======" << std::endl;
    std::cout << "1. ADD - Insert new contact." << std::endl;
    std::cout << "2. SEARCH - Show contacts." << std::endl;
    std::cout << "3. EXIT - Exit phonebook." << std::endl;
    std::cout << "====================================" << std::endl;
}

void PhoneBook::insertContact()
{
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    newContact.setFName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    newContact.setLName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    newContact.setNickn(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8)
    {
        contactCount++;
    }
    std::cout << "Contact successfully added!" << std::endl;
}

void PhoneBook::findContact() const
{
    if (contactCount == 0)
    {
        std::cout << "No contacts available." << std::endl;
        std::cout << "Press Enter to return to the menu.";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(20) << "First Name" << "|"
              << std::setw(20) << "Last Name" << "|"
              << std::setw(20) << "Nickname" << std::endl;
    for (int i = 0; i < contactCount; ++i)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(20) << contacts[i].getFName() << "|"
                  << std::setw(20) << contacts[i].getLName() << "|"
                  << std::setw(20) << contacts[i].getNickn() << std::endl;
    }
    bool validInput = false;
    while (!validInput)
    {
        int index;
        std::cout << "Enter the index of the contact to display: ";
        std::cin >> index;

        if (std::cin.fail() || index < 0 || index >= contactCount)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index! Please enter a valid index between 0 and " << contactCount - 1 << "." << std::endl;
        }
        else
        {
            validInput = true;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "First Name: " << contacts[index].getFName() << std::endl;
            std::cout << "Last Name: " << contacts[index].getLName() << std::endl;
            std::cout << "Nickname: " << contacts[index].getNickn() << std::endl;
            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
            std::cout << "*************************************************" << std::endl;
        }
    }
    std::cout << "Press Enter to return to the menu.";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

