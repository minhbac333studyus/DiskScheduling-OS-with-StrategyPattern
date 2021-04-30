#pragma once 
#include"SchedulingAlgorithm.h"
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;
class SchedulingAlgorithm;
class DiskScheduling {
private:
    vector<int> m_cylinders;
    int m_header = 0;
    int m_previous_request = 0 ;
    SchedulingAlgorithm* m_strategy{};
    DiskScheduling* disk{};
public:
    DiskScheduling() : m_header(13), m_previous_request(0) {};
    const vector<int> getCyliaders();
    void setCyliaders(vector<int>& input);
    const int getHeader();
    const int getPreviousRequest();
    void setHeader(int i);
    void addValue(int i);
    void setStrategy(SchedulingAlgorithm* newStrategy);
    void run(DiskScheduling *disk); 
};

