#pragma once
#include "DiskScheduling.h"
#include <iostream>
#include <string>
#include <fstream>
class DiskScheduling;
class Report
{
	std::string tableReport_;
	int costReport_;
public:
	std::string getTableReport();
	double getCostReport();
	void writeReportTable(DiskScheduling* disk);
	void calculateReportCost(DiskScheduling* disk);
	void save(std::string fileName);
}; 

