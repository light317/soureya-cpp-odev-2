#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Organ.hpp"

class System{
    public:
        System* Next;
        System* Prev;
        Organ** Organs;
        Organ* StartOrgan;
        Organ* EndOrgan;
        System();
        System(System*);
        System(System*, System*);
        void SetOrganLimits(Organ*, Organ*);
};


#endif
