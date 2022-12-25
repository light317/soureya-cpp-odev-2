#ifndef DATAREADER_HPP
#define DATAREADER_HPP

#include <string>
#include "Cell.hpp"
#include "Tissue.hpp"
#include "Organ.hpp"
#include "System.hpp"
#include "Organism.hpp"


class DataReader{
private:
    std::string fileName;
    Cell** AllCells;
    Tissue** AllTissues;
    Organ** AllOrgans;
    System** AllSystems;
    int CellCount;
    int TissueCount;
    int OrganCount;
    int SystemCount;
    int LineCount();
    void ReadLine();
public:
    DataReader(std::string fileName);
    ~DataReader();
    int GetCellCount();
    int GetTissueCount();
    int GetOrganCount();
    int GetSystemCount();
    Organism* GetOrganism();
};


#endif
