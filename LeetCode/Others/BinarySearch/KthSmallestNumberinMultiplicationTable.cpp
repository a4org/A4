/*
 * LeetCode 668 Kth Smallest Number in Multiplication Table
 * Hard
 * Shuo Feng
 * 2021.11.16
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Binary Search
 */

class Solution {
private:
    // Count the quantity of number smaller than mid.
    int count (int m, int n, int k, int mid) {
        int res = 0;
        for(int i = 1; i<= m; ++i) {
            res += min(mid / i, n);
        }
        return res < k;
    }
    
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        int res = 0;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
        
            // Line 24: res <  k -> search mid`s right.
            if(count(m, n, k, mid))
                left = mid + 1;
            
            // Line 24: res >  k -> search mid`s left.
            //          res == k -> record mid.
            else {
                right = mid - 1;
                res = mid;
            }
        }
        return res;
    }
}; 
