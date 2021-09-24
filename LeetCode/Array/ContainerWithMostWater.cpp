/*
 * LeetCode 11 Container With Most Water
 * Medium
 * Shuo Feng
 * 2021.9.24
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: double pointers
 *  %Out of time frame.
 */
 
 class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int theMostWater = INT_MIN;

        for (int Left = 0; Left < size; ++Left) {
            int Left_height = height[Left];

            for (int Right = Left + 1; Right < size; ++Right) {
                int Right_height = height[Right];
                int min_height = min(Left_height, Right_height); 

                theMostWater = max(theMostWater, min_height * (Right - Left));
            }
        }
        return theMostWater;
    }
};

 /*
  * Optimization:
  *   It`s easier to find the biggest container by longer length, so begin with the longest length, each time reduce the length.
  *   Choose the shorter one between left and right as the height of container.
  *   When check next containter, retain the higher side, change the short side(left boundary move right, right boundary move left).
  */

 class Solution {
 public:
     int maxArea(vector<int>& height) {
         int size = height.size();
         int Left = 0;
         int Right = size - 1;
         int theMostWater = INT_MIN; // The most water that can be saved in container.

         while (Left < Right) {
             int Left_height  = height[Left];
             int Right_height = height[Right];
             int min_height = min(Left_height, Right_height);
             int length = Right - Left;

             // Update
             theMostWater = max(theMaxSize, length * min_height);
             
             // Move boundary.
             if (Left_height < Right_height)
                 Left += 1;
             else
                 Right -= 1;
         }
         return theMostWater;
     }
 };
