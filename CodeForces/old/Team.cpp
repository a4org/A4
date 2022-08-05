/*
 * 231A Team
 * Jiawei Wang
 * 15 May 2021
 */

#include <iostream>
#include <string>

using namespace::std;

int main() {
    int	n = 0;
    int ans = 0;

    cin >> n;
    cin.ignore();
    for (int i=0; i < n; i++) {
	string s;
	int temp= 0;
	getline(cin, s);
	for (char c : s) {
	    if (c == '1') temp++;
	}
	if (temp >= 2) ans++;
    }
    cout << ans;
}
