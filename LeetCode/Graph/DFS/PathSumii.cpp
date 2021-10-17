/* 
 * LeetCode 113 Path Sum ii
 * Medium
 * Jiawei Wang
 * 2021.8.22
 */

/* Revision
 * $1 2021.9.28 Jiawei Wang
 * $2 2021.10.17 Jiawei Wang
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
    // We passing a gloal variable or passing reference current for iteration 
    // Reduce the storiage pressure
    vector<vector<int>> pathSum1(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        vector<int> current;
        helper1(root, ret, current, targetSum);
        
        return ret;
    }
private:
    void helper1(TreeNode* root, vector<vector<int>>& ret, vector<int>& current, int targetSum) {
        if (root == nullptr) return;
        
        targetSum -= root->val;
        current.push_back(root->val);
        
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
            // Termination Condition
            ret.push_back(current);
        }
        
        helper1(root->left, ret, current, targetSum);
        helper1(root->right, ret, current, targetSum);
        
        current.pop_back(); // remember pop back each layers
    }

public:
    // #2 Classic DFS (Storage pressure)
    vector<vector<int>> pathSum2(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        
        helper2(root, ret, {}, targetSum);
        
        return ret;
    }

private:
    void helper2(TreeNode* root, vector<vector<int>>& ret, vector<int> current, int targetSum) {
        if (root == nullptr) return;
        
        targetSum -= root->val;
        current.push_back(root->val);
        
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
            // Termination Condition
            ret.push_back(current);
            return;
        }
        
        helper2(root->left, ret, current, targetSum);
        helper2(root->right, ret, current, targetSum);
    }
};
