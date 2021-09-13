/*
 * LeetCode 102 Binary Tree Level Order Traversal
 * Medium
 * Shuo Feng
 * 2021 7.31
 * Last edited at 2021.9.13
 */
 
#include<iostream>
#include<vector>
using namespace std;
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
    vector<vector<int>> Out_Put;
    vector<vector<int>> levelOrder(TreeNode* root) {
        int i = 0;
        traverse(root, i);
        return Out_Put;
    }
    void traverse(TreeNode* root, int i) {
        if (!root)
            return;
        if (Out_Put.size() <= i)
            Out_Put.push_back(vector<int>{}); // Add a array for each new line
        Out_Put[i].push_back(root->val);
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
};

/*
 * Solution 2 :Bfs
 * 2021.8.14
 */

/*
 *  Use " Queue " to storage the line to searched.
 *  Each cycles in " while " (line: 65 ) ,delete the line where we are and add the next line to " Queue "
 *
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out_put;
        if(!root) return {}; 

        queue<TreeNode*> Queue;
        Queue.push(root);
        
        while(!Queue.empty()){
            int Size = Queue.size();
            vector<int> line;

            // For nodes in queue (in a line), add nodes on it`s left or right to the tail of queue, after loop, the queue storage the next line.
            for(int i = 1; i<= Size; ++i){
                TreeNode* point = Queue.front();
                Queue.pop();  // Remove
                line.push_back(point-> val);
                if(point-> left ) Queue.push(point-> left );
                if(point-> right) Queue.push(point-> right);
            }
            out_put.push_back(line);
        }
        return out_put;
    }
};
