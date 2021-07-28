/*
 * LeetCode 112 Path Sum
 * easy
 * Shuo Feng
 * 2021.7.28
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr )
            return false;
        else 
            targetSum -= root-> val;
       
        if(targetSum == 0 && root-> left == nullptr && root-> right ==nullptr)
            return true;         
                   
        else if(targetSum != 0 && root-> left != nullptr || root-> right !=nullptr) {
                bool OutPut_1 = hasPathSum(root-> left, targetSum);
                if(OutPut_1 == 1){
                    return true;
                }    
                else{
                    bool OutPut_2 = hasPathSum(root-> right, targetSum);
                    if(OutPut_2 == 1)
                        return true;
                    else
                        return false;
                }
            }
        else 
            return false;  
    }
    
};
