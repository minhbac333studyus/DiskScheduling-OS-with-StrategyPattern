#pragma once
#include "DiskScheduling.h"
#include "SchedulingAlgorithm.h"
class DiskScheduling;
class SSTF_algorithm: public SchedulingAlgorithm

{
public:
	virtual void runAlgorithm(DiskScheduling* disk) override;
};

