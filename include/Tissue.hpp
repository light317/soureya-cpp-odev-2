#ifndef TISSUE_HPP
#define TISSUE_HPP

#include <fstream>
#include <iostream>
#include <sstream>

#include "Cell.hpp"
#include "NoSuchElement.hpp"

class Tissue{
    private:
        int Size;
        Cell* Texture;
        Cell* Head;
        void RadixSort();
    public:
        Tissue* Next;
        Tissue* Prev;
        Tissue();
        Tissue(Tissue*);
        Tissue(Tissue*, Tissue*);
        ~Tissue();
        Cell** Cells;
        Cell** SortedCells;
        void AddCell(const int& item);
        void InsertCell(int index, const int& item);
        Cell* FindPreviousByPosition(int index);
        void remove(const int& item);
        void removeAt(int index);
        int indexOf(const int& item);
        bool isEmpty()const;
        int Count();
        void clear();
        void SetTexture();
        Cell* GetHead();
        Cell* GetTexture();
};


#endif