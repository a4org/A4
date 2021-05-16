/*
 * 263A Beautiful Matrix
 * Jiawei Wang
 * 16 May 2021
 */

#include <iostream>

using namespace::std;

int main() {
    int ans;
    int col; int row;
    for (int i = 1; i <= 5; i++) {
	for (int j = 1; j <= 5; j++) {
	    int element;
	    cin >> element;
	    if (element) {
		col = j;
		row = i;
		break;
	    }
	}
    }
    ans = abs(row - 3) + abs(col - 3);
    cout << ans;
    return 0;
}

