#include "Scan_algorithm.h" 
void Scan_algorithm::runAl(DiskScheduling* disk)  {
	vector<int> originalCylinder = disk->getCyliaders();
	cout << "\nThe original data request: ";
	for (int i = 0; i < originalCylinder.size() - 1; i++) {
		cout << originalCylinder.at(i) << " -> ";
	}
	cout << originalCylinder.back();
	////START: 100, 26, 27, 28, 4, 5, 6
	////start with 13 
	////GOAL: 26,27,28,100,6,5,4
	//// 	   
	////on the right side , smallest -> got the value
	////new vector result -> push back (the value) 
	int oriHeader = disk->getHeader();
	vector<int> bigger, smaller;
	for (auto x : originalCylinder) {
		if (x > oriHeader) {
			bigger.push_back(x);
		}
	}
	for (auto x : originalCylinder) {
		if (x < oriHeader) {
			smaller.push_back(x);
		}
	}
	 sort(bigger.begin(), bigger.end(),less<int>());//ascending order 26,27,28,100
	 sort(smaller.begin(), smaller.end(), less<int>()); //ascending order 6,5,4
	 vector<int> result;
	 for (auto x : bigger) {
		 result.push_back(x);
	 }
	 for (auto x : smaller) {
		 result.push_back(x);
	 }
	 //print it out
	 cout << "\nThe path algorithm will run: ";
	 for (int i = 0; i < result.size() - 1; i++) {
		 cout << result.at(i) << " -> ";
	 }
	 cout << result.back();
	 
};
 