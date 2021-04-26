#include <iostream>
#include <vector>
#include "DiskScheduling.h"
#include "SchedulingAlgorithm.h"
#include "Fcfs_algorithm.h"
#include <ctime>
#include<random>
using namespace std;
int produceRandom();
void initualizeData(DiskScheduling& ds);
void showMenu();
int main()
{
    char userOption;
    DiskScheduling ds;
    initualizeData(ds);
    Fcfs_algorithm fcfs;


    cin >> userOption;
    do {
        showMenu(); 
        cin >> userOption;
        if (userOption == '1') {
            ds.setStrategy(&fcfs); 
            ds.run(&ds);
        }
      
    }   
    while (userOption == 'Q' || userOption == 'q');


  
   
    return 0;
}

 
int produceRandom() {  
    random_device rd; 
    // Initialize Mersenne Twister pseudo-random number generator
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 200);
    int a = dis(gen);
    return a;
 
 }
void initualizeData(DiskScheduling& ds) {
    cout << "\nGenerating program....";

    for (unsigned int i = 0; i < 10; i++) {
        ds.addValue(produceRandom());
    }
    cout << "\nGenerating program successfully...\n\n";
}
void showMenu(){
    cout << "\n--------------------------------DISK SCHEDULE ALGORITHM-----------------------------";
    cout << "\n|\tType your choice to run the algorithm                                       |";
    cout << "\n|\t1.First come first serve algorithm                                          |";
    cout << "\n|\t2.Shortest seeking time algorithm                                           |";
    cout << "\n|\t3.Scan algorithm                                                            |";
    cout << "\n|\t4.C-Scan algorithm                                                          |";
    cout << "\n|\t5.Look algorithm                                                            |";
    cout << "\n|\t6.C-Look algorithm                                                          |";
    cout << "\n|\tType Q to quit program                                                      |";
    cout << "\nType your option...: ";
}