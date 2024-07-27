#include "ClapTrap.hpp"
#include <iostream>

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap robotA("Starlight");
    ClapTrap robotB("Homelander");

    robotA.setAttackDamage(5);
    robotB.setAttackDamage(3);

    int rounds = 3;
    while (rounds-- > 0 && robotA.getEnergyPoints() > 0 && robotB.getEnergyPoints() > 0)
	{
        std::cout << "\n--- Round: " << 3 - rounds << " ---" << std::endl;
        std::cout << robotA.getName() << " attacks " << robotB.getName() << std::endl;
        robotB.takeDamage(robotA.getAttackDamage());
        robotB.beRepaired(2);

        std::cout << robotB.getName() << " attacks " << robotA.getName() << std::endl;
        robotA.takeDamage(robotB.getAttackDamage());
        robotA.beRepaired(2);

        std::cout << robotA.getName() << " - HP: " << robotA.getHitPoints() << ", Energy: " << robotA.getEnergyPoints() << std::endl;
        std::cout << robotB.getName() << " - HP: " << robotB.getHitPoints() << ", Energy: " << robotB.getEnergyPoints() << std::endl;
    }

    if(robotA.getEnergyPoints() == 0)
        std::cout << robotA.getName() << " is out of energy points!" << std::endl;
    if(robotB.getEnergyPoints() == 0)
        std::cout << robotB.getName() << " is out of energy points!" << std::endl;

    return 0;
}

