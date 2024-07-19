#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    void insertContact();
    void findContact() const;
    void displayMenu() const;

private:
    Contact contacts[8];
    int nextIndex;
    int contactCount;
};

#endif
