#pragma once
#include "DiskScheduling.h"
#include<vector>
class DiskScheduling;
class SchedulingAlgorithm{  
public:  
    virtual void runAlgorithm(DiskScheduling *disk) = 0; 
    virtual ~SchedulingAlgorithm() = default;
};