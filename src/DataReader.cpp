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
        //TODO:: call the radix sort on the current tissue, then set the text(or main cell). 
        // We need the middle cell, since all of the tissue have odd number of cells we get that that by taking Count/2
        // remember index xstarts at 0
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
            //TODO:: update, Make it call the AVL algorithm and return the Tissue we want and set it here
            // Or mayb it should just return whehter the tissues of the organ are balanced or not using AVL-> true/false
            // then set that as a flag in the organ

        BSTNode* root = NULL;
        BST* bst = new BST(root);
        for(Tissue* tissue = tempOrgan->StartTissue; tissue != tempOrgan->EndTissue->Next; tissue = tissue->Next){
           // std::cout<<i<<"\n";
            
            root = bst->InsertNode(root,tissue->GetTexture()->GetDNA());
            
            //std::cout<<root->key<<"\n";
        }

        // if(bst->IsBalanced(root)){
        //     std::cout<<"Printable: "<<root->key<<"\n";
        // }else{
        //     std::cout<<"Not Printable\n";
        // }

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

void DataReader::Print(){

    // for(Organ* itr = AllOrgans[0]; itr != NULL; itr = itr->Next){
    //     std::cout<<"pr loop\n";
    //     AVL* avl = new AVL();
    //     std::cout<<"pr1\n";
    //     AVLNode* root = NULL;
    //     for(Tissue* tissue = itr->StartTissue; tissue != itr->EndTissue; tissue = tissue->Next){
    //         std::cout<<"pr loop 2\n";
    //         root = avl->InsertNode(root,tissue->GetTexture()->GetDNA());
    //     }

    //     if(avl->IsBalanced(avl->root)){
    //         std::cout<<"Printable\n";
    //     }else{
    //         std::cout<<"Not Printable\n";
    //     }

    //     delete avl;
    //     //delete root;
    // }
    
    for(Tissue* itr = AllTissues[0]; itr != NULL; itr = itr->Next){
        //itr->SetTexture();
       // std::cout<<itr->GetTexture()->GetDNA()<<", ";
    }
    //Tissue* tissue = AllTissues[2];
    // for(Tissue* tissue = this->AllTissues[0]; tissue != NULL; tissue = tissue->Next)
    // {
    //     std::cout<<"Tissue cell count: "<<tissue->Count()<<"\n";
    //     for(Cell* itr = tissue->GetHead(); itr != NULL; itr = itr->Next)
    //     {
    //         std::cout<<itr->GetDNA()<<" ";
    //     }
    //     std::cout<<"\n\n";
    // }
    
    //Tissue* tissue = AllTissues[100];
    //tissue->SortCells();

    //Radix* radix = new Radix(tissue,tissue->Count());
    // Cell** c =  radix->Sort();
    // std::cout<<tissue->GetHead()->GetDNA()<<"\n";
    // for(int i = 0; i<tissue->Count(); i++ )
    //     {
    //         std::cout<<tissue->Cells[i]->GetDNA()<<" ";
    //     }

    //tissue->SetTexture();
    // for(int i = 0; i<tissue->Count(); i++ )
    //     {
    //         std::cout<<c[i]->GetDNA()<<" ";
    //     }

}

Organism* DataReader::GetOrganism(){
    ReadLine();
    Organism *tmp= new Organism(this->AllSystems);
    // int count=LineCount();
    // for(int i=0;i<count;++i){
    //     tmp->add(this->lines[i]);
    // }
    return tmp;
    
}

DataReader::~DataReader(){
	if(AllTissues!=0){
		int count = LineCount();
		for (int i = 0; i < count; i++){
			if(AllTissues[i]!=0) delete AllTissues[i];
		}
		delete[] AllTissues;
	}
	
}
