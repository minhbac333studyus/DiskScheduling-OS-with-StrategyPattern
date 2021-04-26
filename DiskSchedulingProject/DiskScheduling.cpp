#include "DiskScheduling.h"
void DiskScheduling::run(DiskScheduling *disk){
     if (m_strategy) {
         m_strategy->runAl(disk);
     }
     else {
         cout << "Normal behavior";
     }
}