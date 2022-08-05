/*
 * 1520D Same Differences
 * Jiawei Wang
 * 22 July 2021
 *
 * (aj - ai = j - i) -> (aj - j = ai - i)
 */

#include <iostream>
#include <map>

using namespace::std;

int main() {
    int Times;
    cin >> Times;
    for (int i = 0; i < Times; i++) {
	int N;
	cin >> N;
	map<int, int> freq;
	int pairs = 0;

	for (int i = 0; i < N; i++) {
	    int a;
	    cin >> a; 
	    pairs += freq[a - i]++;
	}

	cout << pairs << endl;
    }
}


