#include "Organism.hpp"
#include <iostream>
#include "Radix.hpp"

Organism::Organism(System** systems){
    this->Systems = systems;
}

void Organism::Print(){
    std::cout<<endl;
    std::cout<<"                    Organism            \n";
    for(System* system = this->Systems[0]; system != NULL; system = system->Next){
        for(Organ* organ = system->StartOrgan; organ != system->EndOrgan; organ = organ->Next){
            if(organ->GetIsBalanced())
                std::cout<<"#";
            else
                std::cout<<" ";
        }
        std::cout<<"\n";
    }
}
