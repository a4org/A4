#include <algorithm>
#include <array>
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
    int NUM, nbits;
    cin >> NUM >> nbits;

    // bit by bit
    vector<int> bitcount(nbits, 0);

    int tempnum;
    int signb; // current bit
    int half = NUM/2;
    while (NUM--) {
	cin >> tempnum;

	// cout << "dealing with: " << tempnum << endl;
	for (int i = 0; i < nbits; i++) {
	    if ((tempnum/2)*2 == tempnum) {
		// has 0
		// cout << tempnum << " " << i << " has 0" << endl;
		signb = 0;
	    } else {
		// cout << tempnum << " " << i << " has 1" << endl;
		signb = 1;
	    }

	    bitcount[i] += signb;
	    tempnum /= 2;

	    if (!tempnum) {
		break;
	    }
	}
    }

    /*
    for (auto i : bitcount) cout << i << " ";
    cout << endl;
    */

    int ans = 0;;
    for (int i = 0; i < nbits; i++) {
	int numof1 = bitcount[i]; // num of 1
	// cout << "numof1: " << numof1 << " i: " << i << endl;
	if (numof1 > half) ans += pow(2, i);
    }

    cout << ans << endl;
}


int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

