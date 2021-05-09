#pragma once 
#include"SchedulingAlgorithm.h"
#include <vector>  
 
class SchedulingAlgorithm;
class DiskScheduling {
private:
    std::vector<int> cylinders_;
    std::vector<int> result_cylinders_;
    int header_ = 0;
    int previous_request_ = 0 ;
    SchedulingAlgorithm* strategy_{};
    DiskScheduling* disk{};
public:
    DiskScheduling() : header_(13), previous_request_(0) {};
    std::vector<int> get_cylinders();
    void setCylinders(std::vector<int>& input);
    int getHeader();
    int getPreviousRequest();
    void setHeader(int i);
    void addValue(int i);
    void setStrategy(SchedulingAlgorithm* newStrategy); 
	void runAl(DiskScheduling *disk);
    SchedulingAlgorithm* getStrategy() {
        return strategy_;
    }
    std::vector<int> getVectorRe();
    void setVectorRe(std::vector<int> input); 
};

