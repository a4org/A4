/*
 * 489B BerSU Ball
 * Jiawei Wang
 * 20 May 2021
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

int main() {
    int numb, numg;

    cin >> numb;
    vector<int> boys, girls;
    for (int i = 0; i < numb; i++) {
	int b;
	cin >> b;
	boys.push_back(b);
    }

    cin >> numg;
    for (int i = 0; i < numg; i++) {
	int g;
	cin >> g;
	girls.push_back(g);
    }

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    for (int b : boys) {
	for (auto g = girls.begin(); g != girls.end(); g++) {
	    if (b - *g == 1 || *g - b == 1){
		girls.erase(g);
		break;
	    } 
	    if (*g == b) {
		girls.erase(g);
		break;
	    }
	    
	}
    }
    cout << numg - girls.size() << endl;
    return 0;
}
