#include "PrintManager.h"
#include <iostream>
 
void PrintManager::printCylinder(std::vector<int>& input,std::string keyword)
{
	std::cout << "\t\t";
 
	std::cout << "\n";
	std::cout << keyword << " -> \t";
	for (int i = 0; i < input.size(); i++) {
		printEachTrack(input.at(i));
	} 
	std::cout << "\n";
	std::cout << "\t\t";
 
	std::cout << "\n";
 
}
void PrintManager::printTable(std::vector<int>& input)
{
}
void PrintManager::printEachTrack(int i)
{
	std::cout << "|" << i << "|";
}

void PrintManager::printDiffCylinder(DiskScheduling *disk)
{
	std::string before = "Before", after = "After";
	std::vector<int> v1 = disk->get_cylinders(),v2 = disk->getVectorRe();
	printCylinder(v1,before);
	printCylinder(v2, after);
}

void PrintManager::printTable(DiskScheduling* disk)
{
	int headPos = disk->getHeader();
	std::vector<int> requestOrder = disk->getVectorRe();
	std::cout << "\n______________TABLE TRACKING____________\n";
	for (int i = 0; i < requestOrder.size(); i++) {
		std::cout <<"|\t"<< headPos << "\t -> \t" << requestOrder.at(i) << "\t: " << abs(requestOrder.at(i) - headPos)<<"\t|\n";
		headPos = requestOrder.at(i);
		
	}
}
