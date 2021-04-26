#pragma once 
#include"SchedulingAlgorithm.h"
#include <vector>
#include<iostream>
using namespace std;
class SchedulingAlgorithm;
class DiskScheduling {
private:
    vector<int> m_cylinders;
    int m_header = 50;
    int m_previous_request = 40 ;
    SchedulingAlgorithm* m_strategy{};
    DiskScheduling* disk{};
public:
    DiskScheduling() : m_header(50), m_previous_request(40) {};
    const vector<int> getCyliaders();
    const int getHeader();
    const int getPreviousRequest();
    void setHeader(int i);
    void addValue(int i);
    void setStrategy(SchedulingAlgorithm* newStrategy);
    void run(DiskScheduling *disk); 
};

