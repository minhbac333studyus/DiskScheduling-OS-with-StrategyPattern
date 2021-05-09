#include <iostream>
#include <vector>
#include <ctime>
#include<random>
#include<fstream> 
#include "DiskScheduling.h"
#include "SchedulingAlgorithm.h"
#include "PrintManager.h"
#include "Report.h"
#include "Fcfs_algorithm.h"
#include "Scan_algorithm.h"
#include "SSTF_algorithm.h"
#include "CScan_algorithm.h"

using namespace std; 
int produceRandom();
void test_and_report_all_Strategy(DiskScheduling& ds, Fcfs_algorithm& fcfs, Report& rp, PrintManager& pm, SSTF_algorithm& sstf, Scan_algorithm& scan, CScan_algorithm& cscan);
void printFinalReport(double costFCFS, double costSSTF, double costScan, double costCScan, int sz);
void printFastestReport(double costFCFS, double costSSTF, double costScan, double costCScan,int sz);
void printSlowestReport(double costFCFS, double costSSTF, double costScan, double costCScan, int sz);
void initualizeData(DiskScheduling& ds);
void showMenu();
 
int main()
{
 
    char userOption;
    DiskScheduling ds; 
    PrintManager pm;
    Report rp; 
    initualizeData(ds); 
    
    Fcfs_algorithm fcfs;
    Scan_algorithm scan;
    SSTF_algorithm sstf;
    CScan_algorithm cscan;
    vector<int> resultVector;
    do {
        showMenu(); 
        cin >> userOption;
        if (userOption == '1') { 
            ds.setStrategy(&fcfs);   
        }
        else if (userOption == '2') {
            ds.setStrategy(&sstf); 
        }
        else if (userOption == '3') { 
            ds.setStrategy(&scan);   
        }
        else if (userOption == '4') {
            ds.setStrategy(&cscan); 
        }
        else if (userOption == '5') { 
            test_and_report_all_Strategy(ds, fcfs, rp, pm, sstf, scan, cscan);
            continue; 
        }
        ds.runAl(&ds);
        resultVector = ds.getVectorRe();
        rp.calculateReportCost(&ds);
        rp.writeReportTable(&ds);
        pm.printDiffCylinder(&ds);
        pm.printReport(&rp);
        rp.save("output.txt");
    }   
    while (userOption != 'Q' && userOption != 'q'); 
   
    return 0;
}
void test_and_report_all_Strategy(DiskScheduling& ds, Fcfs_algorithm& fcfs, Report& rp, PrintManager& pm, SSTF_algorithm& sstf, Scan_algorithm& scan, CScan_algorithm& cscan)
{
    cout << "\nRunning all of the program...";
    double costFCFS, costSSTF, costScan, costCScan;
    ds.setStrategy(&fcfs);
    ds.runAl(&ds);
    rp.calculateReportCost(&ds);
    rp.writeReportTable(&ds);
    pm.printReport(&rp);
    costFCFS = rp.getCostReport();

    ds.setStrategy(&sstf);
    ds.runAl(&ds);
    rp.calculateReportCost(&ds);
    rp.writeReportTable(&ds);
    pm.printReport(&rp);
    costSSTF = rp.getCostReport();

    ds.setStrategy(&scan);
    ds.runAl(&ds);
    rp.calculateReportCost(&ds);
    rp.writeReportTable(&ds);
    pm.printReport(&rp);
    costScan = rp.getCostReport();

    ds.setStrategy(&cscan);
    ds.runAl(&ds);
    rp.calculateReportCost(&ds);
    rp.writeReportTable(&ds);
    pm.printReport(&rp);
    costCScan = rp.getCostReport();

    printFinalReport(costFCFS, costSSTF, costScan, costCScan,10);
    cout << "\n\n";
}
void printFastestReport(double costFCFS, double costSSTF, double costScan, double costCScan, int sz)
{
    if (costFCFS > costSSTF and costFCFS > costScan && costFCFS > costCScan) {
        cout << "\n\tFCFS has the slowest speed";
        cout << "\n\tTotal cost: " << costFCFS;
        cout << "\n\tAverage cost: " << costFCFS / sz;
    }
    else if (costSSTF > costFCFS && costSSTF > costScan && costSSTF > costCScan) {
        cout << "\n\tFCFS has the slowest speed";
        cout << "\n\tTotal cost: " << costSSTF;
        cout << "\n\tAverage cost: " << costSSTF / sz;
    }
    else if (costScan > costFCFS && costScan > costSSTF && costScan > costCScan) {
        cout << "\n\tSCAN has the slowest speed";
        cout << "\n\tTotal cost: " << costScan;
        cout << "\n\tAverage cost: " << costScan / sz;
    }
    else {
        cout << "\n\tCScan has the slowest speed";
        cout << "\n\tTotal cost: " << costCScan;
        cout << "\n\tAverage cost: " << costCScan / sz;
    }
}
void printSlowestReport(double costFCFS, double costSSTF, double costScan, double costCScan, int sz)
{
    if (costFCFS < costSSTF && costFCFS < costScan && costFCFS < costCScan) {
        cout << "\n\tFCFS has the fastest speed";
        cout << "\n\tTotal cost: " << costFCFS;
        cout << "\n\tAverage cost: " << costFCFS / sz;
    }
    else if (costSSTF < costFCFS && costSSTF < costScan && costSSTF < costCScan) {
        cout << "\n\tFCFS has the fastest speed";
        cout << "\n\tTotal cost: " << costSSTF;
        cout << "\n\tAverage cost: " << costSSTF / sz;
    }
    else if (costScan < costFCFS && costScan < costSSTF && costScan < costCScan) {
        cout << "\n\tSCAN has the fastest speed";
        cout << "\n\tTotal cost: " << costScan;
        cout << "\n\tAverage cost: " << costScan / sz;
    }
    else {
        cout << "\n\tCScan has the fastest speed";
        cout << "\n\tTotal cost: " << costCScan;
        cout << "\n\tAverage cost: " << costCScan / sz;
    }
}
void printFinalReport(double costFCFS, double costSSTF, double costScan, double costCScan, int sz)
{
    cout << "\n_______________________FINAL REPORT________________________\n\n";
    printFastestReport(costFCFS, costSSTF, costScan, costCScan, sz);
    printSlowestReport(costFCFS, costSSTF, costScan, costCScan, sz);
}
//CScan Scan 

 
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
    ds.setHeader(produceRandom());
    cout << "\nGenerating program successfully...\n\n";
}
void showMenu(){
    cout << "\n--------------------------------DISK SCHEDULE ALGORITHM-----------------------------";
    cout << "\n|\tType your choice to run the algorithm                                       |";
    cout << "\n|\t1.First come first serve algorithm                                          |";
    cout << "\n|\t2.Shortest seeking time algorithm                                           |";
    cout << "\n|\t3.Scan algorithm                                                            |";
    cout << "\n|\t4.C-Scan algorithm                                                          |";
    //cout << "\n|\t5.Look algorithm                                                            |";
    //cout << "\n|\t6.C-Look algorithm                                                          |";
    cout << "\n|\t5.Automatically Run All Program and Compare                                 |";
    cout << "\n|\tType Q to quit program                                                      |";
    cout << "\nType your option...: ";
}