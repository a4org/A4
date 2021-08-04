/*
 * LeetCode 55 Jump Game
 * Medium
 * Shuo Feng
 * 2021.8.4
 */


/*
 *   Solution 1
 *  If 'nums' not included '0'(apart from last index), the last index can be reached.
 *  When there`s '0' in 'nums', to reach the last index ,indexes before '0' should be able to reach the index after '0'.
 */


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //int size = nums.size();
        if (nums.size() == 1) return true;
        int m = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == 0) {
                for (int j = i; j >= 0; --j) {
                    if (nums[j] > (i - j)) {
                        m += 1;
                        break;
                    }
                }
            }
            else
                m += 1;
        }
        if (m == nums.size() - 1) return true;
        else return false;
    }
};


/*
 *  Solution 2, the better way.
 * Record the most steps, and update in real time.,find the steps that can reach the last index. 
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 0;
        for(int i = 0; i< nums.size(); ++i){
            if(nums[i]+i> step && i<= step)  // Update condition
                step = nums[i]+ i;
            if(step>= nums.size()- 1) return true; 
        }
    return false;
    }
};
