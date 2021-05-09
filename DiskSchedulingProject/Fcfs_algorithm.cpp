#include "Fcfs_algorithm.h"
#include <iostream>

void Fcfs_algorithm::runAlgorithm(DiskScheduling* disk)
{
	std::cout << "\n______________RUN FCFS ALGORITHM____________\n";
	std::vector<int> originalCylinder = disk->get_cylinders();
	////START: 100, 26, 27, 28, 4, 5, 6
	////start with 13 
	////GOAL: 100, 26, 27, 28, 4, 5, 6
	//// 	   
	////on the right side , smallest -> got the value
	////new vector result -> push back (the value) 
	int oriHeader = disk->getHeader();
	disk->setVectorRe(originalCylinder);
}
