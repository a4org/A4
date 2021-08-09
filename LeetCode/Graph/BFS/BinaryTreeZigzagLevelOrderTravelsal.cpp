/* 
 * LeetCode 103 Binary Tree Zigzag Level Order Traversal
 * Medium
 * Jiawei Wang
 * 2021.8.9
 */


/*
 * #1 BFS
 * Think Simple (Two cases)
 * using deque
 *
 *
 * #2 DFS
 */

#include <algorithm>
#include <vector>
#include <deque>

using namespace::std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    // #1 BFS
    vector<vector<int>> zigzagLevelOrder1(TreeNode *root) {
	if (!root) return {};
	vector<vector<int>> ans;

	deque<TreeNode*> q;
	q.push_back(root);

	int d = 0;

	while (q.size()) {

	    ans.push_back({});    
	    auto cur = &ans.back();
	    deque<TreeNode*> next;
	    while (q.size()) {

	        if (d % 2) {
		   // right and back
	            TreeNode* node = q.back();
	            q.pop_back();
	            cur->push_back(node->val);
	            if (node->right) next.push_front(node->right);
	            if (node->left) next.push_front(node->left);          
		} else {
		// left and front
	            TreeNode* node = q.front();
	            q.pop_front();
	            cur->push_back(node->val);
	            if (node->left) next.push_back(node->left);
	            if (node->right) next.push_back(node->right);          
		}
	  }
	  ++d;
	  q.swap(next);
	}
	return ans;
      }


    // #2 DFS 
    vector<vector<int>> zigzagLevelOrder2(TreeNode *root) {
	vector<vector<int>> ans;
	function<void(TreeNode*, int)> dfs = [&](TreeNode* r, int d) {
	    if (!r) return;

	    // d means depth (level)
	    while (ans.size() < d) ans.push_back( {} );
	    ans[d].push_back(r->val);

	    dfs(r->right, d + 1);
	    dfs(r->left, d + 1);
	};
	
	dfs(root, 0);
	for (int i = 0; i < ans.size(); i+=2) 
	    reverse(begin(ans[i]), end(ans[i]));

	return ans;
    }

};
