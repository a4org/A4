/*
 * 1520A Same Differences
 * Jiawei Wang
 * 22 July 2021
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace::std;

void run_case() {
    int N;
    string S;
    cin >> N >> S;
    string sorted = S;
    sort(sorted.begin(), sorted.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    cout << (S.size() == sorted.size() ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
	run_case();
    }
    return 0;
}
