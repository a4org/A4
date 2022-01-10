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
    int A, B, C;

    cin >> A >> B >> C;

    int diff;

    if (B - A == C - B) {
	cout << "YES" << endl;
	return;
    }

    // you cannot change the order of a, b and c !

    // 1. Change A
    diff = C - B;
    // A + diff = B
    // diff = B - A
    if (((B - diff) % A == 0) && B - diff > 0) { // cannot produce 0
	cout << "YES" << endl;
	return;
    }

    // 2. Change B
    // A + diff = B
    if ((C - A)%2 == 0)  {
	diff = (C - A)/2; 
	if (((A + diff) % B == 0) && A + diff > 0) {
	    cout << "YES" << endl;
	    return;
	}
    }

    // 3. Change C
    diff = B - A;
    // A + diff = B
    // B + diff = C
    if (((B + diff) % C == 0) && B + diff > 0) {
	cout << "YES" << endl;
	return;
    }


    cout << "NO" << endl;
}

int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

