/*
 * LeetCode 215 Kth Largest Element in a Array
 * Medium
 * Shuo Feng
 * 2021.9.19
 */

/*
 * Solution: Heapsort.
 *   Creat a max heap, and the element in the top is the biggest one. 
 *   Delete the top and replace it as the minimum element, build the heap again, in the top is the second largest element, 
 *  repeat this procedure we can get the Kth largest one.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void maxHeap(vector<int>& nums, int i, int Heap_size) {
        
        // The  element in place 'i * 2 + 1' correspond the left  child node of node i
        // Also element in place 'i * 2 + 2' correspond the right child node of node i
        int left  = i * 2 + 1;
        int right = i * 2 + 2;
        int larger = i;
      
        // Select the larger one from child node if it`s bigger than parent, and repalce.
        if (left < Heap_size && nums[left] > nums[larger])
            larger = left;
        if (right < Heap_size && nums[right] > nums[larger])
            larger = right;

        if (larger != i) {
            swap(nums[i], nums[larger]);
            // After the change update nodes behind the changed Node.
            maxHeap(nums, larger, Heap_size);
        }
    }
    
    // Begin with the second last row, a node with child node (half the array, size / 2 - 1).
    // To ensure that the value of child node is smaller than it`s parent node, build max heap forward.
    void buildHeap(vector<int>& nums, int size, int k) {
        for (int i = size / 2 - 1; i >= 0; --i) {
            maxHeap(nums, i, size);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        buildHeap(nums, size, k);
        
        // Delete the largest one and repeat build the heap.
        for (int i = nums.size() - 1; i > nums.size() - k; --i) {
            swap(nums[0], nums[i]);
            --size;
            // Rebuild.
            maxHeap(nums, 0, size);
        }
        // Return the top element
        return nums[0];
    }
};
