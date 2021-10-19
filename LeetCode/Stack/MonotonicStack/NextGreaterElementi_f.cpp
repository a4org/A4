/*
 * LeetCode 496 Next Greater Element i
 * Easy
 * Shuo Feng
 * 2021.10.19
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

/*
 * Solution 1: Violent
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        vector<int> res;

        // Record their place for each element in nums2.
        unordered_map<int, int> map;
        for (int i = 0; i < size_2; ++i) {
            map[nums2[i]] = i;
        }

        for (int i = 0; i < size_1; ++i) {
            int target = nums1[i];
            int place = map.at(target);
            
            if (place == size_2 - 1) 
                res.push_back(-1);

            for (int j = place + 1; j < size_2; ++j) {
                if (nums2[j] > target) {
                    res.push_back(nums2[j]);
                    break;
                }
                // If reach the last element -> no elements after
                else if (j == size_2 - 1) 
                    res.push_back(-1);
            }
        }
        return res;
    }
};


/*
 * Solution 2: Stack
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        vector<int> res; // Result.

        // Second one is the next greater element of first.
        unordered_map<int, int> map;
        stack<int> Stack;

        // Find the next greater element.
        for (int i = 0; i < size_2; ++i) {
          
            // Find greater one -> storage those two elements in map.
            // Remove recorded element in stack.
            while (!Stack.empty() && nums2[i] > Stack.top()) {
                map[Stack.top()] = nums2[i];
                Stack.pop();
            }
            Stack.push(nums2[i]);
        }

        for (int i = 0; i < size_1; ++i) {
            if (map.find(nums1[i]) == map.end())
                res.push_back(-1);
            else
                res.push_back(map.at(nums1[i]));
        }
        return res;
    }
};
