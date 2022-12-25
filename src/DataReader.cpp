#include "DataReader.hpp"
#include <iostream>
#include "Radix.hpp"
#include "BST.hpp"

DataReader::DataReader(std::string fileName) 
{
    this->fileName = fileName;
    this->CellCount = 0;
    this->TissueCount = 0;
    this->OrganCount = 0;
    this->SystemCount = 0;

    int lineCount = LineCount();
    //this -> TissueCount = lineCount; //Every line is a tissue;
    this->AllTissues = new Tissue*[lineCount];
    int organCount = lineCount / 20; //Every 20 tissues is one organ
    int systemCount = organCount / 100; //Every 100 organs is one system
    this->AllOrgans = new Organ*[organCount];
    this->AllSystems = new System*[systemCount];

    for (int i = 0; i < lineCount; i++) 
    {
        Tissue* temp = new Tissue();

        if(i > 0){
            temp->Prev = this->AllTissues[i-1];
            this->AllTissues[i-1]->Next = temp;
        }

        this->AllTissues[i] = temp;
        this->TissueCount++;
    }
}

int DataReader::LineCount() 
{
    int counter = 0;
    std::ifstream file(this->fileName);
    std::string unused;
    while (std::getline(file, unused))
        ++counter;

    file.close();
    return counter;
}

void DataReader::ReadLine() 
{
    std::string token;
    std::ifstream file(this->fileName);
    std::string str;
    int index = 0;
    int cellCount = 0;
    while (std::getline(file, token)) 
    {
        std::istringstream ss(token);
        while (std::getline(ss, str, ' ')) 
        {
            this->AllTissues[index]->AddCell(stoi(str));
            cellCount++;
        }
        
        this->AllTissues[index]->SetTexture();

        if(index > 0){
            this->AllTissues[index]->Prev = this->AllTissues[index-1];
            this->AllTissues[index-1]->Next = this->AllTissues[index];
        }

        index++;

    }
    file.close();

    this->CellCount = cellCount;

    int organIndex;
    int tissueIndex;
    for(organIndex = 0, tissueIndex = 20; tissueIndex <= this->TissueCount; organIndex++, tissueIndex += 20)
    {
        Organ* tempOrgan = new Organ();
         if(organIndex == 0){
             tempOrgan->SetTissueLimits(this->AllTissues[0], this->AllTissues[tissueIndex-1]);
           
         }else{
            tempOrgan->SetTissueLimits(this->AllTissues[tissueIndex-20], this->AllTissues[tissueIndex-1]);
            tempOrgan->Prev = this->AllOrgans[organIndex-1];
            this->AllOrgans[organIndex-1]->Next = tempOrgan;
        }

        BSTNode* root = NULL;
        BST* bst = new BST(root);

        for(Tissue* tissue = tempOrgan->StartTissue; tissue != tempOrgan->EndTissue->Next; tissue = tissue->Next){
            root = bst->InsertNode(root,tissue->GetTexture()->GetDNA());
        }

        tempOrgan->SetIsBalanced(!bst->IsBalanced(root));

        delete bst;

        tempOrgan->SetMainTissue(tempOrgan->EndTissue);
        this->AllOrgans[organIndex] = tempOrgan;
        this->OrganCount++;
    }

    int systemIndex;
    for(systemIndex = 0, organIndex = 100; organIndex <= this->OrganCount; systemIndex++, organIndex += 100)
    {
        System* tempSystem = new System();
        if(systemIndex == 0){
             tempSystem->SetOrganLimits(this->AllOrgans[0], this->AllOrgans[organIndex-1]);
             this->AllSystems[systemIndex] = tempSystem;
         }else{
            tempSystem->SetOrganLimits(this->AllOrgans[organIndex-100], this->AllOrgans[organIndex-1]);
            tempSystem->Prev = this->AllSystems[systemIndex-1];
            this->AllSystems[systemIndex-1]->Next = tempSystem;
            this->AllSystems[systemIndex] = tempSystem;

        }
        this->SystemCount++;
    }
}

int DataReader::GetCellCount(){
    return this->CellCount;
}

int DataReader::GetTissueCount(){
    return this->TissueCount;
}

int DataReader::GetOrganCount(){
    return this->OrganCount;
}

int DataReader::GetSystemCount(){
    return this->SystemCount;
}

Organism* DataReader::GetOrganism(){
    ReadLine();
    Organism *tmp= new Organism(this->AllSystems);
    return tmp;
}

DataReader::~DataReader(){
	if(AllTissues!=0){
		int count = LineCount();
		for (int i = 0; i < count; i++){
			if(AllTissues[i]!=0) delete AllTissues[i];
		}
        delete[] AllCells;
		delete[] AllTissues;
		delete[] AllOrgans;
		delete[] AllSystems;
	}
	
}
