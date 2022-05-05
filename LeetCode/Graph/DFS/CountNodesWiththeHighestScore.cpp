/* 
 * LeetCode 2049 Count Nodes With the Highest Score
 * Medium
 * Jiawei Wang
 * 2022.5.5
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace::std;
using LL = long long;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
      // dfs (binary tree)
      int n = parents.size();
      vector<vector<int>> nodes(n, vector<int>());
      unordered_map<int, int> counts = {};

      for (int i = 0; i < n; i++) {
	childsize[i] = 0;
	counts[i] = 0;
	if (parents[i] == -1) continue; // the root node
	// parents[i] is the parent of node i
	nodes[parents[i]].push_back(i);
      }

      helper(nodes, 0);

      int mx = 0;
      for (int i = 0; i < childsize.size(); i++) {
	// assume we remove the current node
	int val = 1;
	int num = 0;
	for (int j = 0; j < nodes[i].size(); j++) {
	  // the answer is the left and right
	  num += childsize[nodes[i][j]];
	  val *= childsize[nodes[i][j]];
	}
	int tmp = n - num - 1;
	if (tmp) val *= tmp;
	mx = max(mx, val);
	counts[val] ++;
      }

      return counts[mx];
    }

private:
    // store each size of subtree
    unordered_map<int, int> childsize;

    int helper(vector<vector<int>> nodes, int index) {
      // return the current sub tree size (i as the root)
      vector<int> childs = nodes[index];
      int size = 1;
      if (childs.size() == 0) {
	// reach the leaf
	// Termination Condition
	childsize[index] = 1;
	return 1;
      }

      for (int i = 0; i < childs.size(); i++) {
	int tmp = helper(nodes, childs[i]);
	size += tmp;
	childsize[index] = size;
      }

      return size;
    }
};

