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


void run_case() {
    int N, M, RB, CB, RD, CD;
    string s = "";

    cin >> N >> M >> RB >> CB >> RD >> CD;

    RB--; CB--; RD--; CD--;

    auto r_valid = [&](int r) -> bool {
	return 0 <= r && r < N;
    };
    auto c_valid = [&](int c) -> bool {
	return 0 <= c && c < M;
    };

    int dr = 1, dc = 1;
    int steps = 0;

    while (true) {
	if (RB == RD || CB == CD) {
	    cout << steps << '\n';
	    return;
	}

	if (!r_valid(RB + dr))
	    dr *= -1;
	RB += dr;

	if (!c_valid(CB + dc)) 
	    dc *= -1;
	CB += dc;
	steps++;
    }
}

int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

