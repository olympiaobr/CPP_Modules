#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0; // for cloning materia
    virtual void use(ICharacter& target);
};

#endif
