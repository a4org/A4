#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	unordered_set<int> d1 = {};
	unordered_set<int> d2 = {};

	for (int i = 0; i < nums1.size(); i++) d1.insert(nums1[i]);

	for (int j = 0; j < nums2.size(); j++) d2.insert(nums2[j]);

	vector<int> r1 = {};
	vector<int> r2 = {};

	for (auto it1 = d1.begin(); it1 != d1.end(); it1++) {
	    int tmp = *it1;
	    if (d2.find(tmp) == d2.end()) r1.push_back(tmp);
	}

	for (auto it2 = d2.begin(); it2 != d2.end(); it2++) {
	    int tmp = *it2;
	    if (d1.find(tmp) == d1.end()) r2.push_back(tmp);
	}

	vector<vector<int>> ret = {r1, r2};

	return ret;
    }
};

