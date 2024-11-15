#include "Harl.hpp"
#include <iostream>
#include <map>

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{

    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    std::map<std::string, void (Harl::*)()> functions;
    functions["DEBUG"] = &Harl::debug;
    functions["INFO"] = &Harl::info;
    functions["WARNING"] = &Harl::warning;
    functions["ERROR"] = &Harl::error;

    std::map<std::string, void (Harl::*)()>::iterator it = functions.find(level);
    if (it != functions.end())
	{
        (this->*(it->second))();
    }
	else
	{
        std::cout << "Invalid complaint level: " << level << std::endl;
    }
}
