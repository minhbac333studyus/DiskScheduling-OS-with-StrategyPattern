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
    DiskScheduling* disk;
public:
    const vector<int> getCyliaders() {
        return this->m_cylinders;
    }
    const int getHeader() {
        return this->m_header;
    }
    const int getPreviousRequest() {
        return this->m_previous_request;
    }
    void setHeader(int i) {
        m_header = i;
    }
    void addValue(int i) {
        m_cylinders.push_back(i);
    }
    void setStrategy(SchedulingAlgorithm* newStrategy) {
        m_strategy = newStrategy; 
    }
    void run(DiskScheduling *disk);
    void print() {
        cout << "\n-------------\n";
        for (int i = 0; i < 10; i++) {
            cout << m_cylinders.at(i) << " ";
        }
        cout << "\n-------------\n";
    }
};

