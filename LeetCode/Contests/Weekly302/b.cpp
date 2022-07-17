#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
      // key: get sum of digits

      unordered_map<int, int> psd = {};
      unordered_map<int, vector<int>> sumdv = {};

      for (int n : nums) {
	int sod = helper(n);
	psd[sod] += 1;

	sumdv[sod].push_back(n);
      }

      int ret = 0;

      for (auto ps : psd) {
	if (ps.second >= 2) {
	  vector<int> rets = sumdv[ps.first];
	  sort(rets.begin(), rets.end());
	  ret = max(ret, rets[rets.size() - 1] + rets[rets.size() - 2]);
	}
      }

      if (ret) return ret;
      return -1;
    }

    int helper(int num) {

      int sum = 0;

      while (num / 10) {
	sum += num % 10;
	num /= 10;
      }

      sum += num;

      return sum;
    }
};
