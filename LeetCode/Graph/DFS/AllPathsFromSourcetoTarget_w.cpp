/* 
 * LeetCode 797 All Paths From Source to Target
 * Medium
 * Jiawei Wang
 * 2021.11.28
 */


#include <vector>


using namespace::std;

#define vvi vector<vector<int>>
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vvi& graph) {
	// DFS + BackTracking
	vvi ret = {};
	vector<int> curr = {};

	curr.push_back(0);
	helper(graph, ret, curr, 0);

	return ret;
    }

private:
    // Pass Referece! Even though you do not need to change the graph
    void helper(vvi& graph, vvi& ret, vector<int>& curr, int cn) {
	// Do DFS
	if (cn == graph.size()-1) {
	    // Termination Condition
	    ret.push_back(curr);
	    return;
	}

	for (int i = 0; i < graph[cn].size(); i++) {
	    curr.push_back(graph[cn][i]);
	    helper(graph, ret, curr, graph[cn][i]);
	    // BackTracking
	    curr.pop_back();
	}
    }
};

