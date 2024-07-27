#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout << "Creating characters...\n";
    ClapTrap clap("Clapper");
    ScavTrap scav("Guardian");
    ScavTrap scav2("Watcher");

    clap.setAttackDamage(10);
    scav.setAttackDamage(15);
    scav2.setAttackDamage(20);

    std::cout << "\nGuardian enters Guard Gate mode.\n";
    scav.guardGate();
    std::cout << "Watcher enters Guard Gate mode.\n";
    scav2.guardGate();

    std::cout << "\nSimulating battle interactions...\n";
    for (int round = 0; round < 3; round++)
	{
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << scav.getName() << " Energy: " << scav.getEnergyPoints() << std::endl;
        std::cout << clap.getName() << " Energy: " << clap.getEnergyPoints() << std::endl;
        std::cout << scav2.getName() << " Energy: " << scav2.getEnergyPoints() << std::endl;
        std::cout << "--------------------------------------------------------------------\n";

        if (clap.getHitPoints() > 0 && clap.getEnergyPoints() > 0)
		{
            scav.attack("Clapper");
            clap.takeDamage(15);
            clap.beRepaired(10);
        }
		else
		{
            std::cout << "ClapTrap Clapper is knocked out and cannot participate.\n";
        }
        if (scav.getHitPoints() > 0 && scav.getEnergyPoints() > 0)
		{
            scav2.attack("Guardian");
            scav.takeDamage(20);
            scav.beRepaired(15);
        }
		else {
            std::cout << "ScavTrap Guardian is knocked out and cannot participate.\n";
        }
        if (scav2.getHitPoints() > 0 && scav2.getEnergyPoints() > 0)
		{
            clap.attack("Watcher");
            scav2.takeDamage(10);
            scav2.beRepaired(10);
        }
		else
		{
            std::cout << "ScavTrap Watcher is knocked out and cannot participate.\n";
        }
        if (scav.getEnergyPoints() == 0 || clap.getEnergyPoints() == 0 || scav2.getEnergyPoints() == 0) {
            std::cout << "\nOne or more characters are out of energy points!\n";
            break;
        }
    }
    std::cout << "\nDestruction sequence initiated...\n";
    return 0;
}

