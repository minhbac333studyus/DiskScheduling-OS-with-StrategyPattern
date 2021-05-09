#pragma once
#include "SchedulingAlgorithm.h"
class CScan_algorithm :
    public SchedulingAlgorithm
{
public:
    virtual void runAlgorithm(DiskScheduling* disk) override;
};

