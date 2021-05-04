#pragma once
#include<vector>
#include<string>
#include "DiskScheduling.h"
class DiskScheduling;
class PrintManager
{
public:
	void printCylinder(std::vector<int>&, std::string keyword);
	void printTable(std::vector<int>&);
	void printEachTrack(int i);
	void printDiffCylinder(DiskScheduling *disk);
	void printTable(DiskScheduling* disk);
};

