#include "SSTF_algorithm.h"
#include <iostream>
int findSmallestSeekingIndex(std::vector<int>& input, int header) {
	int smallest = 1e9;
	int smallestIndex = 1e9;
	for (unsigned int i = 0; i < input.size(); i++) {
		if (abs(header - input.at(i)) < smallest) {
			smallest = abs(header - input.at(i));
			smallestIndex = i;
		}
	}
	return smallestIndex;
}
void SSTF_algorithm::runAlgorithm(DiskScheduling* disk)
{
	std::cout << "\n______________RUN SSTF ALGORITHM____________\n";
	std::vector<int> originalCylinder = disk->get_cylinders();
	std::vector<int> result;
	int header = disk->getHeader();
	while (!originalCylinder.empty()) {
		int smallestSeekingTimeIndex = findSmallestSeekingIndex(originalCylinder, header);
		result.push_back(originalCylinder.at(smallestSeekingTimeIndex));
		originalCylinder.erase(originalCylinder.begin() + smallestSeekingTimeIndex);
	}
	disk->setVectorRe(result);
}
