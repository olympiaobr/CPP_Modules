#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "Creating characters...\n";
    ClapTrap clap("Homelander");
    FragTrap frag1("Starlight");

    clap.setAttackDamage(10);
    frag1.setAttackDamage(30);

    std::cout << "\nSimulating battle interactions...\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Round: 1\n";
    std::cout << clap.getName() << " - HP: " << clap.getHitPoints() << ", Energy: " << clap.getEnergyPoints() << std::endl;
    std::cout << frag1.getName() << " - HP: " << frag1.getHitPoints() << ", Energy: " << frag1.getEnergyPoints() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    if (clap.getEnergyPoints() > 0)
	{
        clap.attack(frag1.getName());
        frag1.takeDamage(clap.getAttackDamage());
    }
    if (frag1.getEnergyPoints() > 0)
	{
        frag1.attack(clap.getName());
        clap.takeDamage(frag1.getAttackDamage());
    }
    clap.beRepaired(5);
    frag1.beRepaired(5);
	frag1.highFivesGuys();

    std::cout << clap.getName() << " - HP: " << clap.getHitPoints() << ", Energy: " << clap.getEnergyPoints() << std::endl;
    std::cout << frag1.getName() << " - HP: " << frag1.getHitPoints() << ", Energy: " << frag1.getEnergyPoints() << std::endl;

    std::cout << "\nDestruction sequence initiated...\n";
    return 0;
}

