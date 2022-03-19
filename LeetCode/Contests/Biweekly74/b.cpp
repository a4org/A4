#include <string>
#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
	// abdcdbc
	char p0 = pattern[0];
	char p1 = pattern[1];

	string tmptext = "";
	for (auto it = text.begin(); it != text.end(); it++) {
	    // purify the string
	    if (*it == p0 || *it == p1) tmptext.push_back(*it);
	}

	text = tmptext;


	if (text.size() == 0) return 0;
	if (text.size() == 1) return 1;

	long long np0 = 0;
	long long np1 = 0;
	vector<long long> vnp0 = {};
	vector<long long> vnp1 = {};

	if (text[0] == p0) vnp0.push_back(1);
	else vnp0.push_back(0);

	// count reverse
	if (text[text.size()-1] == p1) vnp1.push_back(1);
	else vnp1.push_back(0);

	// p0
	for (int i = 1; i < text.size(); i++) {
	    if (text[i] == p0) {
		vnp0.push_back(vnp0[i-1] + 1);
	    } else {
		vnp0.push_back(vnp0[i-1]);
	    }
	}

	// p1
	for (int i = text.size() - 2; i >= 0; i--) {
	    if (text[i] == p1) {
		vnp1.push_back(vnp1[text.size() - 2 - i] + 1);
	    } else {
		vnp1.push_back(vnp1[text.size() - 2 - i]);
	    }
	}

	long long ret = INT_MIN;

	for (int i = 0; i < text.size()-1; i++) {
	    p0 = vnp0[i];
	    p1 = vnp1[text.size() - 2 - i];
	    ret = max<long long>(ret, max<long long>((p0 + 1) * p1, p0 * (p1 + 1)));
	}

	return ret;
    }
};

int main() {
    Solution* Sol = new Solution();

    Sol->maximumSubsequenceCount("abdcdbc", "ac");
}
