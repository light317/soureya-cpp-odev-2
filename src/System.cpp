#include "System.hpp"

System::System(){
    this->Next = NULL;
    this->Prev = NULL;
}

System::System(System* next){
    this->Next = next;
    this->Prev = NULL;
}

System::System(System* next, System* prev){
    this->Next = next;
    this->Prev = prev;
}

void System::SetOrganLimits(Organ* start, Organ* end){
    this->StartOrgan = start;
    this->EndOrgan = end;
}