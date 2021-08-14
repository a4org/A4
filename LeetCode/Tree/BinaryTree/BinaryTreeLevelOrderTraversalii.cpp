/*
 * LeetCode 107 Binary Tree Level Order Traversal ii 
 * Medium
 * Shuo Feng
 * 2021.8.1
 */

#include<iostream>
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
    vector<vector<int>> Out_Put;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int level = 0;
        if (root == nullptr) return Out_Put;
        traverse(root, level);
        reverse(Out_Put.begin(), Out_Put.end());
        return Out_Put;
    }
    void traverse(TreeNode* root, int level) {
        if (!root)
            return;
        if (Out_Put.size() <= level)
            Out_Put.push_back(vector<int>{});
        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
        Out_Put[level].push_back(root->val);
    }
};



/*
 * Solution 2 : Bfs
 * 2021.8.14
 */

#include<iostrea>
#include<vector>
#include<queue>

using namespace std
  
  
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>> out_put;
        if(!root) return {}; 

        queue<TreeNode*> Queue; 
        Queue.push(root);
        while(!Queue.empty()){
            int Size = Queue.size();
            vector<int> line;

            for(int i = 1; i<= Size; ++i){
                TreeNode* point = Queue.front();
                Queue.pop();
                line.push_back(point-> val);
                if(point-> left ) Queue.push(point-> left );
                if(point-> right) Queue.push(point-> right);
            }
            out_put.push_back(line);
        }
        
        reverse(out_put.begin(),out_put.end());
        return out_put;
    }
};
