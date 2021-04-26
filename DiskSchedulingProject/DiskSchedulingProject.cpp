#include <iostream>
#include <vector>
#include "DiskScheduling.h"
#include "SchedulingAlgorithm.h"
#include "Fcfs_algorithm.h"
using namespace std;
 
int main()
{
    std::cout << "Hello World!\n";
    DiskScheduling ds;
    for (int i = 0; i < 10; i++) {
        ds.addValue(i);
    }
   
    Fcfs_algorithm fcfs;
   
    
    ds.setStrategy(&fcfs);
    
    ds.run(&ds);
}
 