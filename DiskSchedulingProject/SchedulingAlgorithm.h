#pragma once
#include "DiskScheduling.h"
class DiskScheduling;
class SchedulingAlgorithm{ 
public: 

    virtual void runAl(DiskScheduling *disk) = 0;
    virtual ~SchedulingAlgorithm() = default;
};