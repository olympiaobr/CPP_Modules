#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy assigned" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
	{
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
	else
	{
        std::cout << "ScavTrap " << name << " can't attack because it's out of energy." << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
}
