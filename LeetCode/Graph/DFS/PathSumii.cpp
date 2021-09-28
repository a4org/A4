/* 
 * LeetCode 113 Path Sum ii
 * Medium
 * Jiawei Wang
 * 2021.8.22
 */

/* Revision
 * $1 2021.9.28 Jiawei Wang
 */

#include <vector>
#include <deque>
#include <stack>

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
    // #1 BackTracking DFS
    vector<vector<int>> pathSum1(TreeNode* root, int targetSum) {
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
	// BackTracking
	current.pop_back(); // pop root->val (Key statement of BackTracking)
    }

    // #2 Classic DFS (Storage pressure)
    vector<vector<int>> pathSum2(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        dfs(root, {}, 0, targetSum, ans);
        return ans;
    }   
    
    void dfs(TreeNode* node, vector<int> curr, int currVal, int targetSum, vector<vector<int>>& ans) {
        currVal += node->val;
        curr.push_back(node->val); // curr vector
        if (node->left == nullptr && node->right == nullptr && currVal == targetSum) {
            // Termination Condition
            ans.push_back(curr);
        } else {
            if (node->left != nullptr) {
                dfs(node->left, curr, currVal, targetSum, ans);
            }
                
            if (node->right != nullptr) {
                dfs(node->right, curr, currVal, targetSum, ans);
            }
        }
    }

};
