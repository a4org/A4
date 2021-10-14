/*
 * LeetCode 279 Prefect Squares
 * Medium
 * Shuo Feng 
 * 2021.8.16
 * Last edited at 2021.9.15 / 2021.10.14
 */

/*
 * Solution 1: Bfs.
 *   Begin with 0, in each cycles, add the numbers which`s inconformity with n to the queue.
 *   When the number is consistent with n ,return the result.
 *
 *   For example:  
 *  n = 8:     0
 *            /  \    \
 *           1     4    9 (Exclude: "0 + 9" bigger than n).   
 *          /  \  /  \
 *         1   4  1   4 ←─ The first number that can form " n " with numbers before, there is the least number: 2
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
               
        // Start with 0.
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
                    else q.push(num);
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
