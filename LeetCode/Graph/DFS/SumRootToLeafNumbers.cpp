#include <vector>
#include <iostream>

using namespace::std;


// Definition for a binary tree node.
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
    int sumNumbers(TreeNode* root) {
        // DFS + BackTracking
        int ret = 0;
        vector<int> curr, currSum;
	currSum.push_back(0);
        helper(root, ret, curr, currSum);
        return ret;
    }
private:
    void helper(TreeNode* root, int& ret, vector<int>& curr, vector<int>& currSum) {
        if (root == nullptr) {
            // Termination Condtion #1
            return;
        }
        
        curr.push_back(root->val);
        currSum.push_back(currSum.back()*10 + root->val);
        if (root->left == nullptr && root->right == nullptr) {
            // got one answer
            ret += currSum.back();
            curr.pop_back();
            currSum.pop_back();
            return;
        } 
        
        if (root->left != nullptr) {
            helper(root->left, ret, curr, currSum);
        }
        
        if (root->right != nullptr) {
            helper(root->right, ret, curr, currSum);
        }
        
        curr.pop_back();
        currSum.pop_back();
        return; 
    }
};
