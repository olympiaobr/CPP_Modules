#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
    name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap created with default values." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
    name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
    : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage) {
    std::cout << "ClapTrap " << this->name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    if (this != &rhs)
	{
        name = rhs.name;
        hitPoints = rhs.hitPoints;
        energyPoints = rhs.energyPoints;
        attackDamage = rhs.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
	{
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
	else
	{
        std::cout << "ClapTrap " << name << " cannot attack due to insufficient resources." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > amount)
	{
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage, remaining HP: " << hitPoints << "." << std::endl;
    }
	else
	{
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " has been knocked out!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
	{
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
    }
	else
	{
        std::cout << "ClapTrap " << name << " cannot repair due to insufficient resources or being knocked out." << std::endl;
    }
}

std::string ClapTrap::getName() const {
    return name;
}

unsigned int ClapTrap::getHitPoints() const {
    return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return attackDamage;
}


void ClapTrap::setName(const std::string& newName) {
    name = newName;
}

void ClapTrap::setHitPoints(unsigned int newHitPoints) {
    hitPoints = newHitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int newEnergyPoints) {
    energyPoints = newEnergyPoints;
}

void ClapTrap::setAttackDamage(unsigned int newAttackDamage) {
    attackDamage = newAttackDamage;
}

