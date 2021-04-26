#pragma once
#include<iostream>
#include "SchedulingAlgorithm.h"
#include "DiskScheduling.h"
#include <algorithm>
using namespace std;
class Fcfs_algorithm : public SchedulingAlgorithm{
public: 
    void runAl(DiskScheduling* disk) override {
        cout << "I am running fcfs and return value";
        vector<int> originalVector = disk->getCyliaders();

        vector <int> big,small;
        int header = disk->getHeader();
        //get big
        for (int i = 0; i < originalVector.size(); i++) {
            if (originalVector[i] > header) {
                big.push_back(originalVector[i]);
            }
        }
        sort(big.begin(), big.end());
        
       
    }
  
};