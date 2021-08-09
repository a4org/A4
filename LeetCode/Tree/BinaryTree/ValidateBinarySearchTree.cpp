/*
 * LeetCode 98 Validate Binary Search Tree
 * Medium
 * Shuo Feng
 * 2021.8.9
 */

/*
 *   Inorder traverse the bnary tree and record in 'list',if it is a valid binary search tree 
 *  the values in 'list' should be sorted from smallest to largest .
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
    vector<int> list;
    bool isValidBST(TreeNode* root) {
        //if(!root) return true;
        //if(root-> left == nullptr && root-> right == nullptr) return true;

        traverse(root);
        for(int i = 1; i< list.size(); ++i){
                if(list[i]<= list[i- 1]) return false;
        }
    return true;    
    }
    void traverse(TreeNode* root){
        if(root){
            traverse(root-> left );   //Inorder traversal
            list.push_back(root-> val);
            traverse(root-> right);
        }
        else return;
    }

};
