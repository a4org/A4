#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
      vector<int> tmpnum = nums;
      sort(tmpnum.begin(), tmpnum.end());
      tmpnum.erase(unique(tmpnum.begin(), tmpnum.end()), tmpnum.end());

      vector<int> rets = {};

      for (int n : tmpnum) {
	for (int i = 0; i < numsDivide.size(); i++) {
	  int num = numsDivide[i];
	  if (num % n != 0) {
	    break;
	  }

	  if (i == numsDivide.size()-1) {
	    rets.push_back(n);
	  }
	}
      }

      if (rets.size() == 0) return -1;

      sort(rets.begin(), rets.end());

      int target = rets[0];

      int ret = 0;
      for (int num : nums) {
	if (num < target) {
	  ret++;
	}
      }

      return ret;
    }
};
