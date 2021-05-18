/*
 * 158B Taxi
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace::std;

int main() {
    int num;
    cin >> num;

    vector<int> needCars;
    for (int i = 0; i < num; i++) {
	int group;
	cin >> group;
	needCars.push_back(group);
    }

    sort(needCars.begin(), needCars.end());
    vector<int>::iterator vib = needCars.begin();
    vector<int>::iterator vie = needCars.end()-1;
    while (vib != vie) {
	if (*vib + *vie <= 4) {
	    *vie += *vib;
	    vib = needCars.erase(vib);
	} vie--;
	cout << endl;
    }

    cout << needCars.size() << endl;
    return 0;
}

