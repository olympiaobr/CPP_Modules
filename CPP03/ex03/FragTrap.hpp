#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys(void);
    void beRepaired(unsigned int amount);
    void attack(const std::string& target);
};

#endif
