#include <algorithm>
#include <array>
#include <unordered_map>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

#ifdef DEBUG
    #define debug(args...)            {dbg, args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr << v << " ";    
        return *this;    
    }
} dbg;

void run_case() {
    vector<int> elements = {};
    int NUM;
    cin >> NUM;

    int temp;
    while (NUM--) {
	cin >> temp;
	elements.push_back(temp);
    }

    vector<int> cpele = elements;
    sort(cpele.begin(), cpele.end());
    auto it = unique(cpele.begin(), cpele.end());
    if (it == cpele.end()) {
	cout << -1 << endl;;
	return;
    }

    unordered_map<int, vector<int>> numidx;
    int n = elements.size();

    for (int i = 0; i < n; i++) {
	// build the num with its index
	numidx[elements[i]].push_back(i+1);
    }

    int ret = 1;
    // deal with the index

    for (pair<int, vector<int>> idxs : numidx) {
	vector<int> appear = idxs.second;
	if (appear.size() == 1) continue; // do not care
	int idx = idxs.first;
	// assume this idx is the ith we want

	cout << "deal with: " << idx << endl;
	int an = appear.size();
	for (int i = 0; i < an; i++) {
	    int prv = appear[i]; 
	    // find all subsequence
	    for (int j = i+1; j < an; j++) {
		cout << "handle i:" << i << ", j:" << j << endl;
		int later = appear[j];
		int diff = later - prv;

		if ((later-prv) < ret) continue; // do not need

		int beg2prv = prv;
		int later2end = n - later;

		int tmpans = 0;
		if (diff < later2end) {
		    // can get a valid ans
		    tmpans = tmpans + diff + min(beg2prv, diff) + later2end - diff;
		    ret = max(ret, tmpans);
		    cout << "temp ans: " << tmpans << endl;
		} else {
		    cout << "cannot get a valid temp ans" << endl;
		    // not match
		    continue;
		}
	    }
	}
    }

    cout << ret << endl;
}


int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

