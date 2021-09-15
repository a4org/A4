/*
 * LeetCode 279 Prefect Squares
 * Medium
 * Shuo Feng 
 * 2021.8.16
 * Last edited at 2021.9.15
 */

/*
 * Solution 1: Bfs.
 *   Begin with 0, in each cycles, add the numbers which`s inconformity to the queue.
 *   When the number is consistent with n ,return the result.
 *   For example:  
 *  n = 8:     0
 *            /  \
 *           1     4      
 *          /  \  /  \
           1   4  1   4 ←─ The first number that can form " n " with number before, there is the min_nums: 2
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int min_nums = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int size = q.size();
            min_nums += 1;
            
            for(int i = 0; i< size; ++i){
                int m = q.front();
                q.pop();
                
                // Storage all values that smaller than n,
                for(int j = 0; (j* j)+ m <= n; ++j){
                    int num =(j* j)+ m;
                    if(num == n) return min_nums;
                    else if(num < n) q.push(num);
                    else break;
                }
            }
        }
        return min_nums;
    }
};



/*
 * Solution 2: Dp.
 * The better way.
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //vector<int> nums (n+ 1);
    int numSquares(int n) {
        vector<int> nums(n + 1); // Storage the least number to form " n "
        
        for (int i = 1; i <= n; ++i) {
            int Min = INT_MAX;
            for (int j = 1; j * j <= i; ++j)
                Min = min(Min, nums[i - (j * j)] + 1);
            
            nums[i] = Min;
        }
        return nums[n];
    }
}; 
