/*
 * LeetCode 239 Sliding window Maximum
 * Hard
 * Shuo Feng
 * 2021.9.21
 */

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*
 * Solution 1: Double Ended queue (Deque)
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> out_come;
        deque<int> place;  // Refer to the place in array.

        for (int i = 0; i < size; ++i) {
            // Remove the first place in queue when it is not in window.
            while (!place.empty() && place.front() <= i - k) {
                place.pop_front();
            }

            // Compare i(next place) with the last place in queue, if nums[i] is larger, remove the last one in queue.
            // Make sure that each place in queue are sorted from large to small according to their value.
            while (!place.empty() && nums[i] > nums[place.back()]) {
                place.pop_back();
            }
          
            // Push next element into queue.
            place.push_back(i);
            // The first place has the biggest value.
            if (i >= k - 1) out_come.push_back(nums[place.front()]);

        }
        return out_come;
    }
};

/*
 * Solution 2: Max heap (priority queue)
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> out_come;
        // Max heap.
        priority_queue < pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> queue;

        // First 'k' elements.
        // About queue:  queue.first--> value,  queue.second--> their place.
        for (int i = 0; i < k; ++i) {
            queue.emplace(nums[i], i);
        }
        // Storage the biggest value of the first window.
        out_come.push_back(queue.top().first);

        for (int i = k; i < size; ++i) {
            // Move the window.
            queue.emplace(nums[i], i);
            // Remove elements those are not in the window. Similar to line 26
            while (queue.top().second <= i - k)
                queue.pop();

            out_come.push_back(queue.top().first);
        }
        return out_come;
    }
};
