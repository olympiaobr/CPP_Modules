#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    DiamondTrap diamondTrap("Diamond");
    std::cout << std::endl;

    ScavTrap scavTrap("Scavenger");
    std::cout << std::endl;

    FragTrap fragTrap("Fragger");
    std::cout << std::endl;

    ClapTrap clapTrap("Clapper");
    std::cout << std::endl;

    std::cout << "===================== Status Report =====================" << std::endl;
    diamondTrap.whoAmI();
    std::cout << "Hit Points: " << diamondTrap.getHitPoints() << " | Attack Damage: " << diamondTrap.getAttackDamage()
              << " | Energy Points: " << diamondTrap.getEnergyPoints() << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << scavTrap.getName() << std::endl;
    std::cout << "Hit Points: " << scavTrap.getHitPoints() << " | Attack Damage: " << scavTrap.getAttackDamage()
              << " | Energy Points: " << scavTrap.getEnergyPoints() << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << fragTrap.getName() << std::endl;
    std::cout << "Hit Points: " << fragTrap.getHitPoints() << " | Attack Damage: " << fragTrap.getAttackDamage()
              << " | Energy Points: " << fragTrap.getEnergyPoints() << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << clapTrap.getName() << std::endl;
    std::cout << "Hit Points: " << clapTrap.getHitPoints() << " | Attack Damage: " << clapTrap.getAttackDamage()
              << " | Energy Points: " << clapTrap.getEnergyPoints() << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::cout << std::endl << "=============== Functionality Tests ===============" << std::endl;
    diamondTrap.attack("Fragger");
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    std::cout << std::endl;

    return 0;
}
