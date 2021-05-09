#include "Report.h"

void Report::calculateReportCost(DiskScheduling* disk)
{
	if (disk->getStrategy()) {
		std::vector<int> cylinderRe = disk->getVectorRe();
		int headPos = disk->getHeader();
		std::vector<int> requestOrder = disk->getVectorRe();
		int total = 0;
		for (int i = 0; i < requestOrder.size(); i++) {
			total += abs(requestOrder.at(i) - headPos);
			headPos = requestOrder.at(i);
		}
		costReport_ = total;
	}
}
void Report::save(std::string fileName)
{
	std::ofstream outStream;
	outStream.open(fileName);
	outStream << tableReport_;
	outStream.close();
}
std::string Report::getTableReport()
{
	return tableReport_;
}
double Report::getCostReport()
{
	return costReport_;
}
void Report::writeReportTable(DiskScheduling* disk)
{
	if (disk->getStrategy()) {
		tableReport_ = "";
		int headPos = disk->getHeader();
		std::vector<int> requestOrder = disk->getVectorRe();
		tableReport_ += "\n______________TABLE TRACKING____________\n";
		for (int i = 0; i < requestOrder.size(); i++) {
			tableReport_ += "|\t" + std::to_string(headPos) + "\t -> \t" +
				std::to_string(requestOrder.at(i)) + "\t: " +
				std::to_string(abs(requestOrder.at(i) - headPos)) + "\t|\n";
			headPos = requestOrder.at(i);
		}
		tableReport_ += "\nTotal cost for processing all request: " + std::to_string(costReport_);
		tableReport_ += "\nAverage cost: " + std::to_string(costReport_ * 1.0 / requestOrder.size());
		tableReport_ += "\n____________________________________________________________\n\n\n";
	}
}
