/*
 * LeetCode 486 Predict The Winner
 * Medium 
 * Shuo Feng
 * 2021.9.26
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Dp
 */

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
      
        // When size is even, player1(one) is the winner:
        //   Player1 can always selects the solution to win.
        //   If size is even, player1 just need chooses the bigger one between sum of even places and odd places,
        //  because when player1 keep on choosing even places or odd places, player2 can never reach the another one.
        if (size == 1 || !(size % 2)) return true;

        // ★ dp[i][j] is the maximum score player lead another player after judge in nums[i] ~ nums[j].
        vector<vector<int>> dp(size, vector<int>(size));
      
        // Lead nums[i].
        for (int i = 0; i < size; ++i) {
            dp[i][i] = nums[i];
        }

        for (int i = size - 2; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                // ★Explain about line 42: 
                //   In place [i ~ j], playerX can choose place[i] or place[j].
                //   If playerX choose [i], playerY can choose from place[i + 1, j], playerX lead score: nums[i] - dp[i + 1][j].
                //   If playerX choose [j], playerY can choose from place[i, j - 1], playerX lead score: nums[j] - dp[i][j - 1].( score playerX get - score PlayerY can get).
                //   Both two players are think about how to get the maximum score. 
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        // Player1(one) is the first to select, so player1 lead player2 'dp[0][size - 1]'.
        if (dp[0][size - 1] >= 0) return true;
        else return false;
    }
};
