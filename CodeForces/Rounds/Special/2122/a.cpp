#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main() {
    int N = 0; cin >> N;

    for (int n = 0; n < N; n++) {
	int C; cin >> C;
	if (C == 1) {
	    cout << 1 << endl;
	    continue;
	}
	vector<int> curr = {};
	// build the array
	for (int c = 0; c < C; c++) {
	    int num; cin >> num;
	    curr.push_back(num);
	}

	for (auto& ic : curr) {
	    if (ic < 0) ic = -ic;
	}

	sort(curr.begin(), curr.end());

	int prev = curr[0];
	int largestdup = -1;
	int ans = 1;
	for (int i = 1; i < curr.size(); i++) {
	    int current = curr[i];
	    if (current != prev) {
		ans++;
	    } else if (current == prev && current != largestdup && prev != 0) {
		// first time
		largestdup = current;
		ans++;
	    } 
	    prev = current;
	}
	cout << ans << endl;
    }
}
