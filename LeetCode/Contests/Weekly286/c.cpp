#include <vector>
#include <string>

using namespace::std;

using LL = long long;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
	int hl = intLength/2;
	int total = (hl%2) ? hl*90 : (hl-1)*90;

	vector<LL> ret = {};

	for (int i = 0; i < queries.size(); i++) {
	    int tmp = queries[i];
	    if (tmp > total) {
		ret.push_back(-1);
		continue;
	    }
	}
    }

private:
    LL helper(int idx, int total, int len) {
	string target = "";
	for (int i = 0; i < len/2 + 1; i++) {

	}
    }
};
