#pragma once
#include "SchedulingAlgorithm.h"
class Scan_algorithm :
    public SchedulingAlgorithm
{
public: void runAl(DiskScheduling* disk) override ;
};

