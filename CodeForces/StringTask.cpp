/*
 * 118A String Task
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>
#include <string>

using namespace::std;

int main() {
    string s;
    cin >> s;
    string ans;

    for (char c : s) {
	if ((int)c >= 65 && (int)c <= 90) c = c + 32;

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' | c == 'u' | c == 'y') continue;
	else {
	    ans.push_back('.');
	    ans.push_back(c);
	}
    }


    cout << ans << endl;
    return 0;
}


