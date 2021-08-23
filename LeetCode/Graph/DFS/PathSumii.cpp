/* 
 * LeetCode 113 Path Sum ii
 * Easy
 * Jiawei Wang
 * 2021.8.23
 */

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


deque<int> current;
vector<int> tmp;
vector<vector<int>> ans;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	dfs(root, targetSum);
	return ans;
    }

    void dfs(TreeNode* root, int targetSum) {
	if (root == nullptr) {
	    return;
	} else {
	    targetSum -= root->val;
	}


	current.push_back(root->val);

	dfs(root->left, targetSum);
	dfs(root->right, targetSum);

	if (root->right == nullptr && root->left == nullptr && targetSum == 0)  {
	    ans.push_back({});
	    for (auto s : current) {
		ans.back().push_back(s);
	    }
	}
	current.pop_back();
    }

    void dfs2(TreeNode* root, int targetSum) {
	// using vector
	if (root == nullptr) {
	    return;
	} else {
	    targetSum -= root->val;
	}

	tmp.push_back(root->val);

	dfs(root->left, targetSum);
	dfs(root->right, targetSum);

	if (root->right == nullptr && root->left == nullptr && targetSum == 0)  {
	    ans.push_back(tmp);
	}
	tmp.pop_back();
    }
};
