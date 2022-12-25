
#ifndef CELL_HPP
#define CELL_HPP

#include <iomanip>

class Cell{
    private:
        int DNA;
    public:
        Cell* Next;
        Cell* Prev;
        Cell(const int);
        Cell(const int, Cell*);
        Cell(const int, Cell*, Cell*);
        int GetDNA();
};


#endif
