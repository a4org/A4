#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <unordered_map>
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
    long N;
    cin >> N;

    vector<long> vi = {};
    int tmp;
    int mx = 0;
    int tmpN = N;
    while (tmpN--) {
	cin >> tmp;
	mx = max(tmp, mx);
	vi.push_back(tmp);
    }

    if (mx < N) {
	cout << "NO" << endl;
	return;
    }

    for (long& li : vi) {
	// put all of them into (0, N)
	while (li > N) {
	    li /= 2;
	}
	// cout << "has: " << li << endl;
    }

    vector<int> nval(N+1, 0);
    nval[0] = -1;

    for (int li : vi) {
	nval[li]++;
	// cout << "insert into nval: " << li << "nval[li] = " << nval[li] << endl;
    }
    

    set<int> finished = {};
    int index = N;
    for (auto rit = nval.rbegin(); rit < nval.rend()-1; rit++) { // ignore 0
	int num = *rit;
	// cout << "deal with " << index << " which has " << num << endl;
	if (num == 0) {
	    cout << "NO" << endl;
	    return;
	}

	if (num == 1 && finished.find(index) == finished.end()) {
	    // a target
	    // cout << "find a target, because only this valid: " << index << endl;
	    finished.insert(index);
	} else {
	    int extranum;
	    if (finished.find(index) != finished.end()) {
		extranum = num;
	    } else {
		// cout << "find a target, since it has multiple, just put the first and find next: " << index << endl;
		extranum = num - 1;
		finished.insert(index);
	    }

	    int tempindex = index;
	    while (tempindex > 1 && extranum > 0) {
		if (nval[tempindex/2]) {
		    // cout << "find a target, but there excists something, so jump " << tempindex/2 << endl;
		    tempindex/=2;
		} else {
		    // find a target
		    extranum--;
		    nval[tempindex/2]++;
		    finished.insert(tempindex/2);
		    // cout << "find a target: " << tempindex/2 << " Now remain: " << extranum << endl;
		    tempindex /= 2;
		}
	    }
	}
	index--;
    }
    // cout << finished.size() << endl;

    if (finished.size() == N) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

