#include "Zombie.hpp"

int main()
{
    Zombie *z = newZombie("HeapZombie");
	z->announce();
    randomChump("StackZombie");

    delete z;
    return (0);
}
