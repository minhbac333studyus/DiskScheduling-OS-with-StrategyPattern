#include "CScan_algorithm.h"
#include <iostream>
#include <algorithm>
void CScan_algorithm::runAlgorithm(DiskScheduling* disk)
{
	std::cout << "\n______________RUN C-SCAN ALGORITHM____________\n";
	std::vector<int> originalCylinder = disk->get_cylinders();
	////START: 100, 26, 27, 28, 4, 5, 6
	////start with 13 
	////GOAL: 26,27,28,100,4,5,6
	//// 	   
	////on the right side , smallest -> got the value
	////new vector result -> push back (the value) 
	int oriHeader = disk->getHeader();
	std::vector<int> bigger, smaller;
	for (auto x : originalCylinder) {
		if (x > oriHeader) {
			bigger.push_back(x);
		}
	}
	for (auto x : originalCylinder) {
		if (x < oriHeader) {
			smaller.push_back(x);
		}
	}
	sort(bigger.begin(), bigger.end(), std::less<int>());//ascending order 26,27,28,100
	sort(smaller.begin(), smaller.end(), std::less<int>()); //ascending order 6,5,4
	std::vector<int> result;
	for (auto x : bigger) {
		result.push_back(x);
	}
	for (auto x : smaller) {
		result.push_back(x);
	}
	//save the result to the disk
	disk->setVectorRe(result);
}
