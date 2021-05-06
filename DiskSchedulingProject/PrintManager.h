#pragma once
#include<vector>
#include<string>
#include "DiskScheduling.h"
#include "Report.h"
class DiskScheduling;
class Report;
class PrintManager
{
	Report* rp_;
public:
	void printCylinder(std::vector<int>&, std::string keyword); 
	void printEachTrack(int i);
	void printDiffCylinder(DiskScheduling *disk);
	void printReport(Report* rp);
};

