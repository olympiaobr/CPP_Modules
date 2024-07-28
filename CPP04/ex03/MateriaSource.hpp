#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    AMateria* templates[4];

public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif
