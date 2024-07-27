#include "ClapTrap.hpp"
#include <iostream>

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap heroA("Starlight");
    ClapTrap heroB("Homelander");

    heroA.setAttackDamage(5);
    heroB.setAttackDamage(3);

    int rounds = 2;
    std::cout << "\nStarting battle..." << std::endl;

    for (int round = 1; round <= rounds; ++round) {
        std::cout << "\n--- Round: " << round << " ---" << std::endl;

        if (heroA.getEnergyPoints() > 0 && heroB.getEnergyPoints() > 0)
		{
            std::cout << heroA.getName() << " attacks " << heroB.getName() << std::endl;
            heroA.attack(heroB.getName());
            heroB.takeDamage(heroA.getAttackDamage());

            std::cout << heroB.getName() << " attacks " << heroA.getName() << std::endl;
            heroB.attack(heroA.getName());
            heroA.takeDamage(heroB.getAttackDamage());
        }
        if (heroB.getEnergyPoints() > 0)
		{
            heroB.beRepaired(2);
        }
        if (heroA.getEnergyPoints() > 0)
		{
            heroA.beRepaired(2);
        }
        std::cout << heroA.getName() << " - HP: " << heroA.getHitPoints() << ", Energy: " << heroA.getEnergyPoints() << std::endl;
        std::cout << heroB.getName() << " - HP: " << heroB.getHitPoints() << ", Energy: " << heroB.getEnergyPoints() << std::endl;
    }
    if (heroA.getEnergyPoints() == 0)
        std::cout << "\n" << heroA.getName() << " is out of energy points!" << std::endl;
    if (heroB.getEnergyPoints() == 0)
        std::cout << heroB.getName() << " is out of energy points!" << std::endl;
    std::cout << "\nDestruction sequence initiated...\n";

    return 0;
}

