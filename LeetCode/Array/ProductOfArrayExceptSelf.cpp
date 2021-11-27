/*
 * LeetCode 238 Product of Array Except Itself
 * Medium
 * Jiawei Wang
 * 2021.11.27
 */

#include <vector>

using namespace::std;

class Solution {
    // #1 Divide (brute force)
    vector<int> productExceptSelf(vector<int>& nums) {
	int ct = 0;
	int total = 1;

	for (auto n : nums) {
	    // build the ans 
	    if (n == 0) {
		ct++;
		if (ct == 2) break;
	    } else {
		total *= n;
	    }
	}

	if (ct == 2) {
	    vector<int> ret(nums.size(), 0);
	    return ret;
	}

	vector<int> ret;

	if (ct == 1) {
	    for (auto n : nums) {
		if (n == 0) ret.push_back(total);
		else ret.push_back(0);
	    }
	    return ret;
	}

	for (auto n : nums) {
	    // calc the ans
	    ret.push_back(total/n);
	}
	return ret;
    }


    // #2 Prefix Sum
    vector<int> productExceptSelf2(vector<int>& nums) {
	const int n = nums.size();
	vector<int> pref_product;
	pref_product.push_back(1);

	for (int x : nums) {
	    pref_product.push_back(pref_product.back() * x);
	}

	vector<int> suf_product(n+1);
	suf_product[n] = 1;
	for (int i = n-1; i >=0; --i) {
	    suf_product[i] = suf_product[i+1] * nums[i];
	}

	vector<int> ret(n);

	for (int i = 0; i < n; i++) {
	    ret[i] = pref_product[i] * suf_product[i+1];
	}
	return ret;
    }
};


