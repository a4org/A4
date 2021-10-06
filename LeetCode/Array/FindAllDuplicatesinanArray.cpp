/*
 * LeetCode 442 Find All Duplicates in an Array
 * Medium
 * Shuo Feng
 * 2021.10.7
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution1:
 *   Some key points:
 *    ▼ 1 <= nums[i] <= size.
 *    ▼ Each element in nums appears once or twice.
 *
 *   See all number in 'nums' as different place, each time check a place, take the opposite of it`s number,
 *  if we reach a negative value, this place has been visited, record the place in result.
 *   
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector <int> res;

        for (int i = 0; i < size; ++i) {
            int place = nums[i];
            // The place is positive value
            place = place > 0 ? place : place * (-1);

            if (nums[place - 1] > 0)
                nums[place - 1] *= -1;
          
            // Visited the second times.
            else res.push_back(place);
        }
        return res;
    }
};
