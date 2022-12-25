

// /* 
//  * File:   main.cpp
//  * Author: HAKAN
//  *
//  * Created on November 1, 2022, 6:55 AM
//  */

// #include <cstdlib>
// #include "SatirListesi.hpp"
// #include "YoneticiListesi.hpp"
// #include "ReadAndAdd.hpp"
// #include "DisplayAtConsole.hpp"
// #include  "Exception.hpp"

// // using namespace std;

// /*
//  * 
//  */
// int main(int argc, char** argv) {

//     ReadAndAdd * readingFile = new ReadAndAdd("veriler.txt");

//     YoneticiListesi *yoneticiListesi = readingFile->GetFillYoneticiListesi();

//     DisplayAtConsole *console = new DisplayAtConsole(yoneticiListesi);
//     yoneticiListesi->sortByAverage();
//     std::string karakter = "";
//     do {
//         console->printYoneticiListesi();
//         std::cin>>karakter;
//         if (karakter == "c") {
//             Direction direction = up;
//             console->setState(direction);
//         } else if (karakter == "z") {
//             Direction direction = down;
//             console->setState(direction);
//         } else if (karakter == "k") {
//             int randomIndex = 0;
//             try {
//                 randomIndex = console->DisplayRandomSelectedNode();
//             } catch (...) {
//                 continue;

//             }
//             std::cin>>karakter;
//             if (karakter == "k") {

//                 console->DeleteRandomSelectedNode(randomIndex);
//                 yoneticiListesi->sortByAverage();

//             }
//         } else if (karakter == "p") {
//             console->DeleteYoneticiNode();
//         } else if (karakter == "d") {
//             console->SetPage(upPage);
//         } else if (karakter == "a") {
//             console->SetPage(downPage);
//         }


//     } while (karakter != "q");



//     return 0;



// }

#include <iostream>
#include "Cell.hpp"
#include "Tissue.hpp"
#include "DataReader.hpp"
#include <list>
#include "BST.hpp"

void t(bool x){
    x ? std::cout<<"balanced\n" : std::cout<<"not balanced\n";
}

int main(){
    std::cout<<"hi\n";
    DataReader* d = new DataReader("fish.txt");
    Organism* o = d->GetOrganism();

    // int n;
    // std::cin>>n;

    // std::list<int> t[n];
    //std::cout<<"Cells: "<<d->GetCellCount()<<"\n";
    //std::cout<<"Tissues: "<<d->GetTissueCount()<<"\n";
    //std::cout<<"Organs: "<<d->GetOrganCount()<<"\n";
    //std::cout<<"Systems: "<<d->GetSystemCount()<<"\n";


    //d->Print();
    o->PrintOrganism();

    BSTNode* root = NULL;
    BST* bst = new BST(root);

    int input = 0;

    for(int a = 0; a < 100;a++ ){
        std::cin>>input;
        root = bst->InsertNode(root,input);
        //std::cout<<root->key<<"\n";
        bst->printTree(root,"",true);
        t(bst->IsBalanced(root));
    }
       
}
