/*
 * LeetCode 300 Longest Increasing Subsequence
 * Medium
 * Shuo Feng
 * 2021.8.25
 * Last edited at 2021.9.14
 */

/*
 * Solution 1 Dp
 * 
 *   Use " max_size " to stand the longest increasing subsequense to place " i ", each time check the number before " i "(check place " j "),
 *  if " nums[i] " is the bigger one, increasing subsequence is founding, choose the bigger one between " max_size[i] " and " max_size[j] + 1 "
 *  as the longest length to place " i ".
 *
 *   The reason why search the place befor " i ":
 *  In Dp we should judge the situation acording to the conditions we have known, " max_size[] " after place " i " still need judgement.
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 1;
        if (size < 1) return 0;

        vector<int> max_size(size, 0);
        
        for (int i = 0; i < size; ++i) {
            max_size[i] = 1;  // Initial case of each points

            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    max_size[i] = max(max_size[j] + 1, max_size[i]);
                }
            }
        }
        // Get the maximum one
        int p = INT_MIN;
        for (int i = 0; i < size; ++i)
            p = max(p, max_size[i]);
        return p;
    }
};
ea

/*
 * Solution 2: Dichotomy and Greedy.
 * 2021.9.24
 *   Record numbers in " nums " from small to large to a array, in order to storage the most numbers, each number in array
 *  needs to be as small as possible .
 *
 *   Use " Length[i] " to storage the maximum number of increasing subsequence in size i, creat this array start with len 1 (length[1]), 
 *  compare with " nums " from head to tail, if nums[x] bigger than the maximum value in " Length ", add nums[x] to the place
 *  after " Length[len] " and increase len, when nums[x] is smaller, find the first element in " Length " which is smaller than nums[x]
 *  and replace the element after it as nums[x].
 *
 *   As the result, the final len is the size of longest increasing subsequence, the " Length " does not necessarily storage the longest 
 *  increasing subsequence, but it`s no matter.
 * 
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        
        int len = 1; // Begin with size 1.
        vector <int> Length(size + 1, 0);
        Length[len] = nums[0]; // Starting situation.

        for (int i = 1; i < size; ++i) {
        
            // Only increase len when add new element.
            if (nums[i] > Length[len]) {
                len += 1;
                Length[len] = nums[i];

            }
            else {
                int pos = 0;
                int Left = 1;
                int Right = len;
                while (Left <= Right) {
                    int mid = (Left + Right) / 2;
                    
                    // Find the smaller one, as far back as possible.
                    if (Length[mid] < nums[i]) {
                        pos = mid;
                        Left = mid + 1;
                    }
                    else
                        Right = mid - 1;
                }
                // Length[pos] < nums[i], Length[pos + 1] is the one to change.
                Length[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
