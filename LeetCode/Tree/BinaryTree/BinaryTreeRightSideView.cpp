/*
 * LeetCode 199 Binary Tree Right Side View
 * Medium
 * Shuo Feng
 * 2021.8.8
 */

#incldue<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
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
    vector<int> out_put;
    vector<int> rightSideView(TreeNode* root) {
        int place = 0;
        dfs(root, place);
        return out_put;
    }
    void dfs (TreeNode* root, int place){
        if(!root) return;
        
        if(place>= out_put.size()) out_put.push_back(root-> val);
        dfs(root-> right, place+ 1);
        dfs(root-> left , place+ 1);
        return;
    }
};
