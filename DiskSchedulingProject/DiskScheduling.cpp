#include "DiskScheduling.h"
const vector<int> DiskScheduling::getCyliaders() {
    return this->m_cylinders;
}
const int DiskScheduling::getHeader() {
    return this->m_header;
}
const int DiskScheduling::getPreviousRequest() {
    return this->m_previous_request;
}
void DiskScheduling::setHeader(int i) {
    m_header = i;
}
void DiskScheduling::addValue(int i) {
    m_cylinders.push_back(i);
}
void DiskScheduling::setStrategy(SchedulingAlgorithm* newStrategy) {
    m_strategy = newStrategy;
} 
void DiskScheduling::run(DiskScheduling *disk){
     if (m_strategy) {
         m_strategy->runAl(disk);
     }
     else {
         cout << "Normal behavior";
     }
}