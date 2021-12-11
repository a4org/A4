#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
	int n = security.size();
	if (n < time) {
	    return {};
	}

	vector<int> ret;

	if (n == 0) {
	    for (int i = 0; i < n; i++) {
		ret.push_back(i);
	    }
	    return ret;
	}

	vector<int> back;  
	back.push_back(0);

	for (int i = n-2; i >= 0; i--) {
	    if (security[i] <= security[i+1]) {
		back.push_back(back.back() + 1);
	    } else {
		back.push_back(0);
	    }
	}

	reverse(back.begin(), back.end());

	int prev = 0;

	for (int i = 1; i < n; i++) {
	    if (security[i] <= security[i-1]) {
		prev += 1;
	    } else prev = 0;

	    if (prev >= time && back[i] >= time) {
		ret.push_back(i);
	    }
	}
	return ret;
    }
};
