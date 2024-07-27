#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;

public:
	DiamondTrap(void);
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
    DiamondTrap& operator=(const DiamondTrap& other);

    void whoAmI();
    void attack(const std::string& target);
};

#endif

