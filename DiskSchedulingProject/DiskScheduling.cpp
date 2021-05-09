#include "DiskScheduling.h"
 std::vector<int> DiskScheduling::get_cylinders() {
    return this->cylinders_;
}
 int DiskScheduling::getHeader() {
    return this->header_;
}
 int DiskScheduling::getPreviousRequest() {
    return this->previous_request_;
}
void DiskScheduling::setHeader(int i) {
    header_ = i;
}
void DiskScheduling::addValue(int i) {
    cylinders_.push_back(i);
}
void DiskScheduling::setStrategy(SchedulingAlgorithm* newStrategy) {
    strategy_ = newStrategy;
} 


void DiskScheduling::runAl(DiskScheduling* disk)
{
    if (strategy_) {
        strategy_->runAlgorithm(disk);
    } 
}

 
std::vector<int> DiskScheduling::getVectorRe()
{ 
    return result_cylinders_;
}

void DiskScheduling::setVectorRe(std::vector<int> input)
{
    result_cylinders_ = input;
}

void DiskScheduling::setCylinders(std::vector<int>& input) {
    cylinders_ = input;
}