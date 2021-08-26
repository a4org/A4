/*
 * LeetCode 403 Frog Jump
 * Hard
 * Jiawei Wang
 * 2021 8.26
 */

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace::std;

class Solution {
    unordered_set<int> stoneSet; // all valid stone positions
    set<pair<int, int>> failed;
public:
    // #1 Hash + DFS (recursion)
    bool canCross(vector<int>& stones) {
	for (auto x : stones) 
	    stoneSet.insert(x);

	return dfs(stones, 0, 0);
    }

    bool dfs(vector<int>& stones, int pos, int jump) {
	// dfs will return whether the frog can cross the river
	// when it at position "pos" with the jump distance (jump +- 1)
	
	if (pos == stones.back()) return true; // end condition (cross the river successfully)

	if (stoneSet.find(pos) == stoneSet.end()) return false;
	if (failed.find({pos, jump}) != failed.end()) return false; // speed up

	// three situation
	if (jump > 1 && dfs(stones, pos+jump-1, jump-1)) {
	    return true;
	} 
	if (jump > 0 && dfs(stones, pos+jump, jump)) {
	    return true;
	}
	if (dfs(stones, pos+jump+1, jump+1)) {
	    return true;
	}

	failed.insert({pos, jump});
	return false;
    }
};
