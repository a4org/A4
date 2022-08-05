/*
 * 466A Cheap Travel
 * Jiawei Wang
 * 20 May 2021
 */

#include <iostream>

using namespace::std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int ans = 0;
    if (b / m >= a) {
	ans = a * n;
    } else {
	int d =(int) n / m;
	ans = d * b;
	int remain = (n % m);
	if (remain * a < b) {
	    ans += remain * a;
	} else {
	    ans += b;
	}
    }

    cout << ans << endl;
    return 0;
}
