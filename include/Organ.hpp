#ifndef ORGAN_HPP
#define ORGAN_HPP

#include "Tissue.hpp"

class Organ{
    private:
        bool IsBalanced;
    public:
        Organ* Next;
        Organ* Prev;
        Tissue** Tissues;
        Tissue* MainTissue;
        Tissue* StartTissue;
        Tissue* EndTissue;
        Organ();
        Organ(Organ*);
        Organ(Organ*, Organ*);
        void SetTissueLimits(Tissue*, Tissue*);
        void SetMainTissue(Tissue*);
        int GetTissueCount();
        void SetIsBalanced(bool);
        bool GetIsBalanced();
};


#endif
