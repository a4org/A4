/*
 * 270A Fancy Fence
 * Jiawei Wang
 * 19 May 2021
 */

#include <iostream>
#include <vector>

using namespace::std;

int main() {
    int num;
    cin >> num;

    vector<int> vi;
    for (int i = 0; i < num; i++) {
	int degree;
	cin >> degree;
	vi.push_back(degree);
    }

    // The sum of all angles of a regular polygon:
    // sum = (n - 2) * 180

    for (int d : vi) {
	float x = 360.0 / (180 - d);
	int ix = x / 1;
	float y = x - ix;
	if (y != 0) {
	    cout << "NO" << endl;
	} else {
	    cout << "YES" << endl;
	}
    }

}
