/*
 * LeetCode.739 Daily Temperature
 * Medium
 * Shuo Feng
 * 2021.11.13
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

/*
 * Solution: Monotonic Stack
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();

        stack<int> S;
        vector<int> ans(days, 0);  // Answer
        for (int i = 0; i < days; ++i) {
          
            // Keep the top of stack is minimum.
            while (!S.empty() && temperatures[i] > temperatures[S.top()]) {
              // 'temperatures[i]' is the first one greater.
              ans[S.top()] = i - S.top();  // Distance.
                S.pop();
            }
            // Push an element when stack is empty or in stack there is no element smaller than it.
            S.push(i);
        }
        return ans;
    }
};
