#include "Cell.hpp"


 Cell::Cell(const int value){
    this->DNA = value;
    this->Next = NULL;
    this->Prev = NULL;
 }

 Cell::Cell(const int value, Cell* next){
     this->DNA = value;
     this->Next = next;
     this->Prev = NULL;
 }

 Cell::Cell(const int value, Cell* next, Cell* prev){
     this->DNA = value;
     this->Next = next;
     this->Prev = prev;

 }

int Cell::GetDNA(){
    return this->DNA;
}