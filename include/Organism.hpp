#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include "Organ.hpp"
#include "System.hpp"

class Organism{
    private:
        Organ** Organs;
        System** Systems;
    public:
        Organism(System** systems);
        void PrintOrganism();
};


#endif
