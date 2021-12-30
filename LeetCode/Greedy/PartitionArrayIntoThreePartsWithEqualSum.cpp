/*
 * LeetCode 1013 Partition Array Into Three Parts With Equal Sum
 * Easy
 * Jiawei Wang
 * 2021.12.30
 */

#include <vector>

using namespace::std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
	int sum = 0;
	for (auto a : arr) {
	    sum += a;
	}

	if (sum % 3) return false;
	int target = sum / 3;

	int curr = 0; 
	int ns = -1; // next start
	for (int i = 0; i < arr.size(); i++) {
	    curr += arr[i];
	    if (curr == target) {
		ns = i;
		break;
	    }
	}

	if (ns == -1) return false;
	curr = 0;
	for (int i = ns+1; i < arr.size(); i++) {
	    curr += arr[i];
	    if (curr == target && i != arr.size()-1) return true;
	}

	return false;
    }
};
