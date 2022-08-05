/*
 * 96A Football
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    int m = 0;
    char prev = s[0];
    vector<int> vi;

    for (auto sitb = s.begin(); sitb < s.end(); sitb++) {
	if (*sitb == prev) {
	    ans++;
	    if (sitb == s.end() - 1) vi.push_back(ans);
	} else {
	    prev = *sitb;
	    vi.push_back(ans);
	    ans = 1;
	}
    }

    for (int i : vi) if (i > m) m = i;

    if (m >= 7) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;


}

