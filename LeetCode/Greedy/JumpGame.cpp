/*
 * LeetCode 55 Jump Game
 * Medium
 * Shuo Feng
 * 2021.8.4
 * Last edited at 2021.9.3 / 2021.10.3
 */


/*
 *   Solution 1:
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
        
        // The requirement of " ++m ":(1) nums[i] != 0;
        //                            (2) nums[i] == 0; but the point before can span over it.
        // So if " m " is equal to the size of nums[], we can  reach the last index
        int m = 0;
        
        // Search 0. 
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == 0) {
                
                for (int j = i; j >= 0; --j) {
                    
                    // The maximum jump length > length ──→ able to reach the place after 0.
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
 *  Solution 2 Dp.
 * Record the most steps, and update in real time.,find the steps that can reach the last index. 
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // The maximum path we can reach
        int step = 0;
        for(int i = 0; i< nums.size(); ++i){
            
            // To updata the maximum path we can reach, (1) the path is longer than before.
            //                                          (2) we can reach the starting point.
            if(nums[i]+i> step && i<= step)  // Update condition
                step = nums[i]+ i;
            if(step>= nums.size()- 1) return true; 
        }
    return false;
    }
};

/*
 * Solution3: 
 *   The better way
 *   Set a point named 'end' place at last number.
 *   Check from back to front, if a index is able to reach 'end', change 'end' as the index.
 *   When 'end' located at the first index, we can reach the last index.
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return true;
        
        int end = size - 1;
        for(int i = end; i >= 0; --i) {
            if(nums[i] >= end - i){
                end = i;
            }
        }
        
        // Condition of able to reach the last index.
        if(end == 0) return true; 
        return false;
    }
};
