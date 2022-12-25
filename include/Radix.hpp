#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include <cmath>
#include "Tissue.hpp"

class Radix{
	private:	
		Cell** cells;
		int length;
		Queue<Cell*> **queues;
		int maxStep;
		
		int MaxStepNumber();
		int power(int);
		int StepCount(Cell*);
		int* QueueCurrentLengths();
	public:
		Radix(Tissue*, int);
		Cell** Sort();
		~Radix();
};

#endif