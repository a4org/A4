/*
 * 50A Domino Piling
 * Jiawei Wang
 * 15 May 2021
 */

#include <iostream>

using namespace::std;

int main() {
    int m, n;
    cin >> m >> n;

    if (m < n) {
	int temp = m;
	m = n;
	n = temp;
    }

    int l = m / 2;
    int ans = l * n;

    if (m % 2 != 0) ans += (int)(n/2);

    cout << ans;

    return 0;

}
