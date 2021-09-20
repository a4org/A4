/*
 * LeetCode 347 Top K Frequent Element
 * Medium
 * Shuo Feng
 * 2021.9.20
 */

#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<utility>
using namespace std;

/*
 * Solution : Min Heap
 *   
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> out_come;
        unordered_map<int, int> counter;
        // Use priority queue to accomplish a min heap
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_Heap;

        // Storage all element in map and count their frequency.
        // About map, the first is element, the second is their frequency.
        for (auto i : nums)
            ++counter[i];

        // Put all values in 'counter' to the min heap.
        // Priority_queue compare the first element before the second one, so put each frequency in the first place.
        for (auto pair : counter)
            min_Heap.emplace(pair.second, pair.first);
        
        // Element in min heap is sorted from small to large, so elements in last K place are the top K frequent element.
        while (min_Heap.size() > k)
            min_Heap.pop();

        while (!min_Heap.empty()) {
            out_come.push_back(min_Heap.top().second);
            min_Heap.pop();
        }
        return out_come;
    }
};
