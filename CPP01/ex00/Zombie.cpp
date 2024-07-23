#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
	std::cout << "Zombie " << name << " initialized" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
