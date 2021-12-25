#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
	int ret = 0;
	for (auto s : sentences) {
	    int curr = 0;
	    for (auto c : s) {
		if (c == ' ') curr++;
	    }
	    ret = max(curr, ret);
	}

	return ret;
    }
};
