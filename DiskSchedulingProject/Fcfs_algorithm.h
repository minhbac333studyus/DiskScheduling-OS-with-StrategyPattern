#pragma once
#include<iostream>
#include "SchedulingAlgorithm.h"
#include "DiskScheduling.h"
#include <algorithm>
using namespace std;
class Fcfs_algorithm : public SchedulingAlgorithm{
public: 
    void runAl(DiskScheduling* disk) override; 
};