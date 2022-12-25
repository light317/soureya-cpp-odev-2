
#include <iostream>
#include "DataReader.hpp"

int main(){
    DataReader* dataReader = new DataReader("veriler.txt");
    Organism* organism = dataReader->GetOrganism();

    organism->Print();

    //TODO: mutate organism
    std::cin.get();
    std::cout<<"Mutating...\n";
}
