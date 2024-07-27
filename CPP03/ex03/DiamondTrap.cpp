#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


DiamondTrap::DiamondTrap() :
    ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap(), name("DiamondTrap")
{
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) :
    ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << name << " constructed" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &other) :
    ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    *this = other;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destructed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
