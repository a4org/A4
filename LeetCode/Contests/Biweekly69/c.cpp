#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace::std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
	unordered_map<string, int> wc = {};
	bool odd = false;
	int ret = 0;
	int mp = 0;

	for (auto word : words) {
	    wc[word]++;
	}

	for (pair<string, int> pr : wc) {
	    if (ispal(pr.first)) {
		if (!odd && pr.second % 2) {
		    // odd
		    mp += pr.second;
		    odd = true;
		} else if (pr.second % 2 == 0) {
		    mp += pr.second;
		} else if (pr.second %2) {
		    mp += pr.second - 1;
		}
	    } else if (pr.second != -1) {
		if (wc.find(rev(pr.first)) != wc.end()) {
		    ret += min(pr.second, wc[rev(pr.first)]);
		    wc[pr.first] = -1;
		    wc[rev(pr.first)] = -1;
		}
	    }
	}

	return ret*4 + mp*2;

    }

private:
    bool ispal(string s) {
	return s[0] == s[1];
    }

    string rev(string s) {
	string rever = "";
	return rever + s[1] + s[0];
    }
};
