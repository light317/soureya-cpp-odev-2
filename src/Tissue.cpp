#include "Tissue.hpp"
#include "Cell.hpp"
#include "Radix.hpp"

Tissue::Tissue(){
    this->Head = NULL;
    this->Size = 0;
    this->Next = NULL;
    this->Prev = NULL;
}

 Tissue::Tissue(Tissue* next){
    this->Head = NULL;
    this->Size = 0;
    this->Next = next;
    this->Prev = NULL;
 }

 Tissue::Tissue(Tissue* next, Tissue* prev){
    this->Head = NULL;
    this->Size = 0;
    this->Next = next;
    this->Prev = prev;
 }

void Tissue::AddCell(const int& item) {
    InsertCell(Size, item);
}

void Tissue::InsertCell(int index, const int& item) {

    if (index < 0 || index > Size) throw "Index out of Range";
    if (index == 0) {
        Head = new Cell(item, Head);
        if (Head->Next != NULL) Head->Next->Prev = Head;
    } else {
        Cell *prv = FindPreviousByPosition(index);
        
        prv->Next = new Cell(item, prv->Next, prv);

        if (prv->Next->Next != NULL)
            prv->Next->Next->Prev = prv->Next;
    }

    Size++;
}

Cell* Tissue::FindPreviousByPosition(int index) {

    if (index < 0 || index > Size) throw NoSuchElement("No Such Element");

    Cell *prv = Head;

    int i = 1;
    for (Cell* itr = Head; itr->Next != NULL && i != index; itr = itr->Next, i++) {
        prv = prv->Next;
    }

    return prv;
}

bool Tissue::isEmpty()const {
    return Size == 0;
}

void Tissue::remove(const int& item) {
    int index = indexOf(item);
    removeAt(index);
}

void Tissue::removeAt(int index) {
    if (index < 0 || index >= Size) throw "Index out of Range";
    Cell *del;
    if (index == 0) {
        del = Head;
        Head = Head->Next;
        if (Head != NULL) Head->Prev = NULL;
    } else {
        Cell *prv = FindPreviousByPosition(index);
        del = prv->Next;
        prv->Next = del->Next;
        if (del->Next != NULL)
            del->Next->Prev = prv;
    }
    Size--;
    delete del;
}

int Tissue::indexOf(const int& item) {
    int index = 0;
    for (Cell *itr = Head; itr != NULL; itr = itr->Next) {
        if (itr->GetDNA() == item) return index;
        index++;
    }
    throw NoSuchElement("No Such Element");
}

int Tissue::Count(){
    return Size;
}

void Tissue::clear() {
    while (!isEmpty())
        removeAt(0);
}

void Tissue::SetTexture(){
    Radix* radix = new Radix(this,this->Count());
    Cell** sortedCells = radix->Sort();

    int textureIndex = (this->Count() - 1) / 2;

    this->Texture = sortedCells[textureIndex];
    delete [] sortedCells;
    delete radix;
}

Cell* Tissue::GetTexture(){
    return this->Texture;
}

Cell* Tissue::GetHead(){
    return this->Head;
}

Tissue::~Tissue() {
    clear();
}
