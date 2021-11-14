#include <iostream>
#include <string>
#include <stdio.h>
#include <limits.h>

using namespace::std;

int main() {
    int times;
    string s1; string s2;
    cin >> times;

    for (int i = 0; i < times; i++) {
	cin >> s1; cin >> s2;
	int ret = 0;

	for (char c1 : s1)  {
	    // caculate this char
	    int mn = INT_MAX / 2; // ans of this char
	    for (char c2 : s2) {
		int diff = abs(c1 - c2);
		int i1 = min(diff, 26-diff); 
		mn = min(i1, mn);
	    }
	    ret += mn;
	}
	printf("Case #%i: %i\n", i+1, ret);
    }
    return 0;
}
