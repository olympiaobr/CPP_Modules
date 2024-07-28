#ifndef ICE_H
#define ICE_H

# include <iostream>
# include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    virtual ~Ice();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
