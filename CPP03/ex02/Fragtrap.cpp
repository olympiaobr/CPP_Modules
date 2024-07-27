#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructed" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap copy assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << "FragTrap " << name << " can't attack because it's out of energy." << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "FragTrap " << name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << name << " cannot repair due to insufficient resources or being knocked out." << std::endl;
    }
}
