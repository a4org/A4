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
    int rooks; int size;
    cin >> size >> rooks;
    
    if (rooks > (size+1)/2) {
	cout << -1 << '\n';
	return;
    }

    for (int i = 0; i < size; i++) {
	string line = "";
	for (int j = 0; j < size; j++) {
	    if (j == i && !(j % 2) && rooks) {
		line+='R';
		rooks--;
	    } else line+='.';
	}
	cout << line << '\n';
    }
}

int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

