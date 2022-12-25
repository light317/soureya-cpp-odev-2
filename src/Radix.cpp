#include "Radix.hpp"
#include <iostream>

int Radix::MaxStepNumber(){
	int max=0;
	for(int i=0;i<length;i++){
		if(StepCount(cells[i])>max) max = StepCount(cells[i]);
	}
	return max;
}

int Radix::StepCount(Cell* cell){
	int value = abs(cell->GetDNA());
	int basamak=0;
	while(value>0){
		basamak++;
		value /= 10;
	}
	return basamak;
}

Radix::Radix(Tissue* input, int len){
	this->cells = new Cell*[len];
	this->length = len;
	int i = 0;
	for(Cell* itr = input->GetHead(); itr != NULL; itr = itr->Next, i++){this->cells[i] = itr;}

	queues = new Queue<Cell*>*[10];

	for(int j=0;j<10;j++){ queues[j] = new Queue<Cell*>(); }
	maxStep = MaxStepNumber();
}

int* Radix::QueueCurrentLengths(){
	int *lengths = new int[10];
	for(int i=0;i<10;i++){
		lengths[i] = queues[i]->count();
	}
	return lengths;
}

int Radix::power(int e){
	int result=1;
	for(int i=0;i<e;i++) result *= 10;
	return result;
}

Cell** Radix::Sort(){
	int numberIndex=0;
	// read from array once and add to queues
	for(;numberIndex<length;numberIndex++){
		int stepValue = cells[numberIndex]->GetDNA() % 10;
		Cell* cell = cells[numberIndex];
		queues[stepValue]->enqueue(cell);
	}
		
	//i starting from 1 because of first digit processed
	for(int i=1;i<maxStep;i++){
		//get the current length in all queues
		int *qlengths = QueueCurrentLengths();
		for(int index=0;index<10;index++){
			int len=qlengths[index];
			for(;len>0;len--){
				Cell* cell = queues[index]->peek();
				queues[index]->dequeue();
				int stepValue = (cell->GetDNA()/power(i))%10;			
				queues[stepValue]->enqueue(cell);				
			}
		}
		delete [] qlengths;
	}
	Cell** ordered = new Cell*[length];
	numberIndex=0;
	for(int index=0;index<10;index++){
		while(!queues[index]->isEmpty()){
			Cell* number = queues[index]->peek();
			ordered[numberIndex++] = number;
			queues[index]->dequeue();
		}
	}
		
	return ordered;
}

Radix::~Radix(){	
	delete [] cells;
	for(int i=0;i<10;i++) delete queues[i];
	delete [] queues;
}