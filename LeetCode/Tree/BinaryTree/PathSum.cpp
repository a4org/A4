/*
 * LeetCode 112 Path Sum
 * easy
 * Shuo Feng
 * 2021.7.28
 * Last edited at 2021.8.29
 */


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr )
            return false;
        else 
            targetSum -= root-> val;
       
        if(targetSum == 0 && root-> left == nullptr && root-> right ==nullptr)  // End condition.
            return true;         
                   
        else if(targetSum != 0 && root-> left != nullptr || root-> right !=nullptr) { 
                bool OutPut_1 = hasPathSum(root-> left, targetSum);  // Search left subtree
                if(OutPut_1 == 1){                                   // Judge the result, same as line 42
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


/*
 *The better way:
 *Shuo Feng
 *2021.7.29
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr )
            return false;
        else 
            targetSum -= root-> val;
       
        if(targetSum == 0 && (root-> left == nullptr && root-> right ==nullptr) )  //The end condition.
            return true;         
 
        return hasPathSum(root-> left, targetSum)               // If not finished, cheack left and right subtree.
            || hasPathSum(root-> right, targetSum);             // as same as : if(hasPathSum(root-> left, targetSum))
                                                                //                  return hasPathSum(root-> left, targetSum);
    }                                                           //              else if... 
};                                                              // 
