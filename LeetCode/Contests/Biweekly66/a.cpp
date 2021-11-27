#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    // Brute Force
    int countWords(vector<string>& words1, vector<string>& words2) {
	unordered_map<string, int> wm1(0); // word map
	unordered_map<string, int> wm2(0);

	int ret = 0;
	for (auto word : words1) {
	    wm1[word]++;
	}

	for (auto word : words2) {
	    wm2[word]++;
	}

	for (pair<string, int> e1 : wm1) {
	    if (e1.second == 1 && wm2.count(e1.first) && (*wm2.find(e1.first)).second == 1) {
		ret++;
	    }
	}

	return ret;
    }
};
