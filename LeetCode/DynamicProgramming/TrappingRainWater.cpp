/*
 * LeetCode 42 Trapping Rain Water
 * Hard
 * Shuo Feng
 * 2021.8.22
 * Last edited at 2021.9.21
 */

/*
 * Solution :Dp.
 *   For place " i ", find the biggest height in it`s left and right sides, get the shortest one between them (line 38)
 *  if the shortest one higher than the height in place " i " ,the water that can be trapped in this place is ' shorest- height[i] ' (line 39),
 *  another case: if the shortest one is higher, no water can be trapped.
 *
 *   About the the starting place when searching max height (line 30, 33)
 *   height[] start with place " 0 " and end in place " size- 1 ", for one of them, point on it`s left or right is inexistence,
 *  do not need to consider.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int size = height.size();
        vector<int> height_L(size, 0);  // The biggest height to the left  of place " i ".
        vector<int> height_R(size, 0);  // The biggest height to the right of place " i ".

        for (int i = 1; i <= size - 1; ++i) 
            height_L[i] = max(height_L[i - 1], height[i - 1]);  // Start from place " 1 ".
        
        for (int j = size - 2; j >= 0; --j) 
            height_R[j] = max(height_R[j + 1], height[j + 1]);  // Start from place " size- 2 " .
        

        for (int i = 1; i < size - 1; ++i) {
            int shortest = min(height_L[i], height_R[i]); // The most water that can be trapped in place i.
            if (shortest > height[i]) {
                sum += shortest - height[i];
            }
        }
        return sum;
    }
};
