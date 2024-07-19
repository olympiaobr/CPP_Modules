#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFName(const std::string& fName) {
    this->fName = fName;
}

void Contact::setLName(const std::string& lName) {
    this->lName = lName;
}

void Contact::setNickn(const std::string& nickn) {
    this->nickn = nickn;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFName() const {
    return fName;
}

std::string Contact::getLName() const {
    return lName;
}

std::string Contact::getNickn() const {
    return nickn;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
