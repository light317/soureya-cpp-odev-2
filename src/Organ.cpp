#include "Organ.hpp"

Organ::Organ(){
    this->Next = NULL;
    this->Prev = NULL;
}

Organ::Organ(Organ* next){
    this->Next = next;
    this->Prev = NULL;
}

Organ::Organ(Organ* next, Organ* prev){
    this->Next = next;
    this->Prev = prev;
}

void Organ::SetTissueLimits(Tissue* start, Tissue* end){
    this->StartTissue = start;
    this->EndTissue = end;
}
 
void Organ::SetMainTissue(Tissue* tissue){
    this->MainTissue = tissue;
}

int Organ::GetTissueCount(){
    int counter = 0;

    for(Tissue* itr = this->StartTissue; itr != this->EndTissue->Next; itr = itr->Next)
        counter++;

    return counter;
}

void Organ::SetIsBalanced(bool val){
    this->IsBalanced = val;
}

bool Organ::GetIsBalanced(){
    return this->IsBalanced;
}