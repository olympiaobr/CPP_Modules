#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>


int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}

/*
int main()
{
    std::cout << "= Initializing Materia Storage =" << std::endl;
    IMateriaSource* source = new MateriaSource();
    std::cout << "=== Learning Basic Materias ===" << std::endl;
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    ICharacter* hero = new Character("Hero");
    std::cout << "= Equipping Materias to Hero =" << std::endl;
    AMateria* iceMateria = source->createMateria("ice");
    hero->equip(iceMateria);
    AMateria* cureMateria = source->createMateria("cure");
    hero->equip(cureMateria);
    hero->equip(new Ice());
    hero->equip(new Cure());

    ICharacter* villain = new Character("Villain");
    std::cout << "= Hero Uses Equipped Materias =" << std::endl;
    hero->use(0, *villain);
    hero->use(1, *villain);

    std::cout << "= Re-Equipping and Using Materia =" << std::endl;
    hero->equip(iceMateria);
    hero->use(0, *villain);

    std::cout << "= Cleanup Operations =" << std::endl;
    delete villain;
    delete hero;
    delete source;

    std::cout << "= End of RPG System Tests =" << std::endl;
    return 0;
}
*/
