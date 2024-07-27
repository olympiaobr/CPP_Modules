#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout << "Creating characters...\n";
    ClapTrap homelander("Homelander");
    ScavTrap starlight("Starlight");
    ScavTrap destroyer("Destroyer");

    homelander.setAttackDamage(10);
    starlight.setAttackDamage(15);
    destroyer.setAttackDamage(20);

    std::cout << "Starlight and Destroyer enter Guard Gate mode.\n";
    starlight.guardGate();
    destroyer.guardGate();

    std::cout << "\nSimulating battle interactions...\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Starlight - HP: " << starlight.getHitPoints() << ", Energy: " << starlight.getEnergyPoints() << std::endl;
    std::cout << "Homelander - HP: " << homelander.getHitPoints() << ", Energy: " << homelander.getEnergyPoints() << std::endl;
    std::cout << "Destroyer - HP: " << destroyer.getHitPoints() << ", Energy: " << destroyer.getEnergyPoints() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    if (homelander.getEnergyPoints() > 0)
	{
        homelander.attack(starlight.getName());
        starlight.takeDamage(homelander.getAttackDamage());
    }
    if (starlight.getEnergyPoints() > 0)
	{
        starlight.attack(homelander.getName());
        homelander.takeDamage(starlight.getAttackDamage());
    }
    if (destroyer.getEnergyPoints() > 0)
	{
        destroyer.attack(starlight.getName());
        starlight.takeDamage(destroyer.getAttackDamage());
    }

    homelander.beRepaired(5);
    starlight.beRepaired(5);
    destroyer.beRepaired(5);

    std::cout << homelander.getName() << " - HP: " << homelander.getHitPoints() << ", Energy: " << homelander.getEnergyPoints() << std::endl;
    std::cout << starlight.getName() << " - HP: " << starlight.getHitPoints() << ", Energy: " << starlight.getEnergyPoints() << std::endl;
    std::cout << destroyer.getName() << " - HP: " << destroyer.getHitPoints() << ", Energy: " << destroyer.getEnergyPoints() << std::endl;

    std::cout << "\nDestruction sequence initiated...\n";
    return 0;
}
