#include <vector>
#include <iostream>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
	vector<vector<int>> nodes(n);
	for (auto edge : edges) {
	    nodes[edge[1]].push_back(edge[0]);
	}

	for (int i = 0; i < nodes.size(); i++) {
	    vector<int> node = nodes[i];
	    helper(node, nodes, i);
	    vector<int>* finished = &nodes[i];
	    sort(finished->begin(), finished->end());
	    finished->erase(unique(finished->begin(), finished->end()), finished->end());
	}

	return nodes;
    }

private:
    void helper(vector<int> node, vector<vector<int>>&nodes, int index) {
	if (node.size() == 0) 
	    // Termination condition
	    return;

	vector<int> next = {};
	for (int i = 0; i < node.size(); i++) {

	    int n = node[i];
	    if (nodes[n].size() != 0) {
		// still need to be deal with
		for (int ne : nodes[n]) {
		    nodes[index].push_back(ne);
		    next.push_back(ne);
		}
	    }
	}

	helper(next, nodes, index);
    }
};
