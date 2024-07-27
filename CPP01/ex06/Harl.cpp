#include "Harl.hpp"
#include <iostream>
#include <string>

#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug() {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info() {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error() {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void Harl::filterComplaints(std::string level)
{
    char firstChar = level[0];
    switch (firstChar)
    {
        case 'D':
            if (level == "DEBUG")
            {
                debug();
                info();
                warning();
                error();
            }
            break;
        case 'I':
            if (level == "INFO")
            {
                info();
                warning();
                error();
            }
            break;
        case 'W':
            if (level == "WARNING")
            {
                warning();
                error();
            }
            break;
        case 'E':
            if (level == "ERROR")
            {
                error();
            }
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

